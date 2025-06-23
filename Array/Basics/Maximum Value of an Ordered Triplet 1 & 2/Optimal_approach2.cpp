#include<bits/stdc++.h>
using namespace std;

// Time complexity :- O(n)                 
// Space complexity :- O(1)                  

// Approach :-
// for find the max value of (x-y)*z, we've to maximize the value of x & z 
// moving from left to right, we'll maintain maxValue of max_diff(x-y)
// considering current element as z, (curr_ele*max_diff)
// considering current element as y, (max_ele_on_left - curr_ele)
// maintaining maximum value in the variable to calculate max value later 
// Hence, we've to maintain max_val & max_diff variable


// Links :- https://leetcode.com/problems/maximum-value-of-an-ordered-triplet-ii/

class Solution {
#define ll long long

public:
    long long maximumTripletValue(vector<int>& nums) {
        ll n = nums.size(), max_left = 0, max_diff = 0, res = 0;

        for(int i=0; i<n; ++i){
            ll val = ((ll)nums[i])*max_diff;
            res = max<ll>(res, val);
            max_diff = max<ll>(max_diff, max_left - nums[i]);
            max_left = max<ll>(max_left, nums[i]);
        }
        return res;
    }
};