#include<bits/stdc++.h>
using namespace std;

// Time Complexity: O(n*m*4^(n*m))  where n is number of rows and m is number of columns
// Space Complexity: O(n*m)  where n is number of rows and m is number of columns

// Approach 
// 1. We will use a recursive function to find the longest increasing path starting from each cell in the matrix.
// 2. We will check all four possible directions (up, down, left, right) from the current cell and move to the next cell if it has a greater value than the current cell.
// 3. We will keep track of the maximum length of the path found so far and return it as the final answer.

// Link :- https://www.geeksforgeeks.org/problems/longest-increasing-path-in-a-matrix/1

class Solution {
  private:
    bool isValid(int row, int col, int &n, int &m, vector<vector<int>> &matrix, int prevVal){
        return (row >= 0 && row < n && col >= 0 && col < m && 
            matrix[row][col] > prevVal);
    }
    
    int solve(int row, int col, vector<vector<int>> &matrix, int &n, int &m){
        int ans = 1;
        int dir[5] = {-1, 0, 1, 0, -1};
        
        for(int i=0; i<4; ++i){
            int nrow = row + dir[i];
            int ncol = col + dir[i+1];
            
            if(isValid(nrow, ncol, n, m, matrix, matrix[row][col])){
                int maxPath = 1 + solve(nrow, ncol, matrix, n, m);
                ans = max(ans, maxPath);
            }
        }
        return ans; 
    }
  
  public:
    int longIncPath(vector<vector<int>> &matrix, int n, int m) {
        int ans = 0;
        
        for(int row=0; row<n; ++row){
            for(int col=0; col<m; ++col){
                int path = solve(row, col, matrix, n, m);
                ans = max(ans, path);
            }
        }
        return ans;
    }
};