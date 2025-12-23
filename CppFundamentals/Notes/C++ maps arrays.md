# C++ Containers & Data Structures — Practical Summary

This document summarizes the **core data structures and containers** we discussed, starting from **arrays** up to **linked lists**, covering:

* basics
* why they exist
* when to use them
* time & space complexity in common scenarios

---

## 1️⃣ Raw Array (`T arr[N]`)

### Basics

```cpp
int arr[5];
```

* Built-in language feature
* Fixed size (known at compile time)
* Contiguous memory

### Why it exists

* Zero abstraction overhead
* Maximum performance
* Direct memory access

### Downsides

* No bounds checking
* Size is part of the type
* Decays to pointer in functions

### Complexity

| Operation       | Complexity     |
| --------------- | -------------- |
| Access by index | O(1)           |
| Insert/Delete   | O(n)           |
| Resize          | ❌ Not possible |

---

## 2️⃣ `std::array<T, N>`

### Basics

```cpp
std::array<int, 5> a;
```

* Fixed-size STL container
* Wraps raw array safely
* Stored contiguously

### Why it is used

* Safer than raw arrays
* Knows its own size
* Works well with algorithms

### Complexity

| Operation       | Complexity     |
| --------------- | -------------- |
| Access by index | O(1)           |
| Insert/Delete   | O(n)           |
| Resize          | ❌ Not possible |

---

## 3️⃣ `std::vector<T>`

### Basics

```cpp
std::vector<int> v;
v.push_back(10);
```

* Dynamic array
* Heap allocated
* RAII-managed

### Why it is used

* Default container in modern C++
* Dynamic size
* Cache-friendly

### Important behavior

* Reallocation may invalidate pointers/iterators

### Complexity

| Operation         | Complexity     |
| ----------------- | -------------- |
| Access by index   | O(1)           |
| Insert at end     | O(1) amortized |
| Insert in middle  | O(n)           |
| Search (unsorted) | O(n)           |

---

## 4️⃣ Ordered Associative Containers (`map`, `set`)

### Basics

```cpp
std::map<int, std::string> m;
std::set<int> s;
```

* Tree-based (Red-Black tree)
* Elements kept sorted

### Why they are used

* Automatic ordering
* Range queries
* Deterministic iteration order

### Complexity

| Operation | Complexity |
| --------- | ---------- |
| Insert    | O(log n)   |
| Lookup    | O(log n)   |
| Delete    | O(log n)   |

---

## 5️⃣ Unordered Associative Containers (`unordered_map`, `unordered_set`)

### Basics

```cpp
std::unordered_map<int, int> um;
```

* Hash-table based
* No ordering

### Why they are used

* Fast lookups
* Most real-world use cases don’t need ordering

### Caveats

* Higher memory usage
* Depends on good hash function

### Complexity

| Operation | Average | Worst |
| --------- | ------- | ----- |
| Insert    | O(1)    | O(n)  |
| Lookup    | O(1)    | O(n)  |
| Delete    | O(1)    | O(n)  |

---

## 6️⃣ Linked List (Conceptual)

### Basics

```cpp
struct Node {
    int data;
    Node* next;
};
```

* Non-contiguous nodes
* Connected via pointers

### Variants

* Singly linked list
* Doubly linked list
* Circular linked list

### Why it is used

* Fast insert/delete when node is known
* Stable memory addresses

### Downsides

* Poor cache locality
* No random access
* Pointer-heavy bugs

### Complexity

| Operation                  | Complexity |
| -------------------------- | ---------- |
| Access by index            | O(n)       |
| Insert/Delete (known node) | O(1)       |
| Search                     | O(n)       |

---

## Quick Comparison Table

| Container   | Contiguous | Resize | Random Access | Lookup   | Typical Use        |
| ----------- | ---------- | ------ | ------------- | -------- | ------------------ |
| Array       | Yes        | No     | Yes           | O(n)     | Low-level / C APIs |
| std::array  | Yes        | No     | Yes           | O(n)     | Fixed-size safety  |
| vector      | Yes        | Yes    | Yes           | O(n)     | Default choice     |
| map/set     | No         | No     | No            | O(log n) | Sorted data        |
| unordered_* | No         | No     | No            | O(1) avg | Fast lookup        |
| linked list | No         | Yes    | No            | O(n)     | Frequent inserts   |

---

## Selection Rules (Golden)

* Need fast indexed access → `vector`
* Need fixed size → `std::array`
* Need ordering → `map` / `set`
* Need fast lookup → `unordered_map`
* Need frequent inserts & stable addresses → linked list

---

## One-Line Truth

> Containers exist to trade **memory, speed, and safety** in different proportions.

---

*End of document.*
