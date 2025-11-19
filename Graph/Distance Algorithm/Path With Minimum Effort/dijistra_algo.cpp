#include<bits/stdc++.h>
using namespace std;

// Time complextiy :- O((v+e)*log(v+e))
// Space complexity :- O(v+e)

// Approach :-
// we can use dijistra's algo to track each path min distance
// keep track of max cell value along the path using priority_queue

// Link :- https://www.geeksforgeeks.org/problems/path-with-minimum-effort/1

class Solution {
  private:
    typedef pair<int,int> pii;
    typedef pair<int,pii> pip;
    
    bool isValid(int row, int col, int &n, int &m){
        return (row >= 0 && row < n && col >= 0 && col < m);
    }
  
  public:
    int minCostPath(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        //{dirs[i], dirs[i+1]} represent the up, right, down and bottom direction
        vector<int> dirs = {-1, 0, 1, 0, -1};
        
        // min-heap for storing {dist, {row,col}} 
        priority_queue<pip, vector<pip>, greater<pip>> pq;
        pq.push({0, {0,0}});
        
        // a matrix to represent dist till current cell
        vector<vector<int>> dist(n, vector<int> (m, INT_MAX));
        dist[0][0] = 0;
        
        // standard dijistra's 
        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            
            // curr node info
            int currDist = it.first;
            int row = it.second.first;
            int col = it.second.second;
            
            // current cell is last cell 
            if(row == n-1 && col == m-1)
                return currDist;
            
            // traverse on adjacent cell 
            for(int i=0; i<4; ++i){
                int nrow = row + dirs[i];
                int ncol = col + dirs[i+1];
                
                if(isValid(nrow, ncol, n, m)){
                    // cost to move from current cell to next 
                    int cost = max(currDist, abs(mat[row][col] - mat[nrow][ncol]));
                    if(cost < dist[nrow][ncol]){
                        dist[nrow][ncol] = cost;
                        pq.push({dist[nrow][ncol], {nrow, ncol}});
                    }
                }
            }
        }
        return 0;
    }
};
