#include<bits/stdc++.h>
using namespace std;

// Time complextiy :- O(N^3)
// Space complexity :- O(N^2)

// Approach :-   
// converting the memoization solution to tabulation 

//Link :- https://www.geeksforgeeks.org/problems/optimal-binary-search-tree2214/1

class Solution {
  public:
    int minCost(vector<int> &keys, vector<int> &freq) {
        int n = freq.size();
        vector<int>preSum(n+1, 0);
        
        // standard prefix sum technique
        for(int i=0; i<n; ++i){
            // sum eqaul to current freq 
            preSum[i+1] = freq[i];
            // add previous sum 
            if(i > 0)
                preSum[i+1] += preSum[i];
        }
        // intialize 2d dp with -1
        vector<vector<int>> dp(n+1, vector<int> (n+1, 0));
        
        for(int i=n-1; i>=0; --i){
            for(int j=0; j<n; ++j){
                if(i > j)
                    continue;
                
                int res = INT_MAX;
                // loop from i to j 
                for(int ind=i; ind<=j; ++ind){
                    // find the current node cost using prefix sum 
                    int cost = (preSum[j+1]-preSum[i]) + dp[i][ind-1] + dp[ind+1][j];
                    // update the min answer 
                    res = min(res, cost);
                }
                dp[i][j] = res;
            }
        }
        return dp[0][n-1];
    }
};