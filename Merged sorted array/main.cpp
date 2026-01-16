// Problem: Merge Sorted Array
// Link: https://leetcode.com/problems/merge-sorted-array/description/
// Difficulty: Easy
// Tags: Array, Pointers


#include <vector>

using namespace std;
/*
* APPROACH: Iterate backwards (Two pointers)
* -----------------------------
*  Compare nums1[p1] and nums2[p2].
* Place the larger element at nums1[p] and decrement the corresponding pointers.
* * * Time Complexity: O(n+m)
* * Space Complexity: O(n+m)
* */
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int p1 = m - 1;
        int p2 = n - 1;
        int p = m + n - 1;

        // Compare and place the largest element at the end
        while (p1 >= 0 && p2 >= 0) {
            if (nums1[p1] > nums2[p2]) {
                nums1[p] = nums1[p1];
                p1--;
            } else {
                nums1[p] = nums2[p2];
                p2--;
            }
            p--;
        }

    }
};
int main() {
    Solution s;
    vector<int> nums1{1,2,4,5,6,0};
    vector<int> nums2{3};
    Solution test;
    test.merge(nums1,5,nums2,1);
    return 0;
}