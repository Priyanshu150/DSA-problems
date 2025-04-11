#include<bits/stdc++.h>
using namespace std;

// Time complexity :- O(e*log(e))
// Space complexity :- O(v+e)              

// Approach :- 
// Use priority_queue to keep track of min edge distance, maintain the node in format of {dist, node}
// maintain a dist array intially every distance is INT_MAX
// distance of source will be 0, and push {0, src} into the queue
// take out the node present at the top, traverse on the adjacent node of current node 
// if the dist_till_curr_node + edg_wt < dist_of_adj_node then, 
// update the distance in array and push that into the queue 


// Links :- https://www.geeksforgeeks.org/problems/implementing-dijkstra-set-1-adjacency-matrix/1

class Solution {
    #define pii pair<int,int>
    
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        // Code here
        vector<vector<pii>> graph(V);
        
        for(auto edge: edges){
            int u = edge[0], v = edge[1], wt = edge[2];
            
            graph[u].push_back({v, wt});
            graph[v].push_back({u, wt});
        }
        
        priority_queue<pii, vector<pii>, greater<pii>> pq;
        vector<int> dist(V, INT_MAX);
        
        pq.push({0, src});
        dist[src] = 0;
        
        while(!pq.empty()){
            pii curr = pq.top();
            pq.pop();
            
            int node = curr.second;
            int currDist = curr.first;
            
            for(pii adj: graph[node]){
                int adjNode = adj.first, wt = adj.second;
                if(dist[adjNode] > currDist + wt){
                    dist[adjNode] = currDist + wt;
                    pq.push({dist[adjNode], adjNode});
                }
            }
        }
        return dist;
    }
};
