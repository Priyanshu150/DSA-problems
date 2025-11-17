#include<bits/stdc++.h>
using namespace std;

// Time complexity :- O(n*n)               
// Space complexity :- O(n*n)          


// Links :- https://www.geeksforgeeks.org/problems/maximum-sum-increasing-subsequence4749/1

class Solution {
  public:
    int maxSumIS(vector<int>& arr) {
        int n = arr.size();
        // initialize a 2d dp vector with 0
        vector<vector<int>> dp(n+1, vector<int> (n+2, 0));
        
        for(int ind=1; ind<=n; ++ind){
            for(int nextInd=1; nextInd<=n+1; ++nextInd){
                // try all possibilities 
                int notTake = dp[ind-1][nextInd], take = 0;
                
                if(nextInd == n+1 || arr[ind-1] < arr[nextInd-1])
                    take = arr[ind-1] + dp[ind-1][ind];
                
                // max of both option will 
                dp[ind][nextInd] = max(take, notTake);
            }
        }
        return dp[n][n+1];
    }
};