#include<bits/stdc++.h>
using namespace std;

// Time complexity :- O(n*m)                 
// Space complexity :- O(n*m)                  

// Approach :- 
// for find the number of island we can use the concept of dfs traversal on different component
// Count the number of component that will be our answer i.e number of island
// maintain a vis array, apply dfs for the cell on which you find land 'l'
// traverse on all 8 direction and mark all the connect land as visited considering it as 1 island
// repeate the same for other component using same technique


// Links :- https://www.geeksforgeeks.org/problems/find-the-number-of-islands/1

class Solution {
  private:
    bool isValid(int row, int col, vector<vector<char>>& grid){
        return (row >= 0 && row < grid.size() && col >= 0 && col < grid[0].size());
    }
  
    void dfs(int row, int col, vector<vector<bool>> &vis, vector<vector<char>>& grid){
        vis[row][col] = true;
        
        for(int dr=-1; dr<=1; ++dr){
            for(int dc=-1; dc<=1; ++dc){
                if(dr == 0 && dc == 0)  continue;
                int nr = row + dr, nc = col + dc;
                if(isValid(nr, nc, grid) && grid[nr][nc] == 'L' && !vis[nr][nc])
                    dfs(nr, nc, vis, grid);
            }
        }
    }
  
  public:
    int countIslands(vector<vector<char>>& grid) {
        // Code here
        int n = grid.size(), m = grid[0].size(), res = 0;
        vector<vector<bool>> vis(n, vector<bool> (m, false));
        
        for(int row=0; row<n; ++row){
            for(int col=0; col<m; ++col){
                if(grid[row][col] == 'L' && !vis[row][col]){
                    ++res;
                    dfs(row, col, vis, grid);
                }
            }
        }
        return res;
    }
};
