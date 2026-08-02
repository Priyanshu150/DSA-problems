#include<bits/stdc++.h>
using namespace std;


// Time complextiy :- O(n*m*m)
// Space complexity :- O(n*m + stack_space )

// Approach :-   
// we've to try all posibility, so we maintain two states 
// fisrt the index -> number taken till now and prev -> last number which was choosen
// dp[index][prev] represent for index length and prev element as last element what the maximum count 
// try taken every number from 1 to m which divide the number 
// memoize the solution using 2d dp 
 
// Link :- https://www.geeksforgeeks.org/problems/count-in-array2138/1

class Solution {
  private:
    int solve(int ind, int prev, int &n, int &m, vector<vector<int>> &dp){
        if(ind == n)        return 1;
        
        if(dp[ind][prev] != -1)
            return dp[ind][prev];
        
        int res = 0;
        
        for(int i=1; i<=m; ++i){
            if((prev == m+3) || (prev % i) == 0 || (i % prev) == 0){
                res += solve(ind+1, i, n, m, dp);
            }
        }
        return dp[ind][prev] = res;
    }
  
  public:
    int count(int n, int m) {
        vector<vector<int>> dp(n+1, vector<int> (m+5, -1));
        return solve(0, m+3, n, m, dp);
    }
};