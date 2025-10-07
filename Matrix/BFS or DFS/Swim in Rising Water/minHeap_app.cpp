#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(n*n)
//Space complexity :- O(n*n)

// Approach :-  
// We've to find a path from top-left to bottom-right such that the cell value among them is minimum
// we can try exploring all path from the current cell 
// and can use the min heap to keep track the cell having minimum value first
// whenever we first reach the end that will be our minimum path value 


// Link :- https://leetcode.com/problems/swim-in-rising-water/

class Solution {
private:
    #define pii pair<int, pair<int,int>> 

public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        int dirs[] = {-1, 0, 1, 0, -1};

        priority_queue<pii, vector<pii>, greater<pii> > pq;
        vector<vector<bool>> vis(n, vector<bool> (n, false));

        vis[0][0] = true;
        pq.push({grid[0][0], {0, 0}});

        while(!pq.empty()){
            pii it = pq.top();
            pq.pop();

            int val = it.first;
            int row = it.second.first;
            int col = it.second.second;

            if(row == n-1 && col == n-1)
                return val;
            
            for(int i=0; i<4; ++i){
                int nrow = row + dirs[i];
                int ncol = col + dirs[i+1];

                if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < n && vis[nrow][ncol] == false){
                    int maxVal = max(val, grid[nrow][ncol]);
                    pq.push({maxVal, {nrow, ncol}});
                    vis[nrow][ncol] = true;
                }
            }
        }
        return 500;
    }
};