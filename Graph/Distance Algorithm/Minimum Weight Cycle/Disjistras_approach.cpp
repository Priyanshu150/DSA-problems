#include<bits/stdc++.h>
using namespace std;

// Time complextiy :- O(e*(v+e)*log(v))
// Space complexity :- O(v+e)

// Approach :-
// Try removing each each one by one and find path b/w the edge removed 
// For find path use dijistras algorithm, while applying algo don't consider direct edge that was removed
// If we're able to find a path then cycle exist for that one otherwise not 
// If cycle exist then cycle weight will be distance for the path(given by dijistra) + current_edge_weight which was removed
// maintain the minimum answer in a variable 


// Link :- https://www.geeksforgeeks.org/problems/minimum-weight-cycle/1

class Solution {
    #define pii pair<int,int>
  
  private:
    int dijistras(int src, int dest, int &V, vector<vector<pii>> &graph){
        priority_queue<pii, vector<pii>, greater<pii>> pq;
        vector<int> dist(V, INT_MAX);
        
        pq.push({0, src});
        dist[src] = 0;
        
        while(!pq.empty()){
            int node = pq.top().second;
            int cost = pq.top().first;
            pq.pop();
            
            if(dist[node] < cost)
                continue;
            
            for(auto it: graph[node]){
                int adjNd = it.first;
                int edgWt = it.second;
                
                if((src == node && dest == adjNd) || (src == adjNd && dest == node))
                    continue;
                
                if(cost + edgWt < dist[adjNd]){
                    dist[adjNd] = cost + edgWt;
                    pq.push({dist[adjNd], adjNd});
                }
            }
        }
        return dist[dest];
    }
  
  public:
    int findMinCycle(int V, vector<vector<int>>& edges) {
        // code here
        vector<vector<pii>> graph(V);
        
        for(auto edge : edges){
            int u = edge[0], v = edge[1], wt = edge[2];
            graph[u].push_back({v, wt});
            graph[v].push_back({u, wt});
        }
        int ans = INT_MAX;
        
        for(auto edge: edges){
            int u = edge[0], v = edge[1], wt = edge[2];
            int dist = dijistras(u, v, V, graph);
            
            if(dist != INT_MAX)
                ans = min(ans, dist + wt);
        }
        return (ans == INT_MAX) ? -1 : ans;
    }
};
