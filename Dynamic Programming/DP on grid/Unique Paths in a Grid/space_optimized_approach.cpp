#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(m*n)
// Space complexity :- O(m)

// Approach :- 
// Instead a 2-d array we use 2 array to reduce more space 
// since we're only using prev and curr column


//Link :- https://www.geeksforgeeks.org/problems/unique-paths-in-a-grid--170647/1

class Solution {
  public:
    int uniquePaths(vector<vector<int>> &grid) {
        // code here
        int n = grid.size(), m = grid[0].size();
        
        if(grid[0][0] == 1 || grid[n-1][m-1] == 1)
            return 0;
        
        vector<int> prev(m, 0), curr(m, 0);
        prev[0] = 1;
        
        for(int col=1; col<m; ++col){
            if(grid[0][col])
                break;
            else
                prev[col] = 1;
        }
        
        for(int row=1; row<n; ++row){
            vector<int> curr(m, 0);
            curr[0] = (grid[row][0] == 0) ? prev[0] : 0;
            
            for(int col = 1; col < m; ++col){
                if(grid[row][col] == 0){
                    curr[col] = prev[col] + curr[col - 1];
                } else {
                    curr[col] = 0;
                }
            }
            prev = curr;
        }
        return prev[m-1];
    }
};