#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(n*log(n))
// Space complexity :- O(1)

// Approach :-  
// For every number we find the number that is (low - curr_num) && (high - curr_num)
// all the number lying between these range will be valid b/w these 
// we'll use find the index of both number inorder to calculate the valid number for current number
// sort the array and apply lower and upper bound to find the index repectively on right side of element


// links :- https://leetcode.com/problems/count-the-number-of-fair-pairs/

class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        long long ans = 0;

        for(int i=0; i<n; ++i){
            int lb = lower_bound(nums.begin()+i+1, nums.end(), lower-nums[i]) - nums.begin();
            int ub = upper_bound(nums.begin()+i+1, nums.end(), upper-nums[i]) - nums.begin();
            ans += (ub - lb);
        }
        return ans;
    }
};