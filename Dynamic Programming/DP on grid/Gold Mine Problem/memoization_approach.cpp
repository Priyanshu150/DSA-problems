#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(n^3)
// Space complexity :- O(n^2)

// Approach :-  
// memoize the recursive solution 
// row and col are changing parameters then 2-d dp will suffice 


// links :- https://www.geeksforgeeks.org/problems/gold-mine-problem2608/1

class Solution {
  private:
    int n, m;
    
    int solve(int row, int col, vector<vector<int>>& mat, vector<vector<int>>& dp){
        if(col == m)
            return 0;
        
        if(dp[row][col] != -1)
            return dp[row][col];
        
        int up = 0, right = 0, down = 0;
        
        if(row-1 >= 0)
            up += solve(row-1, col+1, mat, dp);
        
        if(row+1 < n)
            down += solve(row+1, col+1, mat, dp);
        
        right = solve(row, col+1, mat, dp);
        
        return dp[row][col] = mat[row][col] + max({up, right, down});
    }
    
  public:
    int maxGold(vector<vector<int>>& mat) {
        // code here
        n = mat.size();
        m = mat[0].size();
        int res = 0;
        vector<vector<int>> dp(n, vector<int> (m, -1));
        
        for(int row=0; row<n; ++row){
            res = max(res, solve(row, 0, mat, dp));
        }
        return res;
    }
};