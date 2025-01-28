#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(n*m)
// Space complexity :- O(n*m)

// Approach :- 
// Go in every pond and check wheather that pond is explored earlier or not 
// If not not call dfs which will tell the number of fish present in the pond
// Keep track of the pond which has maximum number of fish

//Link :- https://leetcode.com/problems/maximum-number-of-fish-in-a-grid/description/

class Solution {
private:
    int n, m;
    int dr[4] = {0, 0, -1, 1};
    int dc[4] = {-1, 1, 0, 0};

    bool isValid(int row, int col){
        return (row>=0 && row<n && col>=0 && col<m);
    }

    int dfs(int row, int col, vector<vector<bool>> &vis, vector<vector<int>>& grid){
        vis[row][col] = true;
        int fish = grid[row][col];

        for(int i=0; i<4; ++i){
            int nr = row+dr[i], nc = col+dc[i];
            if(isValid(nr, nc) && grid[nr][nc]>0 && !vis[nr][nc]){
                fish += dfs(nr, nc, vis, grid);
            }
        }
        return fish;
    }

public:
    int findMaxFish(vector<vector<int>>& grid) {
        int  res = 0;
        n = grid.size(), m = grid[0].size();
        vector<vector<bool>> vis(n, vector<bool> (m, false));

        for(int row=0; row<n; ++row){
            for(int col=0; col<m; ++col){
                if(grid[row][col]>0 && !vis[row][col]){
                    res = max(res, dfs(row, col, vis, grid));
                }
            }
        }
        return res;
    }
};