#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(n*m*log(n*m))
//Space complexity :- O(n*m)

// Approach :-  
// The water accumulate for any cell wil be min bounday among its neighbour minus curr cell value 
// we'll use bfs traversal from bounday cell with minimum value first
// for maintaining min value and cell we can use min heaps 
// we'll traverse on 4-direction on unvisited cell 
// Visiting any inside cell guarentes we're coming from min value due to using on min heap
// if the next cell having less height then new height will be the one from where we're coming
// because water will get accumulated in that cell and height increase with the presence of water 
// and if the height is less then current cell height we'll carry forward 
// In this case water accumulate will be -ve based on general formula take 0 as additonal water added 


// Link :- https://leetcode.com/problems/trapping-rain-water-ii/

class Solution {
private:
    #define pp pair<int, pair<int,int>>

public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        int m = heightMap.size(), n = heightMap[0].size(), res = 0;
        int dirs[5] = {-1, 0, 1, 0, -1};

        priority_queue<pp, vector<pp>, greater<> > pq;
        vector<vector<bool>> vis(m, vector<bool> (n, false));

        // Add first and last row into the heap
        for(int col=0; col<n; ++col){
            pq.push({heightMap[0][col], {0, col}});
            vis[0][col] = true;
            pq.push({heightMap[m-1][col], {m-1, col}});
            vis[m-1][col] = true;
        }
        // Add first and last col into the heap
        for(int row=1; row<m-1; ++row){
            pq.push({heightMap[row][0], {row, 0}});
            vis[row][0] = true;
            pq.push({heightMap[row][n-1], {row, n-1}});
            vis[row][n-1] = true;
        }

        while(!pq.empty()){
            pp cells = pq.top();
            pq.pop();
            // current value of the cell 
            int height = cells.first;
            int row = cells.second.first;
            int col = cells.second.second;

            for(int i=0; i<4; ++i){
                int nrow = row + dirs[i];
                int ncol = col + dirs[i+1];
                
                if(nrow >= 0 && nrow < m && ncol >= 0 && ncol < n && !vis[nrow][ncol]){
                    res += max(0, height - heightMap[nrow][ncol]);
                    int maxHeight = max(height, heightMap[nrow][ncol]);
                    pq.push({maxHeight, {nrow, ncol}});
                    vis[nrow][ncol] = true;
                }
            }
        }
        return res;
    }
};