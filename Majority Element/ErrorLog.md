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


