# 📂 169. Majority Element

- **Difficulty:** Easy
- **Tags:** `Hash Map`, `Counting`, `STL Algorithms`, `Lambda`
- **Link:** [LeetCode 169](https://leetcode.com/problems/majority-element/)

---

## 💡 Solution Approach

The goal is to find the element that appears more than ⌊n / 2⌋ times.

1.  **Count Frequencies:**
    - Initialize an `unordered_map<int, int>` to store numbers and their occurrences.
    - Iterate through the input vector `nums` once ($O(n)$) to populate the map.

2.  **Find the Maximum (Optimization):**
    - Instead of writing a manual `for` loop to track the maximum counter, use the STL algorithm `std::max_element`.
    - **Custom Comparator:** Since a map stores `pair<key, value>`, we use a **Lambda function** to tell `max_element` to compare the *values* (`.second` / frequency) instead of the *keys*.

3.  **Return Result:**
    - `max_element` returns an iterator pointing to the winner pair. We access `it->first` to get the actual majority number.

### 💻 Code Implementation

```cpp
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> mapa;
        
        // 1. Fill the frequency map
        for(auto num : nums){
            mapa[num]++;
        }
        
        // 2. Find the element with the highest frequency
        // Note: Arguments must be 'const pair' because map keys are immutable
        auto it = max_element(mapa.begin(), mapa.end(), 
            [](const pair<int, int>& a, const pair<int, int>& b){
                return a.second < b.second;
            }
        );
        
        // 3. Return the key (the number itself)
        return it->first;
    }
};
```

## 📊 Complexity Analysis

- **Time Complexity:** $O(n)$
  - Iterating the array to fill the map takes $O(n)$.
  - std::max_element iterates over the map once, which is roughly $O(n)$ in the worst case (unique elements).
- **Space Complexity:**  $O(n)$
  - In the worst case, the map stores up to $n$ unique elements (or $n/2$ in the context of majority element).

---
## 🐛 Debugging & Error Log (Post-Mortem)

| Error Type | Issue Description | Root Cause | Fix / Learning |
| :--- | :--- | :--- | :--- |
| **Optimization**  | Initial approach used two manual loops (one to fill, one to find max).| Unaware of STL power tools. | Replaced second loop with std::max_element + Lambda. |
| **Compilation** | no matching function for call... inside the Lambda. | Map keys are immutable. I tried to pass pair<int, int>& (modifiable) but map stores pair<const int, int>. | Changed Lambda parameters to const pair<int, int>& a. |
| **Logic** |Returned the wrong value (the count instead of the number). | Confusion between .first (Key/Number) and .second (Value/Frequency).| Always verify return type: it->first is the element, it->second is the count |
---

## 🧠 Technical Deep Dive: Hash Map Internals

### Why must the pair be `const` in the Lambda?

In a `std::unordered_map`, the internal data structure relies entirely on the **Key**.

1.  **Hashing & Buckets:** The Key determines which "bucket" (memory slot) the data goes into based on its Hash value.
2.  **Data Integrity:** If C++ allowed modification of the Key inside the map, the element's position would become invalid relative to its new hash. The element would be "lost" in the wrong bucket, effectively corrupting the map.

Therefore, the type effectively stored inside a map is **strictly**:

```cpp
std::pair<const Key, Value>


