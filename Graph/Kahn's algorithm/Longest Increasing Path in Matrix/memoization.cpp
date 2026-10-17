#include<bits/stdc++.h>
using namespace std;

// Time Complexity: O(n*m)  where n is number of rows and m is number of columns
// Space Complexity: O(n*m)  

// Approach : Memoization
// memoize the brute force solution using 2d dp array 

// Link :- https://www.geeksforgeeks.org/problems/longest-increasing-path-in-a-matrix/1

class Solution {
  private:
    bool isValid(int row, int col, int &n, int &m, vector<vector<int>> &matrix, int prevVal){
        return (row >= 0 && row < n && col >= 0 && col < m && 
            matrix[row][col] > prevVal);
    }
    
    int solve(int row, int col, vector<vector<int>> &matrix, int &n, int &m, 
            vector<vector<int>> &dp){
        
        if(dp[row][col] != -1)
            return dp[row][col];
        
        int ans = 1;
        int dir[5] = {-1, 0, 1, 0, -1};
        
        for(int i=0; i<4; ++i){
            int nrow = row + dir[i];
            int ncol = col + dir[i+1];
            
            if(isValid(nrow, ncol, n, m, matrix, matrix[row][col])){
                int maxPath = 1 + solve(nrow, ncol, matrix, n, m, dp);
                ans = max(ans, maxPath);
            }
        }
        return  dp[row][col] = ans; 
    }
  
  public:
    int longIncPath(vector<vector<int>> &matrix, int n, int m) {
        int ans = 0;
        vector<vector<int>> dp(n, vector<int> (m, -1));
        
        for(int row=0; row<n; ++row){
            for(int col=0; col<m; ++col){
                int path = solve(row, col, matrix, n, m, dp);
                ans = max(ans, path);
            }
        }
        return ans;
    }
};