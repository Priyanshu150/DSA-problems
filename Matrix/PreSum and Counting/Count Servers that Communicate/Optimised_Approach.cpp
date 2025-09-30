#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(M*N)
// Space complexity :- O(M + N)

//Approach :- 
// Count the number of server in every row and column
// if any row or col where server is present has only 1 row count of server or 1 col count of server
// Then that server is in isolation rest all are communicating server


//Link :- https://leetcode.com/problems/count-servers-that-communicate/description/

class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size(), communicating_server = 0;
        vector<int> rowsCnt(n, 0), colsCnt(m, 0);

        for(int row=0; row<n; ++row){
            for(int col=0; col<m; ++col){
                if(grid[row][col]){
                    rowsCnt[row] += 1;
                    colsCnt[col] += 1;
                    communicating_server += 1;
                }
            }
        }
        for(int row=0; row<n; ++row){
            for(int col=0; col<m; ++col){
                if(grid[row][col]){
                    if(rowsCnt[row] == 1 && colsCnt[col] == 1)
                        communicating_server--;
                }
            }
        }
        return communicating_server;
    }
};