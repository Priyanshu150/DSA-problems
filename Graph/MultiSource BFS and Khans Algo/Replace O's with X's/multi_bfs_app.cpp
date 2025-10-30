#include<bits/stdc++.h>
using namespace std;

// Time Complexity: O(n*m)
// Space Complexity: O(n*m)

// Approach :- 
// all the 'O' which are present at the border or touching border of the grid will not be converted 
// hence we can apply multisource bfs from all the corner 'O' grid 
// mark all the one which are touch border and mark them as visited 
// at last check the 'O' which are not vis make them as 'X' 


// Link :- https://www.geeksforgeeks.org/problems/replace-os-with-xs0052/1

class Solution {
  private:
    typedef pair<int, int> pi;
    
    // check wheater a {row, col} is valid or not  
    bool isValid(int row, int col, int &n, int &m){
        return (row>=0 && row<n && col>=0 && col<m);
    }
  
  public:
    void fill(vector<vector<char>>& grid) {
        // Code here
        int n = grid.size(), m = grid[0].size();
        queue<pi> q;  // represents {row, col}
        // {i, i+1} represent down, right, up and left
        int dirs[] = {-1, 0, 1, 0, -1};
        vector<vector<bool>> vis(n, vector<bool> (m, false));
        
        // push the 'O' in the queue which are present on the border 
        for(int row=0; row<n; ++row){
            // left-most column
            if(grid[row][0] == 'O'){
                q.push({row, 0});
                vis[row][0] = true;
            }
            // right-most column
            if(grid[row][m-1] == 'O'){
                q.push({row, m-1});
                vis[row][m-1] = true;
            }
        }
        
        for(int col=0; col<m; ++col){
            // top-most column
            if(grid[0][col] == 'O'){
                q.push({0, col});
                vis[0][col] = true;
            }
            // bottom-most column 
            if(grid[n-1][col] == 'O'){
                q.push({n-1, col});
                vis[n-1][col] = true;
            }
        }
        
        // standard bfs on corner 'O'
        while(!q.empty()){
            pi it = q.front();
            q.pop();
            
            int row = it.first;
            int col = it.second;
            
            // check for adjacent cells
            for(int i=0; i<4; ++i){
                int nrow = row + dirs[i];
                int ncol = col + dirs[i+1];
                
                if(isValid(nrow, ncol, n, m) && !vis[nrow][ncol] && grid[nrow][ncol] == 'O'){
                    q.push({nrow, ncol});
                    vis[nrow][ncol] = true;
                }
            }
        }
        
        // mark all the 'O' to 'X' which are not visited via bfs
        for(int row=0; row<n; ++row){
            for(int col=0; col<m; ++col){
                if(grid[row][col] == 'O' && !vis[row][col]){
                    grid[row][col] = 'X';
                }
            }
        }
    }
};