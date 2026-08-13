#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(V+E*log(V))
// Space complexity :- O(V+E)

// Approach :-  
// use the same approach as dijistra to solve the problem 

// links :- https://www.geeksforgeeks.org/problems/longest-path-in-a-directed-acyclic-graph/1


class Solution {
  private:
    typedef pair<int,int> pii;
  
  public:
    vector<int> maxDistance(int V, int src, vector<vector<int>> &edges) {
        vector<pii> graph[V];
        
        for(auto edge: edges){
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];
            
            graph[u].push_back({v, wt});
        }
        
        vector<int> dist(V, INT_MIN);
        queue<pii> pq;
        
        dist[src] = 0;
        pq.push({0, src});
        
        while(!pq.empty()){
            int distTillNow = pq.front().first;
            int node = pq.front().second;
            pq.pop();
            
            if(distTillNow < dist[node])
                continue;
            
            for(auto adjNbr: graph[node]){
                int adjNd = adjNbr.first;
                int wt = adjNbr.second;
                
                if(distTillNow + wt > dist[adjNd]){
                    dist[adjNd] = distTillNow + wt;
                    pq.push({dist[adjNd], adjNd});
                }
            }
        }
        return dist;
    }
};