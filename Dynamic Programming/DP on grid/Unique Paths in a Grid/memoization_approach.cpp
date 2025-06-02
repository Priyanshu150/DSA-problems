#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(m*n)
// Space complexity :- O(m*n + stack_space)

// Approach :- 
// Since there are 2 changing parameter a 2-d dp will suffice
// recursion remains same add 2 dp for saving the state 

//Link :- https://www.geeksforgeeks.org/problems/unique-paths-in-a-grid--170647/1

class Solution {
  private:
    int solve(int row, int col, vector<vector<int>> &grid, vector<vector<int>> &dp){
        if(row == 0 && col == 0)
            return 1;
            
        if(dp[row][col] != -1)
            return dp[row][col];
        
        int up = 0, left = 0;
        
        if(row-1 >= 0 && grid[row-1][col] == 0)
            up = solve(row-1, col, grid, dp);
        
        if(col-1 >= 0 && grid[row][col-1] == 0)
            left = solve(row, col-1, grid, dp);
        
        return dp[row][col] = (up + left);
    }
  
  public:
    int uniquePaths(vector<vector<int>> &grid) {
        // code here
        int n = grid.size(), m = grid[0].size();
        
        if(grid[0][0] == 1 || grid[n-1][m-1] == 1)
            return 0;
        
        vector<vector<int>> dp(n, vector<int> (m, -1));
        return solve(n-1, m-1, grid, dp);
    }
};