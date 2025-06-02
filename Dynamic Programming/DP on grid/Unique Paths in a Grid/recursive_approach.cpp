#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(2^(m*n))
// Space complexity :- O(stack_space)

// Approach :- 
// for find the total number of ways we've to explore all possibilities that's why recursion
// Either (0, 0) to (n-1, m-1) and (n-1, m-1) to (0, 0), we'll use 2nd one 
// row & col will be 2 changing state parameter
// if row-1 exist then go on to left cell and count then number of ways 
// and also if col-1 exists then go on to the up cell and count the number of ways
// the total ways will be sum of left an up cell 
// base case will be, when row == 0 and col == 0 then only 1 way exists 

//Link :- https://www.geeksforgeeks.org/problems/unique-paths-in-a-grid--170647/1

class Solution {
  private:
    int solve(int row, int col, vector<vector<int>> &grid){
        if(row == 0 && col == 0)
            return 1;
        
        int up = 0, left = 0;
        
        if(row-1 >= 0 && grid[row-1][col] == 0)
            up = solve(row-1, col, grid);
        
        if(col-1 >= 0 && grid[row][col-1] == 0)
            left = solve(row, col-1, grid);
        
        return (up + left);
    }
  
  public:
    int uniquePaths(vector<vector<int>> &grid) {
        // code here
        int n = grid.size(), m = grid[0].size();
        
        if(grid[0][0] == 1 || grid[n-1][m-1] == 1)
            return 0;
        
        return solve(n-1, m-1, grid);
    }
};