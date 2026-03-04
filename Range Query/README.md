# 📌 Range Query – Segment Tree

Range Query means answering queries on a subarray `[L, R)` efficiently.
Common operations:

* Range Sum
* Range Minimum
* Range Maximum
* Range GCD
* Range AND / OR / XOR
* Range Updates

Naive solution takes **O(N)** per query.
Segment Tree improves it to:
* **Build:** O(N)
* **Query:** O(log N)
* **Update:** O(log N)

---

# Segment Tree

A Segment Tree is a binary tree where:

* Each leaf represents one element.
* Each internal node represents a merge of two children.
* Each node stores information about a range.

The tree size is extended to the nearest power of 2.

---

# ⚙️ Initial Value (Neutral Element)

When designing a Segment Tree, choosing the **correct initial value** (neutral element) is very important.

This value must NOT affect the result when merged.

| Operation      | Merge Function | Initial Value (Neutral Element)  |
| -------------- | -------------- | -------------------------------- |
| Sum            | (a + b)        | `0`                              |
| Minimum        | min(a, b)      | `+INF`                           |
| Maximum        | max(a, b)      | `-INF`                           |
| GCD            | gcd(a, b)      | `0`                              |
| XOR            | (a ^ b)        | `0`                              |
| OR             | (a | b)        | `0`                              |
| AND            | (a & b)        | `(1 << bits) - 1` (all bits = 1) |
| Multiplication | (a * b)        | `1`                              |

---

# 🧠 Code Structure Explanation

My implementation is a **generic Segment Tree template** that can be modified easily.

---

### ✔ Advantages:

* Encapsulates data inside a `Node`.
* By changing:

* Node variables
* merge()
* neutral value

You can reuse the same tree for:

* sum
* min
* max
* xor
* and
* gcd
* custom structs

---

# 📊 Time & Space Complexity

| Operation | Complexity |
| --------- | ---------- |
| Build     | O(N)       |
| Query     | O(log N)   |
| Update    | O(log N)   |
| Space     | O(2N)      |

---
