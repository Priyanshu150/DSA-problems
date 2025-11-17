#include<bits/stdc++.h>
using namespace std;

// Time complexity :- O(n*n)               
// Space complexity :- O(n*n + n(stack space))          

// Approach :-
// The question is same as LIS and max subsequence sum 
// merging both the concept we'll sovle this problem 

// Links :- https://www.geeksforgeeks.org/problems/maximum-sum-increasing-subsequence4749/1

class Solution {
  private:
    int solve(int ind, int nextInd, vector<int> &nums, int &n, vector<vector<int>> &dp){
        // base case 
        if(ind == 0)
            return 0;
        // memoization step
        if(dp[ind][nextInd] != -1)
            return dp[ind][nextInd];
        
        // try all possibilities 
        int notTake = solve(ind-1, nextInd, nums, n, dp), take = 0;
        if(nextInd == n+1 || nums[ind-1] < nums[nextInd-1])
            take = nums[ind-1] + solve(ind-1, ind, nums, n, dp);
        
        // max of both option will 
        return dp[ind][nextInd] = max(take, notTake);
    }
  
  public:
    int maxSumIS(vector<int>& arr) {
        int n = arr.size();
        // initialize a 2d dp vector with -1
        vector<vector<int>> dp(n+1, vector<int> (n+2, -1));
        return solve(n, n+1, arr, n, dp);
    }
};