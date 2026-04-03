# Valeriya Compiler

Valeriya is a statically-typed imperative programming language designed around **mutable value semantics (MVS)** and **pattern matching on algebraic data types**.

This repository contains the source code of the Valeriya compiler.

---

## Overview

Valeriya focuses on three main ideas:

* **Mutable Value Semantics (MVS)**
  Combines the safety of value semantics with the efficiency of reference semantics.

* **Property Types (Algebraic Data Types)**
  A high-level abstraction for defining structured and recursive data.

* **Pattern Matching**
  A native and expressive way to destructure and operate on data.

The language is designed to improve:

* safety (no uncontrolled mutation)
* readability
* local reasoning about code
* expressiveness for rule-based logic and structured data

---

## Key Features

### 1. Mutable Value Semantics (MVS)

All variables behave like values from the user’s perspective, but the compiler internally optimizes memory using:

* reference counting
* copy-on-write

This means:

* assignments do **not immediately copy data**
* copying happens **only when mutation occurs**

#### Example (Copy-on-Write)

```val
Data data1 = Data{ 5, "Hello", { 3.14, 2.72 }, 'x' };

// No real copy (shared internally)
Data data2 = data1;

// Triggers copy-on-write
data2.ds[0] = 314.0;
```

* `data1` remains unchanged
* `data2` gets a real copy only when modified

---

### 2. Property Types

A **property** is a custom algebraic data type (sum type) with labeled variants.

#### Example

```val
property cmd
{
    move: { double dx, dy; }
    rotate: { double angle; }
    stop: {}
}
```

This allows representing structured commands safely and explicitly.

---

### 3. Pattern Matching

Valeriya provides built-in pattern matching for property types.

#### Example

```val
match(cc)
{
    case move   -> { printf("moved: %f, %f\n", cc.dx, cc.dy); }
    case rotate -> { printf("rotated: %f\n", cc.angle); }
    case stop   -> { printf("stopped\n"); }
}
```

* Eliminates complex branching logic
* Ensures all cases are handled explicitly

---

### 4. Recursive Data Structures

Property types and structs support recursion, enabling expressive tree-like structures.

#### Example

```val
property Formula
{
    Boolval: { bool b; }
    Not: { Formula f; }
    And: { Formula l, r; }
    Or: { Formula l, r; }
}
```

Used together with pattern matching:

```val
fn eval(Formula f) -> bool
{
    match(f)
    {
        case Boolval -> { return f.b; }
        case Not     -> { return !eval(f.f); }
        case And     -> { return eval(f.l) && eval(f.r); }
        case Or      -> { return eval(f.l) || eval(f.r); }
    }
}
```

---

### 5. Function Semantics

Functions receive arguments using MVS:

* No immediate copies on function calls
* Copy occurs only if mutation happens inside the function

#### Example

```val
fn ViewStructValues(Struct s) -> void
{
    printf("%d %f %s\n", s.a, s.d, s.s);
}

fn AlterStructAndView(Struct s) -> void
{
    s.a = 777;   // triggers copy
    ViewStructValues(s);
}
```

---

## Language Design Principles

Valeriya follows these core principles:

* Deterministic behavior through value semantics
* No hidden shared mutable state
* Clear separation between reading and mutation
* Strong static typing
* Minimal and predictable compiler behavior

---

## Use Cases

Valeriya is particularly suitable for:

* rule-based systems
* symbolic computation
* interpreters and compilers
* structured data transformations
* logic and formula evaluation

---

## Future Work

Planned extensions include:

* generalized algebraic data types
* multi-dimensional arrays
* concurrency and multithreading support
* improved pattern matching capabilities 

---

## Summary

Valeriya demonstrates that:

* value semantics and performance can coexist
* pattern matching can be integrated cleanly into imperative languages
* safer and more predictable programming models are achievable without sacrificing efficiency