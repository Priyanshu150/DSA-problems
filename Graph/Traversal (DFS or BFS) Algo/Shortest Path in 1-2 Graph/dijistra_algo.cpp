#include<bits/stdc++.h>
using namespace std;

// Time complextiy :- O(E + V*log(V))
// Space complexity :- O(V+E)

// Approach :-  
// apply standard dijistra's algo 

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
        
        priority_queue<pii, vector<pii>, greater<pii>> pq;
        vector<int> dist(V, INT_MAX);
        
        dist[src] = 0;
        pq.push({0, src});
        
        while(!pq.empty()){
            pii next = pq.top();
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