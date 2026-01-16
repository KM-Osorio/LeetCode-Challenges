# 📂 2. Name

- **Difficulty:** Easy
- **Tags:** Array, Two Pointers, Sorting
- **Link:** [LeetCode Problem Link](https://...)

---

## 💡 Solution Approach

The problem asks us to merge two sorted arrays (`nums1` and `nums2`) into `nums1`, which has extra space at the end.

Instead of starting from the beginning (which would require shifting elements repeatedly), we use a **Reverse Two Pointers** approach:

1.  **Pointers:** Initialize three pointers:
    -   `p1`: points to the last valid element in `nums1` ($m-1$).
    -   `p2`: points to the last element in `nums2` ($n-1$).
    -   `p`: points to the end of the total array ($m+n-1$), acting as the **write pointer**.
2.  **Comparison:** Iterate backwards. Compare `nums1[p1]` and `nums2[p2]`. Place the larger element at `nums1[p]` and decrement the corresponding pointers.
3.  **Cleanup:** If `nums2` still has elements left after `nums1` is exhausted, copy them into `nums1`. (If `nums1` has elements left, they are already in place).
---
## 📊 Complexity Analysis

- **Time Complexity:** $O(m + n)$
  - We traverse each array (nums1 and nums2) exactly once linearly to merge them.
- **Space Complexity:**  $O(1)$
  - We do not use any extra data structures; the merging happens in-place within the allocated space of nums1.

---
## 🐛 Debugging & Error Log (Post-Mortem)

| Error Type | Issue Description | Root Cause | Fix / Learning |
| :--- | :--- | :--- | :--- |
| **Logic / Indexing**  | Using nums1[m + ptr2] as the insertion index.| Conceptual Gap: Tied the "write" position to the ptr2 index. This failed because ptr2 only decrements when we pick from nums2, causing overwrites or gaps. | Decouple the reading and writing. Use a dedicated third pointer (p or i) solely for the writing position that decrements on every step. |
| **Edge Case** | Logic for m=0 or n=0 handled manually/incorrectly. | Implementation Details: Trying to force specialized if statements instead of letting the main loop handle it. | The while(p2 >= 0) loop naturally handles the case where m=0. Specialized checks aren't needed if the loop logic is robust. |
| **Completeness** | Numbers from nums2 were sometimes missing or "stuck". | Optimization Missing: The initial code didn't handle the case where nums1 is exhausted first (e.g., nums1=[7,8,9,0,0,0], nums2=[1,2,3]). | Added a cleanup while (p2 >= 0) loop to ensure all remaining elements from nums2 are copied over. |
---

## 🧠 Technical Deep Dive: Reverse Filling Pattern

When you see a problem involving sorted arrays where one array has extra buffer space at the end, and you need to merge or manipulate them in-place.Why Reverse Filling Works:Standard merging (forward) requires shifting elements to the right to make space ($O(N^2)$ behavior or extra space). By filling from the back:
1.  **Zero Collisions:** We write into the empty "buffer" zone ($0, 0, 0$) first.
3.  **Preservation:** We never overwrite a number in nums1 until we have already processed/moved it.
2.  **Stability:** It effectively mimics a merge sort merge step but utilizes the provided empty space as the target array.
