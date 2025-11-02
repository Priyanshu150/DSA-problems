#include<bits/stdc++.h>
using namespace std;

//Time complexity :- O(n*m)
//Space complexity :- O(n*m)

// Approach :-
// using the same approach as mention 
// for every guard marking the up, left, right and down 
// mark wall with 2, then guard with 3 
// again for every guard traverse on all the direction and mark 1 
// until next guard, wall or out of index found 


//link :- https://leetcode.com/problems/count-unguarded-cells-in-the-grid/description/

class Solution {
private:
    void markGuarded(int row, int col, vector<vector<int>> &grid){
        // east 
        for(int c=col+1; c<grid[0].size(); ++c){
            if(grid[row][c] == 2 || grid[row][c] == 3)
                break;
            
            grid[row][c] = 1;
        }

        // west 
        for(int c=col-1; c>=0; --c){
            if(grid[row][c] == 2 || grid[row][c] == 3)
                break;
            
            grid[row][c] = 1;
        }

        // north
        for(int r=row-1; r>=0; --r){
            if(grid[r][col] == 2 || grid[r][col] == 3)
                break;
            
            grid[r][col] = 1;
        }

        // south 
        for(int r=row+1; r<grid.size(); ++r){
            if(grid[r][col] == 2 || grid[r][col] == 3)
                break;
            
            grid[r][col] = 1;
        }
    }

public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<int>> grid(m, vector<int> (n, 0));

        // mark the index where wall is present
        for(auto wall: walls){
            int row = wall[0];
            int col = wall[1];
            grid[row][col] = 2;
        }
        // mark the index where guard
        for(auto guard: guards){
            int row = guard[0], col = guard[1];
            grid[row][col] = 3;
        }
        
        // mark each cell which guard can se 
        for(auto guard: guards){
            int row = guard[0], col = guard[1];
            markGuarded(row, col, grid);
        }
        int res = 0;

        for(int row=0; row<m; ++row){
            for(int col=0; col<n; ++col){
                if(grid[row][col] == 0)
                    res++;
            }
        }
        return res;
    }
};