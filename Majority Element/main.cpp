// Problem: Majority Element
// Link: https://leetcode.com/problems/majority-element/
// Difficulty: Easy
// Tags: Array, Hash Table,Sorting

#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
    unordered_map<int,int> mapa;
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int>mapa;
        for(auto num:nums){
            mapa[num]++;
        }
        auto it=max_element(mapa.begin(),mapa.end(),[](const pair<int,int>&a,const pair<int,int>&b){
            return a.second < b.second;
        });
        int major =it->first;
        return major;
    }
};
int main() {
Solution s;
    vector<int> nums = {3,2,3,1,1,1,1};
    int major=s.majorityElement(nums);
    return 0;
}