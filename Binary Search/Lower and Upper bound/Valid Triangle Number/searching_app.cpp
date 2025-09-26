#include<bits/stdc++.h>
using namespace std;

//Time complexity :- O(N*log(N) + N*N*log(N))
//Space complexity :- O(1) 

// Approach :-
// sum of two sides of triangle should be smaller than third side 
// using this property we'll solve this question 
// sort the array, and fix the two sides using for loop 
// and search for the third side using lower bound/bs whose value is less than sum of other two
// count all such values that will be ours answer

//link :- https://leetcode.com/problems/valid-triangle-number/

class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        int n = nums.size(), res = 0;
        sort(nums.begin(), nums.end());

        for(int i=0; i<n; ++i){
            for(int j=i+1; j<n; ++j){
                int sum = nums[i] + nums[j];
                int ind = lower_bound(nums.begin()+j+1, nums.end(), sum) - nums.begin();
                res += (ind - j - 1);
            }
        }
        return res;
    }
};
