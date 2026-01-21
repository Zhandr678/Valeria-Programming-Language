
std::optional<Expression> Parser::ParseExpression(TokenLabel flag1, TokenLabel flag2)
{
	Token next_token = GetNextPeeked();
	bool is_unary = false;

	if (next_token.label == TokenLabel::SYM_NOT)
	{
		is_unary = true;
		ResetLookAhead();
		auto unary_expr = ParseExpression(flag1, flag2);

		if (not unary_expr.has_value())
		{
			throw ParserException("Expected Expression After ![here]", GetFileName(), ExprCallStmt, GetLine()); // no expression
		}

		return Expression(UnaryExpr, *unary_expr, next_token.attr);
	}
	std::vector <Expression> single_exprs;
	std::vector <Token> operators;
	if (next_token.label == TokenLabel::SYM_MINUS)
	{
		is_unary = true;
		next_token = GetNextPeeked();
		if (next_token.label == TokenLabel::LIT_NUMBER)
		{
			single_exprs.emplace_back(DoubleLiteralExpr, -1 * std::stod(next_token.attr));
		}
		else if (next_token.label == TokenLabel::LIT_INTEGER)
		{
			single_exprs.emplace_back(IntLiteralExpr, -1 * std::stoi(next_token.attr));
		}
		else if (next_token.label == TokenLabel::IDENTIFIER)
		{
			Token name_token = std::move(next_token);
			next_token = GetNextPeeked();
			if (next_token.label == TokenLabel::SYM_LPAR)
			{
				next_token = GetNextPeeked();
				std::vector <Expression> args;
				while (next_token.label != TokenLabel::SYM_RPAR)
				{
					next--;
					auto expr = ParseExpression(TokenLabel::SYM_COMMA, TokenLabel::SYM_RPAR);
					if (not expr.has_value())
					{
						throw ParserException("Expected Expression in Function Body After '('", GetFileName(), ExprCallStmt, GetLine());
					}
					args.push_back(*expr);

					next_token = GetNextPeeked();
					if (next_token.label == TokenLabel::SYM_COMMA)
					{
						next_token = GetNextPeeked();
						continue;
					}
					else if (next_token.label == TokenLabel::SYM_RPAR)
					{
						//next--;
						break;
					}
					else {
						throw ParserException("Expected Closing ')'", GetFileName(), ExprCallStmt, GetLine());
					}
				}

				if (GetNextPeeked().label == TokenLabel::SYM_DOT)
				{
					auto expr_after_dot = ParseExpression(flag1, flag2);

					if (not expr_after_dot.has_value())
					{
						throw;
					}

					single_exprs.emplace_back(UnaryExpr, Expression(FieldCallExpr, Expression(FnCallExpr, args.begin(), args.end(), name_token.attr), *expr_after_dot), "-");
				}
				else {
					next--;
					single_exprs.emplace_back(UnaryExpr, Expression(FnCallExpr, args.begin(), args.end(), name_token.attr), "-");
				}
			}
			else if (next_token.label == TokenLabel::SYM_DOT)
			{
				single_exprs.emplace_back(UnaryExpr, Expression(FieldCallExpr, Expression(VarNameExpr, name_token.attr), ParseFieldCall()), "-");
			}
			else if (next_token.label == flag1 || next_token.label == flag2)
			{
				next--;
				single_exprs.emplace_back(UnaryExpr, Expression(VarNameExpr, name_token.attr), "-");
			}
			else {
				throw ParserException("Expected ';'", GetFileName(), ExprCallStmt, GetLine());
			}
		}
		else if (next_token.label == TokenLabel::SYM_LPAR)
		{
			auto par_expr = ParseExpression(_Dupl(TokenLabel::SYM_RPAR));
			if (not par_expr.has_value())
			{
				throw ParserException("Expected Expression After '('", GetFileName(), ExprCallStmt, GetLine());
			}
			if (GetNextPeeked().label != TokenLabel::SYM_RPAR)
			{
				throw ParserException("Expected Closing ')'", GetFileName(), ExprCallStmt, GetLine());
			}
			single_exprs.emplace_back(UnaryExpr, *par_expr, "-");
		}
		else if (next_token.label == TokenLabel::SYM_LBRACKET)
		{
			auto index_expr =
		}
		else {
			throw ParserException("Invalid Expression After MINUS symbol", GetFileName(), ExprCallStmt, GetLine());
		}
	}

	if (is_unary)
	{
		next_token = GetNextPeeked();

		if (IsBinaryOperator(next_token.label))
		{
			operators.push_back(next_token);
			next_token = GetNextPeeked();
		}

		else if (next_token.label == flag1 || next_token.label == flag2)
		{
			next--;
			return single_exprs.back();
		}
	}

	while (next_token.label != flag1 && next_token.label != flag2)
	{
		if (next_token.label == TokenLabel::SYM_LPAR)
		{
			auto par_expr = ParseExpression(_Dupl(TokenLabel::SYM_RPAR));

			if (not par_expr.has_value())
			{
				throw ParserException("Expected Expression ([here])!", GetFileName(), ExprCallStmt, GetLine()); // no expr in ()
			}

			if (GetNextPeeked().label != TokenLabel::SYM_RPAR)
			{
				throw ParserException("Expected Closing ')'", GetFileName(), ExprCallStmt, GetLine()); // expected closing ')'
			}

			single_exprs.push_back(*par_expr);

			next_token = GetNextPeeked();

			if (next_token.label == flag1 || next_token.label == flag2)
			{
				next--;
				break;
			}
			else if (IsBinaryOperator(next_token.label))
			{
				operators.push_back(next_token);
				next_token = GetNextPeeked();
				continue;
			}
			else { throw ParserException("Expression MUST NOT Follow Expression", GetFileName(), ExprCallStmt, GetLine()); } // expression followed by expression
		}

		else if (next_token.label == TokenLabel::SYM_LBRACE)
		{
			std::vector<Expression> array_exprs;
			Token next_token = GetNextPeeked();

			while (next_token.label != TokenLabel::SYM_RBRACE)
			{
				next--;
				auto expr = ParseExpression(TokenLabel::SYM_COMMA, TokenLabel::SYM_RBRACE);

				if (not expr.has_value())
				{
					throw;
				}

				array_exprs.push_back(*expr);

				next_token = GetNextPeeked();
				if (next_token.label == TokenLabel::SYM_COMMA)
				{
					next_token = GetNextPeeked();
					continue;
				}
				else if (next_token.label == TokenLabel::SYM_RBRACE)
				{
					break;
				}
				else {
					throw;
				}
			}

			single_exprs.emplace_back(InitListExpr, array_exprs.begin(), array_exprs.end());
			next_token = GetNextPeeked();

			if (next_token.label == flag1 || next_token.label == flag2)
			{
				next--;
				break;
			}
			else if (IsBinaryOperator(next_token.label))
			{
				operators.push_back(next_token);
				next_token = GetNextPeeked();
				continue;
			}
			else { throw ParserException("Expression MUST NOT Follow Expression", GetFileName(), ExprCallStmt, GetLine()); }
		}

		else if (next_token.label == TokenLabel::LIT_TRUE || next_token.label == TokenLabel::LIT_FALSE)
		{
			single_exprs.emplace_back(BoolLiteralExpr, next_token.label == TokenLabel::LIT_TRUE);

			next_token = GetNextPeeked();

			if (next_token.label == flag1 || next_token.label == flag2)
			{
				next--;
				break;
			}
			else if (IsBinaryOperator(next_token.label))
			{
				operators.push_back(next_token);
				next_token = GetNextPeeked();
				continue;
			}
			else { throw ParserException("Expression MUST NOT Follow Expression", GetFileName(), ExprCallStmt, GetLine()); } // expression followed by expression
		}

		else if (next_token.label == TokenLabel::LIT_INTEGER)
		{
			single_exprs.emplace_back(IntLiteralExpr, std::stoi(next_token.attr));

			next_token = GetNextPeeked();

			if (next_token.label == flag1 || next_token.label == flag2)
			{
				next--;
				break;
			}
			else if (IsBinaryOperator(next_token.label))
			{
				operators.push_back(next_token);
				next_token = GetNextPeeked();
				continue;
			}
			else { throw ParserException("Expression MUST NOT Follow Expression", GetFileName(), ExprCallStmt, GetLine());; } // expression followed by expression
		}

		else if (next_token.label == TokenLabel::LIT_NUMBER)
		{
			single_exprs.emplace_back(DoubleLiteralExpr, std::stod(next_token.attr));

			next_token = GetNextPeeked();

			if (next_token.label == flag1 || next_token.label == flag2)
			{
				next--;
				break;
			}
			else if (IsBinaryOperator(next_token.label))
			{
				operators.push_back(next_token);
				next_token = GetNextPeeked();
				continue;
			}
			else { throw ParserException("Expression MUST NOT Follow Expression", GetFileName(), ExprCallStmt, GetLine());; } // expression followed by expression
		}

		else if (next_token.label == TokenLabel::LIT_STRING)
		{
			single_exprs.emplace_back(StringLiteralExpr, next_token.attr);

			next_token = GetNextPeeked();

			if (next_token.label == flag1 || next_token.label == flag2)
			{
				next--;
				break;
			}
			else if (IsBinaryOperator(next_token.label))
			{
				operators.push_back(next_token);
				next_token = GetNextPeeked();
				continue;
			}
			else { throw ParserException("Expression MUST NOT Follow Expression", GetFileName(), ExprCallStmt, GetLine());; } // expression followed by expression
		}

		else if (next_token.label == TokenLabel::LIT_CHAR)
		{
			single_exprs.emplace_back(CharLiteralExpr, next_token.attr[1]);

			next_token = GetNextPeeked();

			if (next_token.label == flag1 || next_token.label == flag2)
			{
				next--;
				break;
			}
			else if (IsBinaryOperator(next_token.label))
			{
				operators.push_back(next_token);
				next_token = GetNextPeeked();
				continue;
			}
			else { throw ParserException("Expression MUST NOT Follow Expression", GetFileName(), ExprCallStmt, GetLine());; } // expression followed by expression
		}

		else if (next_token.label == TokenLabel::IDENTIFIER)
		{
			Token name_token = std::move(next_token);
			next_token = GetNextPeeked();

			if (IsBinaryOperator(next_token.label))
			{
				single_exprs.emplace_back(VarNameExpr, name_token.attr);
				operators.push_back(next_token);
				next_token = GetNextPeeked();
			}
			else if (next_token.label == TokenLabel::SYM_LBRACE)
			{
				next_token = GetNextPeeked();
				std::vector <Expression> struct_inits;
				while (next_token.label != TokenLabel::SYM_RBRACE)
				{
					next--;
					auto expr = ParseExpression(TokenLabel::SYM_COMMA, TokenLabel::SYM_RBRACE);
					if (not expr.has_value())
					{
						throw ParserException("Expected Expression in Struct Initialization", GetFileName(), ExprCallStmt, GetLine());;
					}
					struct_inits.push_back(*expr);

					next_token = GetNextPeeked();
					if (next_token.label == TokenLabel::SYM_COMMA)
					{
						next_token = GetNextPeeked();
						continue;
					}
					else if (next_token.label == TokenLabel::SYM_RBRACE)
					{
						break;
					}
					else {
						throw ParserException("Expected Closing '}'", GetFileName(), ExprCallStmt, GetLine());;
					}
				}
				single_exprs.emplace_back(StructInitExpr, struct_inits.begin(), struct_inits.end(), name_token.attr);

				next_token = GetNextPeeked();

				if (next_token.label == flag1 || next_token.label == flag2)
				{
					next--;
					break;
				}
				else if (IsBinaryOperator(next_token.label))
				{
					operators.push_back(next_token);
					next_token = GetNextPeeked();
					continue;
				}
				else { throw ParserException("Expression MUST NOT Follow Expression", GetFileName(), ExprCallStmt, GetLine());; } // expression followed by expression
			}
			else if (next_token.label == TokenLabel::SYM_LPAR)
			{
				next_token = GetNextPeeked();
				std::vector <Expression> args;
				while (next_token.label != TokenLabel::SYM_RPAR)
				{
					next--;
					auto expr = ParseExpression(TokenLabel::SYM_COMMA, TokenLabel::SYM_RPAR);
					if (not expr.has_value())
					{
						throw ParserException("Expected Expression in Function Args", GetFileName(), ExprCallStmt, GetLine());;
					}
					args.push_back(*expr);

					next_token = GetNextPeeked();
					if (next_token.label == TokenLabel::SYM_COMMA)
					{
						next_token = GetNextPeeked();
						continue;
					}
					else if (next_token.label == TokenLabel::SYM_RPAR)
					{
						break;
					}
					else {
						throw ParserException("Expected Closing ')'", GetFileName(), ExprCallStmt, GetLine());;
					}
				}

				if (GetNextPeeked().label == TokenLabel::SYM_DOT)
				{
					single_exprs.emplace_back(FieldCallExpr, Expression(FnCallExpr, args.begin(), args.end(), name_token.attr), ParseFieldCall());
				}
				else {
					single_exprs.emplace_back(FnCallExpr, args.begin(), args.end(), name_token.attr);
				}

				next_token = GetNextPeeked();

				if (next_token.label == flag1 || next_token.label == flag2)
				{
					next--;
					break;
				}
				else if (IsBinaryOperator(next_token.label))
				{
					operators.push_back(next_token);
					next_token = GetNextPeeked();
					continue;
				}
				else { throw ParserException("Expression MUST NOT Follow Expression", GetFileName(), ExprCallStmt, GetLine());; } // expression followed by expression
			}
			else if (next_token.label == flag1 || next_token.label == flag2)
			{
				single_exprs.emplace_back(VarNameExpr, name_token.attr);
				next--;
				break;
			}
			else if (next_token.label == TokenLabel::SYM_DOT)
			{
				single_exprs.emplace_back(FieldCallExpr, Expression(VarNameExpr, name_token.attr), ParseFieldCall());

				next_token = GetNextPeeked();

				if (next_token.label == flag1 || next_token.label == flag2)
				{
					next--;
					break;
				}
				else if (IsBinaryOperator(next_token.label))
				{
					operators.push_back(next_token);
					next_token = GetNextPeeked();
					continue;
				}
				else {
					throw ParserException("Expression MUST NOT Follow Expression", GetFileName(), ExprCallStmt, GetLine());
				} // expression followed by expression
			}
			else {
				throw ParserException("Invalid Symbol After Identifier", GetFileName(), ExprCallStmt, GetLine());;
			}
		}

		else {
			throw ParserException("Unknown Expression Type", GetFileName(), ExprCallStmt, GetLine());;
		}
	}

	if (single_exprs.empty()) { return std::nullopt; }

	/*for (size_t i = 0; i < operators.size(); i++)
	{
		std::cout << single_exprs[i].sel() << " " << operators[i] << " ";
	}
	std::cout << (single_exprs.end() - 1)->sel();*/

	return GenerateExpression(single_exprs, operators, 0, operators.size());
}