#include<bits/stdc++.h>
using namespace std;

//Time complexity :- O(100*n)
//Space complexity :- O(100*n + n)

// Approach :-
// Create all the perfect square till number 100 and store it in some ds 
// till 100 because constraint says n will be at max 1e4
// using dp we can solve this, problem is similar to subset sum problem 
// using same approach to solve the problem 
// 2d dp will suffice for memo as there will be max 100 * n values 

//link :- https://www.geeksforgeeks.org/problems/get-minimum-squares0538/1

class Solution {
  private:
    int solve(int ind, int sum, vector<int> &nums, vector<vector<int>> &dp){
        // base case 
        if(sum == 0)        return 0;
        if(ind == 100)      return 1e5;
        if(dp[ind][sum] != -1)
            return dp[ind][sum];
        
        // not take the current number and move to next 
        int notTake = solve(ind+1, sum, nums, dp), take = 1e5;
        // take the current number if number is less than target 
        if(nums[ind] <= sum)
            take = 1 + solve(ind, sum - nums[ind], nums, dp);
        
        // the min of both possibilities will be our answer 
        return dp[ind][sum] =   min(notTake, take);
    }
  
  public:
    int minSquares(int n) {
        // Code here
        vector<int> nums;
        
        // create all the valid square combination 
        for(int i=1; i<=100; ++i){
            int prod = i*i;
            nums.push_back(prod);
        }
        // declare 2d dp vector of size 100*n
        vector<vector<int>> dp(100, vector<int> (n+1, -1));
        return solve(0, n, nums, dp);
    }
};