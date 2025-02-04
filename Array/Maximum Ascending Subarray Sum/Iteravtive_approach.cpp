#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(n)
// Space complexity :- O(1)

// Approach :-  
// Traverse on each element and for each ascending subarray keep track of all the maximum sum


// Link :- https://leetcode.com/problems/maximum-ascending-subarray-sum/description/

class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int n = nums.size(), sum = nums[0], res = sum;

        for(int i=1; i<n; ++i){
            if(nums[i] > nums[i-1])         sum += nums[i];
            else    sum = nums[i];

            res = max(sum, res);
        }
        return res;
    }
};