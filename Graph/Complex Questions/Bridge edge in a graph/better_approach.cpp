#include<bits/stdc++.h>
using namespace std;

// Time complexity :- O(v+e)
// Space complexity :- O(v+e)              

// Approach :- 
// Create the ajacency list with adding the edge (c to d)
// count the number of components (comp1)
// Add edge (c to d), then again count the components (comp2)
// if the diff comp1 > comp2, the the edge is a bridge


// Links :- https://www.geeksforgeeks.org/problems/bridge-edge-in-graph/1

class Solution {
  private:
    bool isSame(int u, int v, int c, int d){
        return (u == c && v == d) || (u == d && v == c);
    }
    
    void dfs(int node, vector<bool> &vis, vector<vector<int>> &graph){
        vis[node] = true;
        
        for(auto adjNd: graph[node]){
            if(!vis[adjNd])
                dfs(adjNd, vis, graph);
        }
    }
  
  public:
    bool isBridge(int V, vector<vector<int>> &edges, int c, int d) {
        // Code here
        vector<vector<int>> graph(V);
        
        for(auto edge: edges){
            if(isSame(edge[0], edge[1], c, d))
                continue;
            
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        
        int comp1 = 0, comp2 = 0;
        vector<bool> vis(V, false);
        
        for(int i=0; i<V; ++i){
            if(!vis[i]){
                comp1++;
                dfs(i, vis, graph);
            }
        }
        
        for(int i=0; i<V; ++i)
            vis[i] = false;
        
        graph[c].push_back(d);
        graph[d].push_back(c);
        
        for(int i=0; i<V; ++i){
            if(!vis[i]){
                comp2++;
                dfs(i, vis, graph);
            }
        }
        return (comp1-comp2 == 1);
    }
};