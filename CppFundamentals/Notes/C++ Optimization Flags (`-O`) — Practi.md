# C++ Optimization Flags (`-O`) — Practical Guide

This document summarizes **compiler optimization flags** (`-O*`) in GCC/Clang, how they are used in **real production**, and **when to apply each one**.

---

## What is `-O{n}`?

* `-O` is the **optimization flag family**
* `{n}` selects the **optimization level**

Example:

```bash
g++ -O2 main.cpp -o app
```

This means: *compile with optimization level 2*.

---

## Default Optimization Level

If you do **not** specify any `-O` flag:

```bash
g++ main.cpp -o app
```

The compiler uses:

```text
-O0
```

### Why?

* Predictable behavior
* Faster compile times
* Easier debugging
* No assumptions about performance intent

---

## Optimization Levels Overview

| Flag     | Name               | Purpose                           |
| -------- | ------------------ | --------------------------------- |
| `-O0`    | No optimization    | Learning & debugging              |
| `-Og`    | Debug optimization | Debugging with mild optimizations |
| `-O1`    | Optimize           | Light, safe optimizations         |
| `-O2`    | Optimize more      | **Production default**            |
| `-O3`    | Optimize most      | Hot loops & math-heavy code       |
| `-Os`    | Optimize for size  | Embedded / small binaries         |
| `-Ofast` | Fast (unsafe)      | Ignores strict standards          |

---

## `-O0` — No Optimization

```bash
g++ -g -O0 main.cpp -o app
```

### Used for:

* Learning C++
* Memory & pointer debugging
* Understanding stack vs heap

### Characteristics:

* Slow execution
* Exact source-to-binary mapping
* Variables never optimized away

---

## `-Og` — Optimize for Debugging

```bash
g++ -g -Og main.cpp -o app
```

### Used for:

* Daily development
* Professional debug builds
* CI debug pipelines

### Why it exists:

* Keeps code debuggable
* Avoids painfully slow `-O0`

---

## `-O2` — Production Standard (Most Common)

```bash
g++ -O2 main.cpp -o app
```

### Used for:

* Production binaries
* Game engines
* Backend services
* Desktop applications

### Why `-O2` is preferred:

* Large performance gains
* Stable and predictable
* Minimal risk of behavior change

> **If someone says “release build”, they usually mean `-O2`.**

---

## `-O3` — Aggressive Optimization (Selective Use)

```bash
g++ -O3 physics.cpp -o physics.o
```

### What `-O3` adds beyond `-O2`:

* Loop unrolling
* Aggressive inlining
* Auto-vectorization (SIMD)

### Used ONLY when:

* Code runs millions/billions of times
* Control flow is simple
* Code is already profiled

### Typical use cases:

* Physics solvers
* Math kernels
* Image/audio processing
* Rendering hot paths

### Not recommended for:

* Entire codebases
* Complex branching logic
* Debugging

> **Rule:** `-O3` is applied per-file, not globally.

---

## Mixing Optimization Levels (Industry Standard)

You **can** mix optimization levels safely.

### Example

```bash
g++ -O2 -c main.cpp
g++ -O2 -c engine.cpp
g++ -O3 -c physics.cpp
g++ main.o engine.o physics.o -o app
```

### Or using a library

```bash
g++ -O3 -c physics.cpp
ar rcs libphysics.a physics.o

g++ -O2 main.cpp -lphysics -o app
```

This is common in:

* Game engines
* Math libraries
* High-performance systems

---

## `-Os` — Optimize for Size

```bash
g++ -Os main.cpp -o app
```

### Used for:

* Embedded systems
* Mobile binaries
* WASM builds
* CLI tools

Smaller binaries:

* Load faster
* Fit better in instruction cache

---

## `-Ofast` — Maximum Speed (Unsafe)

```bash
g++ -Ofast main.cpp -o app
```

### What it does:

* Enables `-O3`
* Disables strict IEEE rules
* May break C++ guarantees

### Used for:

* Scientific experiments
* Research code
* Non-critical math-heavy workloads

⚠️ **Never use where correctness matters.**

---

## Real-World Build Matrix

| Build Type        | Flags            |
| ----------------- | ---------------- |
| Debug             | `-g -Og`         |
| Release           | `-O2`            |
| Release + symbols | `-O2 -g`         |
| Hot path          | `-O3` (per file) |
| Size constrained  | `-Os`            |

---

## Golden Rules

1. Start with `-O2`
2. Profile before using `-O3`
3. Never debug optimized code when learning
4. Keep debug symbols in production builds
5. Undefined behavior gets exposed faster at higher `-O`

---

## One-Line Truths

* `-O0` hides problems
* `-O2` exposes problems
* `-O3` weaponizes problems

---

## Recommended Path (Learning → Production)

* **Learning:** `-g -O0`
* **Serious debugging:** `-g -Og`
* **Production:** `-O2`
* **Hot loops only:** `-O3`

---

*End of document.*
