#include<bits/stdc++.h>
using namespace std;

// Time complexity :- O(v+e)
// Space complexity :- O(v+e)              

// Approach :- 
// build a graph skipping the edge from (c - d)
// apply dfs from node c, if d get visited then it's not a bridge otherwise it's a bridge 


// Links :- https://www.geeksforgeeks.org/problems/bridge-edge-in-graph/1


class Solution {
  private:
    bool isSame(int u, int v, int c, int d){
        return (u == c && v == d) || (u == d && v == c);
    }
    
    void dfs(int node, vector<bool> &vis, vector<vector<int>> &graph){
        // mark current node as visited 
        vis[node] = true;
        
        // visit the adjacent node of current node 
        for(auto adjNd: graph[node]){
            // if they're not visited 
            if(!vis[adjNd])
                dfs(adjNd, vis, graph);
        }
    }
  
  public:
    bool isBridge(int V, vector<vector<int>> &edges, int c, int d) {
        vector<vector<int>> graph(V);
        

        for(auto edge: edges){
            // skip (c - d) edge 
            if(isSame(edge[0], edge[1], c, d))
                continue;
            
            // build a undirected graph 
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        
        vector<bool> vis(V, false);
        
        // apply dfs from node c 
        dfs(c, vis, graph);
        // node d is visited then it's not a bridge otherwise it is 
        return !vis[d];
    }
};