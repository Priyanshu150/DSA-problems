#include<bits/stdc++.h>
using namespace std;

// Time Complexity: O(n)
// Space Complexity: O(1)

// Approach :- 
// Traverse on the left to right side of array and maintain 2 variable maxSum & sum_till_now(sum)
// whenever the sum becomes -ve reset it to 0

// Link :- https://leetcode.com/problems/maximum-subarray/

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size(), sum = 0, maxSum = INT_MIN;

        for(int i=0; i<n; ++i){
            sum += nums[i];
            maxSum = max(sum, maxSum);
            if(sum < 0)     sum = 0;
        }
        return maxSum;
    }
};