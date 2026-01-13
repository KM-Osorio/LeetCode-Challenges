// Problem: Two Sum
// Link: https://leetcode.com/problems/two-sum/
// Difficulty: Easy
// Tags: Array, Hash Table

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

/*
* APPROACH: Two-Pass Hash Table
* -----------------------------
* Uses an auxiliar structure(unordered_map) to optimize latency
* Determinate whether the addends are contained in the unordered_map
* * * Time Complexity: O(n)
* * Space Complexity: O(n)
* */

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        //Fill the unordered_map
        unordered_map <int,int>nums2;
        int k=0;
        for(auto num:nums){
            nums2[num]=k;
            k++;
        }
        for(int i=0;i<nums.size();i++){
            auto it=nums2.find(target-nums[i]);
            //if the complement is found returns the indices
            if(it!=nums2.end()&&i!=it->first)return {it->second,i};
        }
        return {};
    }
};