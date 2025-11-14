#include<bits/stdc++.h>
using namespace std;

// Time complexity :- O(n*n*n)               
// Space complexity :- O(n*n)          

// Approach :-
// intialize the 2d dp with maximum_val 
// i = (0 to n-1) and j = (n-1 to 0) opp of recursion 
// whenever j >= i, set dp[i][j] = 0 and skip rest 
// otherwise express the same possibilites from recursion 
// the final answer will be present at  dp[0][n-1]


// Links :- 
// gfg - https://www.geeksforgeeks.org/problems/matrix-chain-multiplication0303/1
// leetcode - https://leetcode.com/problems/minimum-cost-to-merge-stones/description/

class Solution {
  public:
    int mergeStones(vector<int> &stones, int k) {
        // code here
        int n = stones.size();
        
        // not possible case -> total stones has to removed will be n-1
        // and in each step we're removing k-1 stone hence remainder should be 0
        if((n-1) % (k-1) != 0)
            return -1;
        
        // initailize 2d dp array 
        vector<vector<int>> dp(n+1, vector<int> (n+1, INT_MAX));
        // intialize prefix sum array with n+1 size 
        vector<int> prefixSum(n+1, 0);
        
        
        // maintain prefix sum
        for(int i=0; i<n; ++i){
            prefixSum[i+1] = prefixSum[i] + stones[i];
        }
        
        // try-out all ways using tabulations 
        for(int i=n-1; i>=0; --i){
            for(int j=0; j<n; ++j){
                if(i >= j){
                    // base case condition 
                    dp[i][j] = 0;
                    continue;
                }
                // try to make every valid partitions 
                for(int ind=i; ind<j; ind+=(k-1)){
                    int cost = dp[i][ind] + dp[ind+1][j];
                    dp[i][j] = min(cost, dp[i][j]);
                }
                // add the contribution of current k consecutive numbers 
                if((j-i) % (k-1) == 0){
                    int sum = prefixSum[j+1] - prefixSum[i];
                    
                    if(dp[i][j] != INT_MAX)
                        dp[i][j] += sum;
                }
            }
        }
        return dp[0][n-1];
    }
};