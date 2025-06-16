#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(n)
// Space complexity :- O(1)

// Approach :- 
// traverse in array from left to right, while doing that maintain min_element and maximum difference 
// if the current element is less than min_element update min_element 
// if the current element is greater than min_element find the difference and update the maximum difference
// otherwise skip/continue


// Link :- https://leetcode.com/problems/maximum-difference-between-increasing-elements/

class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int n = nums.size(), diff = -1, mini = INT_MAX;

        for(int i=0; i<n; ++i){
            if(mini == nums[i])
                continue;
            if(nums[i] < mini){
                mini = nums[i];
            }
            else{
                diff = max(diff, nums[i] - mini);
            }
        }
        return diff;
    }
};