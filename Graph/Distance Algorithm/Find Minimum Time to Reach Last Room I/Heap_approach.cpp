#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(n*m*log(n*m))  
// Space complexity :- O(n*m)

// Approach :-
// we'll use distance algorithm to find the shortest time
// use priority_queue to keep track of the lowest time and apply level order traversal on the graph
// while updating the dist find the max time b/w the time taken till now + 1 and moveTime[i] + 1

// Link :- https://leetcode.com/problems/find-minimum-time-to-reach-last-room-i/

class Solution {
private:
    #define pii pair<int, pair<int,int>> 

    bool isValid(int row, int col, int &n, int &m){
        return (row>=0 && row<n && col>=0 && col<m);
    }

public:
    int minTimeToReach(vector<vector<int>>& moveTime) {
        int n = moveTime.size(), m = moveTime[0].size();
        priority_queue<pii, vector<pii>, greater<pii>> pq;
        vector<vector<bool>> vis(n, vector<bool> (m, false));
        int dirs[] = {-1, 0, 1, 0, -1};

        pq.push({0, {0, 0}});
        vis[0][0] = true;

        while(!pq.empty()){
            int dist = pq.top().first;
            int row = pq.top().second.first;
            int col = pq.top().second.second;
            pq.pop();

            if(row == n-1 && col == m-1)
                return dist;

            for(int i=0; i<4; ++i){
                int nr = row + dirs[i], nc = col + dirs[i+1];
                if(isValid(nr, nc, n, m) && !vis[nr][nc]){
                    int newDist = max(dist, moveTime[nr][nc]) + 1;
                    pq.push({newDist, {nr, nc}});
                    vis[nr][nc] = true;
                }
            }
        }
        return 0;
    }
};