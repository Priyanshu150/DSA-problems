#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(N)
// Space complexity :- O(N)

// Approach :-
// we'll use sliding window approach using two pointer for a valid sub-array
// expand the window until we got the distinct element 
// and maintain a current sum for the valid subarray and maximum sum throughout of the array
// once we get a duplicate number we start removing from the left side of window until that current number is removed 
// use hash set to maintain the distinct number 

// Link :- https://leetcode.com/problems/maximum-erasure-value/

class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int n = nums.size(), left = 0, curr_sum = 0, max_sum = 0;
        unordered_set<int> distinct_nums;

        for(int right=0; right<n; ++right){
            while(distinct_nums.count(nums[right])){
                curr_sum -= nums[left];
                distinct_nums.erase(nums[left]);
                ++left;
            }
            curr_sum += nums[right];
            distinct_nums.insert(nums[right]);
            max_sum = max(max_sum, curr_sum);
        }
        return max_sum;
    }
};