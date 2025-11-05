#include<bits/stdc++.h>
using namespace std;

//Time complexity :- O(100*n)
//Space complexity :- O(100*n)

// Approach :-
// memozation approach can be further optimized to tabulation 
// express base case first, for any value of ind when sum is 0, the value should be 0
// express the same conditions in tabulation 
// ind = 99 to 0 and sum = 1 to n, will be two for loops and answer will be stored at dp[0][n]

//link :- https://www.geeksforgeeks.org/problems/get-minimum-squares0538/1

class Solution {
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
        vector<vector<int>> dp(101, vector<int> (n+1, 1e5));
        
        for(int ind=0; ind<=100; ++ind)
            dp[ind][0] = 0;
        
        for(int ind=99; ind>=0; --ind){
            for(int sum=1; sum<=n; ++sum){
                // not take the current number and move to next 
                dp[ind][sum] = dp[ind+1][sum];
                // take the current number if number is less than target 
                if(nums[ind] <= sum){
                    // the min of both possibilities will be our answer
                    dp[ind][sum] = min(dp[ind][sum], 1 + dp[ind][sum - nums[ind]]);   
                }
            }
        }
        return dp[0][n];
    }
};