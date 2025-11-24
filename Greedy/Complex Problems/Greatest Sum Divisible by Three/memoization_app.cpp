#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(n*3)
// Space complexity :- O(n*3 + n)

// Approach :-  
// using recusion we can explore all the possibilities, considering notTake and take case 
// states will be (ind, rem) and max of both the case 
// we'll use 2d dp to memoize the solution 

//Link :- https://leetcode.com/problems/greatest-sum-divisible-by-three/

class Solution {
private:
    int solve(int ind, int rem, vector<int> &nums, vector<vector<int>> &dp){
        if(ind == 0){
            return (rem % 3 == 0) ? 0 : INT_MIN;
        }
        if(dp[ind][rem] != -1)
            return dp[ind][rem];

        int notTake = solve(ind-1, rem, nums, dp);
        int take = nums[ind-1] + solve(ind-1, (rem + nums[ind-1])%3, nums, dp);

        return dp[ind][rem] = max(take, notTake);
    }

public:
    int maxSumDivThree(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n+1, vector<int> (3, -1));
        return solve(n, 0, nums, dp);
    }
};