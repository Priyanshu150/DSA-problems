#include<bits/stdc++.h>
using namespace std;

// Time complextiy :- O(V+E)
// Space complexity :- O(V+E)

// Approach :-  
// remove the priority queue and apply bfs instead as edge weight is 1 or 2 

// Link :- https://www.geeksforgeeks.org/problems/level-of-nodes1147/1

class Solution {
  private:
    typedef pair<int,int> pii;
  
  public:
    int shortestPath(int V, int src, int dest, vector<vector<int>> &edges) {
        vector<pii> graph[V];
        
        for(auto edge: edges){
            int u = edge[0], v = edge[1], wt = edge[2];
            
            graph[u].push_back({v, wt});
            graph[v].push_back({u, wt});
        }
        
        queue<pii> pq;
        vector<int> dist(V, INT_MAX);
        
        dist[src] = 0;
        pq.push({0, src});
        
        while(!pq.empty()){
            pii next = pq.front();
            pq.pop();
            
            int currDist = next.first;
            int node = next.second;
            
            if(currDist > dist[node]){
                continue;
            }
            
            for(auto adjNbr: graph[node]){
                int adjNd = adjNbr.first;
                int wt = adjNbr.second;
                
                if(currDist + wt < dist[adjNd]){
                    dist[adjNd] = currDist + wt;
                    pq.push({dist[adjNd], adjNd});
                }
            }
        }
        
        return (dist[dest] == INT_MAX) ? -1 : dist[dest];
    }
};