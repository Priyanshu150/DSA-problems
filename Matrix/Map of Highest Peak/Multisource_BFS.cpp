#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(N*M)
// Space complexity :- O(N*M)

// Approach :- 
// Use multi souce bfs for solving this problem
// Push all the water cells in the queue
// Apply bfs for all the node present in queue and push all the adjacent nodes
// Use vis array to track which cells are processed or Use the ans array to keep track of visited to save the space 

//Link :- https://leetcode.com/problems/map-of-highest-peak/description/

class Solution {
private:
    bool isValid(int row, int col, int &n, int &m){
        return (row>=0 && row<n && col>=0 && col<m);
    }

public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int n = isWater.size(), m = isWater[0].size(), level = 0;
        vector<vector<int>> ans(n, vector<int> (m, -1));
        queue<pair<int,int>> q;

        for(int row=0; row<n; ++row){
            for(int col=0; col<m; ++col){
                if(isWater[row][col]){
                    q.push({row, col});
                    ans[row][col] = 0;
                }
            }
        }
        int dr[4] = {0, 0, -1, 1};
        int dc[4] = {-1, 1, 0, 0};

        while(!q.empty()){
            int sz = q.size();
            
            while(sz-->0){
                int row = q.front().first;
                int col = q.front().second;
                q.pop();

                ans[row][col] = level;

                for(int i=0; i<4; ++i){
                    int nr = row + dr[i], nc = col + dc[i];
                    if(isValid(nr, nc, n, m) && ans[nr][nc] == -1){
                        q.push({nr, nc});
                        ans[nr][nc] = 0;
                    }
                }
            }
            ++level;
        }
        return ans;
    }
};