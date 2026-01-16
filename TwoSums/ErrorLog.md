# 📂 1. Two Sum

- **Difficulty:** Easy
- **Tags:** Array, Hash Table
- **Link:** [LeetCode Problem Link](https://leetcode.com/problems/two-sum/)

---

## 💡 Solution Approach

We optimize the brute force approach (O(n^2)) by using a **Hash Map** (Space-Time Tradeoff).
As we iterate through the array, we check if the `complement` ($target - current\_value$) already exists in our map.
* If it exists: We found the pair.
* If not: We store the current value and its index to be found by a future element.
## 📊 Complexity Analysis

- **Time Complexity:** $O(n)$
  - We traverse the list containing $n$ elements exactly once. Each lookup in the table costs only $O(1)$ on average.
- **Space Complexity:** $O(n)$
  - The extra space required depends on the number of items stored in the hash table, which stores at most $n$ elements.

---

## 🐛 Debugging & Error Log (Post-Mortem)

| Error Type | Issue Description | Root Cause | Fix / Learning |
| :--- | :--- | :--- | :--- |
| **Boundary Check Failure** | Loop iteration exceeded array bounds (Index out of range). | **Off-by-one error:** I used `i <= size` instead of strict inequality `i < size`. | Always verify loop termination conditions against 0-based indexing limits. |
| **Type Mismatch / Syntax** | Confusion using `.find()` return value. | I forgot that `.find()` returns an **iterator** (pointer), not the value directly. | To access data from an iterator, use the arrow operator: `it->first` (Key) and `it->second` (Value). |

---

## 🧠 Technical Deep Dive: Hash Map Internals

### 1. `std::map` vs. `std::unordered_map`
The fundamental difference lies in the **underlying data structure**:

* **`std::map` (Ordered):**
    * **Mechanism:** Implemented using a **Red-Black Tree** (Self-balancing Binary Search Tree).
    * **Performance:** Search/Insert operations are $O(\log n)$.
    * **Use Case:** When the order of keys matters.
* **`std::unordered_map` (Hash Table):**
    * **Mechanism:** Uses Hashing and Buckets.
    * **Performance:** Average Search/Insert operations are $O(1)$.
    * **Use Case:** High-performance lookups where order is irrelevant (like this problem).

### 2. How `unordered_map` calculates position (Under the Hood)
When we insert or search for a key (e.g., "apple"), the system follows these steps to find the memory address:

1.  **Hash Function:**
    * Apply a hash function to the key to generate a large integer (Hash Code).
    * *Example:* `hash("apple")` $\to$ `3849572938475`
2.  **Modulo Operation:**
    * Compress the hash code to fit the current array (bucket) size.
    * *Formula:* `bucket_index = hash_code % number_of_buckets`
    * *Example:* `3849572938475 % 16` $\to$ **Bucket 11**.
3.  **Storage / Retrieval:**
    * Use this bucket index to directly access the position where the Key-Value pair is stored.
    * *Note:* If multiple keys map to the same bucket (**Collision**), they are usually stored in a linked list at that index.
