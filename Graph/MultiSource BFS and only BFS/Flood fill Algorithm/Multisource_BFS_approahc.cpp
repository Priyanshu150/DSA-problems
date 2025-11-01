#include<bits/stdc++.h>
using namespace std;

// Time complexity :- O(n*m)
// Space complexity :- O(n*m)              

// Approach :- 
// We'll use multisource bfs to solve this problem
// Starting from the src provided we'll save the color of that and put that node into queue 
// Taking each node out from queue changing it's color and traversing on the adjacent node 
// if the node has same color then push it on the queue


// Links :- https://www.geeksforgeeks.org/problems/flood-fill-algorithm1856/1

class Solution {
    #define pii pair<int,int>
  
  private:
    bool isValid(int row, int col, int &n, int &m){
        return (row>=0 && row<n && col>=0 && col<m);
    }
    
  public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc,
                                  int newColor) {
        // Code here
        int n = image.size(), m = image[0].size(), color = image[sr][sc];
        if(newColor == color)
            return image;
        
        
        queue<pii> q;
        int dir[] = {-1, 0, 1, 0, -1};
        q.push({sr, sc});
        
        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            
            image[row][col] = newColor;
            
            for(int i=0; i<4; ++i){
                int nr = row + dir[i], nc = col + dir[i+1];
                if(isValid(nr, nc, n, m) && image[nr][nc] == color)
                    q.push({nr, nc});
            }
        }
        return image;
    }
};