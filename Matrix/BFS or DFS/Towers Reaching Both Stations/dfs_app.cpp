#include<bits/stdc++.h>

//Time complextiy :- O(n+m)
// Space complexity :- O(n+m)

// Approach :-  

//Link :- https://www.geeksforgeeks.org/problems/geeks-island--170646/1

class Solution {
  private:
    vector<int> dirs = {-1, 0, 1, 0, -1};

    bool isValid(int row, int col, vector<vector<int>> &mat){
        int n = mat.size();
        int m = mat[0].size();
        
        return (row >= 0 && row < n && col >= 0 && col < m);
    }
  
    void dfs(int row, int col, vector<vector<bool>> &vis, vector<vector<int>> &mat){
        vis[row][col] = true;
        
        for(int i=0; i<4; ++i){
            int nrow = row + dirs[i];
            int ncol = col + dirs[i+1];
            
            if(isValid(nrow, ncol, mat) && !vis[nrow][ncol] && mat[nrow][ncol] >= mat[row][col]) 
                dfs(nrow, ncol, vis, mat);
        }
    }
  
  public:
    int countCoordinates(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        
        vector<vector<bool>> towerReachP(n, vector<bool> (m, false));
        vector<vector<bool>> towerReachQ(n, vector<bool> (m, false));
        
        for(int row=0; row<n; ++row){
            dfs(row, 0, towerReachP, mat);
            dfs(row, m-1, towerReachQ, mat);
        }
        
        for(int col=0; col<m; ++col){
            dfs(0, col, towerReachP, mat);
            dfs(n-1, col, towerReachQ, mat);
        }
        int res = 0;
        
        for(int row=0; row<n; ++row){
            for(int col=0; col<m; ++col){
                if(towerReachP[row][col] && towerReachQ[row][col]){
                    res++;
                }
            }
        }
        return res;
    }
};