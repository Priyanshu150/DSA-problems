#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(N*W)  
// Space complexity :- O(N*W)

// Approach :-
// Instead of reucrion we can loop on ind & W and use 2-d dp array and convert the memoization to tablulation
// all the value will be 0, include the base case where ind==0 the for all values of w the dp[0][w] = val[0]
// we can take all possibities from memoization and the answer will be stored at dp[n][m]

// Link :- https://www.geeksforgeeks.org/problems/0-1-knapsack-problem0945/1


class Solution {
  public:
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        // code here
        int n = val.size();
        vector<vector<int>> dp(n, vector<int> (W+1, 0));
        
        for(int w=0; w<=W; ++w){
            if(wt[0] <= w)
                dp[0][w] = val[0];
        }
        
        for(int ind=1; ind<n; ++ind){
            for(int w=1; w<=W; ++w){
                dp[ind][w] = dp[ind-1][w];
                
                if(wt[ind] <= w)
                    dp[ind][w] = max(dp[ind][w], val[ind] + dp[ind-1][w-wt[ind]]);
            }
        }
        return dp[n-1][W];
    }
};