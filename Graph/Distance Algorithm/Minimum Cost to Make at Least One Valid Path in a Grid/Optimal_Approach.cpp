#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(N*M*log(N*M))
// Space complexity :- O(3*N*M)

//Approach :- 
//Build a graph where grid[i][j] is connected to all the four side-adjacent cells with weighted edge. 
//The weight is 0 if the sign is pointing to the adjacent cell or 1 otherwise.
//Apply dijistra's from (0, 0) visit all edges with weight = 0 first
//The answer is the distance to (m -1, n - 1)

//Link :- https://leetcode.com/problems/minimum-cost-to-make-at-least-one-valid-path-in-a-grid/description/

//Solution 1
class Solution {
private:
    int n, m;

    int findNodeNumber(int row, int col){
        return (m*row + col);
    }

    bool isValid(int row, int col){
        return (row>=0 && row<n && col>=0 && col<m);
    }

public:
    int minCost(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        int maxLen = (n*m);

        vector<pair<int,int>> graph[maxLen];
        vector<pair<int,int>> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

        //Building the graph
        for(int row=0; row<n; ++row){
            for(int col=0; col<m; ++col){
                int nodeNum = findNodeNumber(row, col);

                for(int i=0; i<4; ++i){
                    int nr = row + dir[i].first;
                    int nc = col + dir[i].second;

                    if(isValid(nr, nc)){
                        int adjNodeNum = findNodeNumber(nr, nc);
                        if(i+1 == grid[row][col])
                            graph[nodeNum].push_back({adjNodeNum, 0});
                        else 
                            graph[nodeNum].push_back({adjNodeNum, 1});
                    }
                }
            }
        }
        //Applying Dijystra's algorithm
        vector<int> dist(maxLen, INT_MAX);
        priority_queue< pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > pq;

        pq.push({0, 0});
        dist[0] = 0;

        while(!pq.empty()){
            int node = pq.top().second;
            int costTillNow = pq.top().first;
            pq.pop();

            for(auto edge: graph[node]){
                int adjNode = edge.first;
                int cost = edge.second;

                if(costTillNow + cost < dist[adjNode]){
                    pq.push({costTillNow + cost, adjNode});
                    dist[adjNode] = costTillNow + cost;
                }
            }
        }
        return dist[maxLen - 1];
    }
};

//Solution 2
class Solution {
    #define pii pair<int,pair<int,int>> 

private:
    bool isValid(int row, int col, int &n, int &m){
        return (row>=0 && row<n && col>=0 && col<m);
    }

public:
    int minCost(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int dr[4] = {0, 0, 1, -1};
        int dc[4] = {1, -1, 0, 0};

        vector<vector<bool>> vis(n, vector<bool> (m, false));
        priority_queue<pii, vector<pii>, greater<pii>> pq;
        pq.push({0, {0,0}});

        while(!pq.empty()){
            auto node = pq.top();
            pq.pop();

            int row = node.second.first;
            int col = node.second.second;
            int cost = node.first;

            if(vis[row][col])       continue;
            if(row == n-1 && col == m-1)
                return cost;
            
            vis[row][col] = true;

            for(int i=0; i<4; ++i){
                int nr = row + dr[i];
                int nc = col + dc[i];

                if(isValid(nr, nc, n, m) && !vis[nr][nc]){
                    int newCost = cost + (i+1 == grid[row][col] ? 0 : 1);
                    pq.push({newCost, {nr, nc}});
                }
            }
        }
        return 0;
    }
};