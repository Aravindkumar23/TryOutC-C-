# C++ Pointers & References — Practical Guide (with Debugging)

This document summarizes **pointers and references in C++**, how they work in memory, how they differ, and **how to debug issues related to them**.

---

## Core Mental Model

* A **variable** owns a value
* A **pointer** stores an address
* A **reference** is an alias to an existing variable

Think in terms of **identity (address)** vs **value**.

---

## Pointers

### What a Pointer Is

```cpp
int x = 10;
int* p = &x;
```

* `p` stores the address of `x`
* `*p` accesses the value at that address

Key properties:

* can be `nullptr`
* can be reassigned
* must be dereferenced explicitly

---

### Pointer Memory View

```text
x   -> value 10 (stack)
p   -> address of x
```

Dereferencing:

```cpp
*p = 20; // modifies x
```

---

### Common Pointer Bugs

* uninitialized pointer
* dangling pointer (pointing to freed memory)
* double delete
* dereferencing `nullptr`

These bugs often **appear only under optimization**.

---

## References

### What a Reference Is

```cpp
int x = 10;
int& r = x;
```

* `r` is another name for `x`
* no separate storage
* cannot be null
* cannot be reseated

Every operation on `r` affects `x`.

---

### Reference Memory View

```text
x, r -> same memory location
```

Compiler treats them as the same object.

---

### Reference Rules (Non‑Negotiable)

* must be initialized
* cannot be reassigned
* cannot outlive the referenced object

Violating lifetime rules leads to **undefined behavior**.

---

## Pointer vs Reference (Quick Comparison)

| Feature             | Pointer              | Reference             |
| ------------------- | -------------------- | --------------------- |
| Can be null         | Yes                  | No                    |
| Can rebind          | Yes                  | No                    |
| Syntax              | `*p`                 | `r`                   |
| Ownership semantics | Possible             | No                    |
| Common use          | Optional / ownership | Aliasing / parameters |

---

## When to Use What

### Use references when:

* parameter must exist
* you want no null checks
* passing objects efficiently

```cpp
void update(Player& p);
```

---

### Use pointers when:

* optional parameters
* dynamic lifetime
* ownership is involved

```cpp
void setTarget(Target* t);
```

---

## Debugging Pointers and References

### 1️⃣ Compile for Debugging

```bash
g++ -g -Og main.cpp -o app
```

This preserves pointer visibility and lifetimes.

---

### 2️⃣ Inspect Addresses

```text
print x
print &x
print p
print *p
```

Helps verify:

* correct address
* correct value
* valid dereference

---

### 3️⃣ Detect Dangling References

Symptoms:

* crashes far from source
* random values
* works in debug, fails in release

Cause:

* reference bound to destroyed object

---

### 4️⃣ Stack vs Heap Lifetimes

```cpp
int* foo() {
    int x = 10;
    return &x; // dangling pointer
}
```

Stack memory dies when function exits.

---

### 5️⃣ Debug Heap Issues

```cpp
int* p = new int(5);
delete p;
*p = 10; // use-after-free
```

Debugging tips:

* inspect pointer before dereference
* set pointer to `nullptr` after delete

---

## Optimization Interaction

* `-O0` hides some pointer bugs
* `-O2` exposes undefined behavior
* `-O3` amplifies mistakes

Always debug pointer code **before** optimizing.

---

## Golden Rules

1. Initialize every pointer
2. Never return references to locals
3. Prefer references for parameters
4. Prefer smart pointers for ownership
5. Debug lifetimes, not values

---

## One‑Line Truths

* Pointers express possibility
* References express certainty
* Lifetimes matter more than syntax

---

## Recommended Learning Path

* Start with raw pointers
* Understand lifetimes deeply
* Move to `unique_ptr` and `shared_ptr`
* Combine with RAII

---

*End of document.*
