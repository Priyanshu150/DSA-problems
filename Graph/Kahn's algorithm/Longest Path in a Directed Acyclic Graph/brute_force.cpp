#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(2^V)
// Space complexity :- O(E)

// Approach :-  
// try exploring all direction from the graph and update the maximum path for every node 

// links :- https://www.geeksforgeeks.org/problems/longest-path-in-a-directed-acyclic-graph/1

class Solution {
  private:
    typedef pair<int,int> pii;
  
    void solve(int node, int dist, vector<int> &res, vector<pii> graph[]){
        res[node] = max(res[node], dist);
        
        for(auto adjNbr: graph[node]){
            int adjNd = adjNbr.first;
            int wt = adjNbr.second;
            
            solve(adjNd, dist + wt, res, graph);
        }
    }
  
  public:
    vector<int> maxDistance(int V, int src, vector<vector<int>> &edges) {
        vector<pii> graph[V];
        
        for(auto edge: edges){
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];
            
            graph[u].push_back({v, wt});
        }
        
        vector<int> res(V, INT_MIN);
        solve(src, 0, res, graph);
        return res;
    }
};