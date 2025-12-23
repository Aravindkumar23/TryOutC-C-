# C++ Debugging — Practical Summary

This document summarizes **how debugging works in C++**, the **compiler flags involved**, and **best practices used in real projects**.

---

## What Debugging Means in C++

Debugging is the ability to:

* Inspect variables
* Step through code line by line
* See stack traces
* Understand program state at runtime

To enable this, the compiler must **preserve information** that it normally throws away.

---

## The `-g` Flag (Debug Symbols)

```bash
g++ -g main.cpp -o app
```

### What it does

* Embeds **debug symbols** into the binary
* Allows debuggers (gdb, lldb, VS Code) to:

  * see variable names
  * map machine code back to source lines
  * show call stacks

### Important facts

* `-g` does **not** change program behavior
* It only increases binary size
* Debug symbols can be stripped later

---

## Why Optimization Affects Debugging

Optimizations can:

* remove variables
* inline functions
* reorder instructions
* eliminate entire code paths

This causes:

* breakpoints to jump
* variables to appear as "optimized out"
* confusing stack traces

So debugging quality depends heavily on **optimization level**.

---

## Debug Optimization Levels

### `-O0` — No Optimization

```bash
g++ -g -O0 main.cpp -o app
```

#### Used for

* Learning C++
* Understanding pointers, references, lifetimes
* Early-stage debugging

#### Characteristics

* Exact source-to-binary mapping
* Very slow execution
* Most predictable behavior

---

### `-Og` — Optimize for Debugging (Recommended)

```bash
g++ -g -Og main.cpp -o app
```

#### Used for

* Daily development
* Professional debug builds
* CI debug pipelines

#### Why it’s preferred

* Keeps code debuggable
* Avoids extremely slow `-O0`
* Allows safe optimizations

> `-Og` is the **best balance** between speed and debuggability.

---

## Why Not Debug With `-O2` or `-O3`

Debugging optimized code leads to:

* missing variables
* skipped lines
* reordered execution
* misleading behavior

This is especially dangerous when learning C++ or debugging memory issues.

---

## Debug vs Release Builds (Mental Model)

| Build Type          | Flags            | Purpose                   |
| ------------------- | ---------------- | ------------------------- |
| Debug               | `-g -O0`         | Learning & teaching       |
| Debug (recommended) | `-g -Og`         | Real development          |
| Release             | `-O2`            | Production                |
| Hot-path release    | `-O3` (per file) | Performance-critical code |

---

## Production Debugging Practice

* Production binaries are often built with:

```bash
g++ -O2 -g main.cpp -o app
```

* Debug symbols are:

  * kept separately
  * stripped from shipped binaries if needed

This allows post-crash debugging without slowing the app.

---

## Golden Rules for Debugging

1. Always use `-g`
2. Prefer `-Og` over `-O0` for daily work
3. Never debug optimized code when learning
4. Optimization exposes undefined behavior
5. Debug first, optimize later

---

## One-Line Truths

* `-g` gives visibility
* `-O0` gives predictability
* `-Og` gives sanity
* `-O2/-O3` give speed, not clarity

---

## Recommended Path

* **Beginner / Learning:** `-g -O0`
* **Serious debugging:** `-g -Og`
* **Production debugging:** `-O2 -g`

---

## How to Debug (Practical Workflow)

This section explains **how debugging is actually done** once your build flags are correct.

---

### 1️⃣ Build for Debugging

Always start with a debuggable binary:

```bash
g++ -g -Og main.cpp -o app
```

Why:

* `-g` enables symbols
* `-Og` keeps code readable by the debugger

---

### 2️⃣ Run Under a Debugger (GDB)

```bash
gdb ./app
```

Common commands:

```text
break main        # set breakpoint at main
run               # start program
next              # step over
step              # step into
print x           # inspect variable
backtrace         # view call stack
quit              # exit debugger
```

---

### 3️⃣ Debug a Crash (Segfault)

If your program crashes:

```bash
gdb ./app
run
```

When it stops:

```text
backtrace
```

This shows:

* which function crashed
* call order
* exact source line

---

### 4️⃣ Inspect Variables and Memory

```text
print myVar
print &myVar
print *ptr
```

Helpful when debugging:

* pointers
* references
* dangling memory

---

### 5️⃣ Step Through Logic

Use:

* `next` for line-by-line execution
* `step` to enter functions
* `finish` to exit current function

This helps track:

* control flow
* unexpected branches
* incorrect state changes

---

### 6️⃣ Debug With VS Code (Conceptual)

When using VS Code:

* build with `-g -Og`
* use the C++ debug launcher
* set breakpoints in the editor

VS Code is just a UI on top of gdb/lldb.

---

### 7️⃣ Debug Optimized Production Builds

Production debugging often uses:

```bash
g++ -O2 -g main.cpp -o app
```

Notes:

* debugging is harder
* some variables may be optimized out
* stack traces still work

Used mainly for:

* crash analysis
* post-mortem debugging

---

### 8️⃣ Debugging Checklist

Before debugging, verify:

* compiled with `-g`
* optimization is `-Og` or lower
* no undefined behavior assumptions
* pointers are initialized

---

### Debugging Mindset

* Debug correctness first
* Optimize only after behavior is correct
* If debugging feels confusing, reduce optimization

---

*End of document.*
