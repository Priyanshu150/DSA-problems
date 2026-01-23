#include<bits/stdc++.h>
using namespace std;

// Time complexity :- O(n*m + q)                  
// Space complexity :- O(n*m + q)                

// Approach :-
// Instead of applying BFS for every query we can sort queries array 
// that way we and avoid recalculation 
// we can store the query in map that way it will be sorted and we can use map while building our answer
// traverse the bfs based on sorted values and count the node covered during each time
// update the count of nodes during that time in map


// Links :- https://leetcode.com/problems/maximum-number-of-points-from-grid-queries/

class Solution {
#define vi vector<int> 

private:
    bool isValid(int row, int col, int n, int m){
        return (row>=0 && row<n && col>=0 && col<m);
    }

public:
    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
        map<int,int> mp;
        int n = grid.size(), m = grid[0].size(), count = 0;

        for(auto query: queries)
            mp[query] = 0;
        
        int dir[] = {-1, 0, 1, 0, -1};
        vector<vi> vis(n, vi(m, 0));
        priority_queue<vi, vector<vi>, greater<vi> > minHeap;

        vis[0][0] = 1;
        minHeap.push({grid[0][0], 0, 0});

        for(auto [num, cnt] : mp){
            while(!minHeap.empty()){
                vi curr = minHeap.top();
                minHeap.pop();

                int val = curr[0], row = curr[1], col = curr[2];
                if(val >= num){
                    minHeap.push(curr);
                    break;
                }
                count += 1;

                for(int i=0; i<4; ++i){
                    int nr = row + dir[i], nc = col + dir[i+1];
                    if(isValid(nr, nc, n, m) && !vis[nr][nc]){
                        vis[nr][nc] = 1;
                        minHeap.push({grid[nr][nc], nr, nc});
                    }
                }
            }
            mp[num] = count;
        }
        vi ans;

        for(auto query: queries)
            ans.push_back(mp[query]);

        return ans;
    }
};
