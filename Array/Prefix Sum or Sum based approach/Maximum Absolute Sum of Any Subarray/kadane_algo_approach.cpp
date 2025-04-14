#include<bits/stdc++.h>
using namespace std;

//Time complexity :- O(N+N)       
//Space complexity :- O(1)    

// Approach :-
// use kadane algo to find the maximum subarray sum 
// for abs value, again use kadane algo to find the minimum subarray sum
// mulitply min subarray sum with -1 and take max of both as ans


//link :- https://leetcode.com/problems/maximum-absolute-sum-of-any-subarray/

class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int n = nums.size(), res = 0, sum = 0;

        for(int i=0; i<n; ++i){
            sum += nums[i];
            res = max(res, sum);
            if(sum < 0)
                sum = 0;
        }
        sum = 0;

        for(int i=0; i<n; ++i){
            sum += nums[i];
            res = max(res, -1*sum);
            if(sum > 0)
                sum = 0;
        }
        return res;
    }
};