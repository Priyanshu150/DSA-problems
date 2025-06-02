#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(m*n)
// Space complexity :- O(m*n)

// Approach :- 
// Express base case first where all element should be initialized 0 and dp[0][0] = 1
// for first row or first coll it will be 1 until grid[row][col] becomes 1 after that 0
// row will go from 1 to n and col will go from 1 to m
// express the same possibilities from recursion 
// the answer will be present at dp[n-1][m-1]


//Link :- https://www.geeksforgeeks.org/problems/unique-paths-in-a-grid--170647/1

class Solution {
  public:
    int uniquePaths(vector<vector<int>> &grid) {
        // code here
        int n = grid.size(), m = grid[0].size();
        
        if(grid[0][0] == 1 || grid[n-1][m-1] == 1)
            return 0;
        
        vector<vector<int>> dp(n, vector<int> (m, 0));
        dp[0][0] = 1;
        
        for(int row=1; row<n; ++row){
            if(grid[row][0] == 0)
                dp[row][0] = 1;
            else 
                break;
        }
        
        for(int col=1; col<m; ++col){
            if(grid[0][col])
                break;
            else
                dp[0][col] = 1;
        }
        
        for(int row=1; row<n; ++row){
            for(int col=1; col<m; ++col){
                if(grid[row][col] == 1)
                    continue;
                
                if(grid[row-1][col] == 0)
                    dp[row][col] += dp[row-1][col];
                
                if(grid[row][col-1] == 0)
                    dp[row][col] += dp[row][col-1];
            }
        }
        return dp[n-1][m-1];
    }
};

class Solution {
  public:
    int uniquePaths(vector<vector<int>> &grid) {
        // code here
        int n = grid.size(), m = grid[0].size();
        
        if(grid[0][0] == 1 || grid[n-1][m-1] == 1)
            return 0;
        
        vector<vector<int>> dp(n, vector<int> (m, 0));
        dp[0][0] = 1;
        
        for(int row=1; row<n; ++row){
            if(grid[row][0] == 0)
                dp[row][0] = 1;
            else 
                break;
        }
        
        for(int col=1; col<m; ++col){
            if(grid[0][col])
                break;
            else
                dp[0][col] = 1;
        }
        
        for(int row=1; row<n; ++row){
            for(int col=1; col<m; ++col){
                if(grid[row][col] == 1)
                    continue;
                
                dp[row][col] = dp[row-1][col] + dp[row][col-1];
            }
        }
        return dp[n-1][m-1];
    }
};