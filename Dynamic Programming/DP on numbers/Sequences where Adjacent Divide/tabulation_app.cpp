#include<bits/stdc++.h>
using namespace std;

// Time complextiy :- O(n*m*m)
// Space complexity :- O(n*m)

// Approach :-   
// convert the memoization solution to tabulation 

// Link :- https://www.geeksforgeeks.org/problems/count-in-array2138/1

class Solution {
  public:
    int count(int n, int m) {
        vector<vector<int>> dp(n+1, vector<int> (m+1, 0));
        
        for(int prev=0; prev<=m; ++prev){
            dp[n][prev] = 1;
        }
        
        for(int ind=n-1; ind>=0; --ind){
            for(int prev=1; prev<=m; ++prev){
                for(int i=1; i<=m; ++i){
                    if((prev % i) == 0 || (i % prev) == 0){
                        dp[ind][prev] += dp[ind+1][i];
                    }
                }
            }
        }
        return dp[0][1];
    }
};