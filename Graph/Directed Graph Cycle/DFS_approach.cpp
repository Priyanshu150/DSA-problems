#include<bits/stdc++.h>
using namespace std;

// Time complexity :- O(V+E)                 
// Space complexity :- O(V)              

// Approach :- 
// we can use dfs approach to check wheather the give DAG has cycle or not 
// we can use 2 vis array, one track which node are visited till now
// other tracks which node are vis in current path traversal 
// traversing the adjcant node, If we find them already vis in current path then there exist a cycle


// Links :- https://leetcode.com/problems/largest-divisible-subset/

class Solution {
  private:
    bool dfs(int node, vector<bool> &vis, vector<bool> &pathVis, vector<vector<int>> & graph){
        vis[node] = true;
        pathVis[node] = true;
        
        for(auto adjNd: graph[node]){
            if(!vis[adjNd]){
                if(dfs(adjNd, vis, pathVis, graph))
                    return true;
            }
            else if(pathVis[adjNd])
                return true;
        }
        pathVis[node] = false;
        return false;
    }
    
  public:
    bool isCyclic(int V, vector<vector<int>> &edges) {
        // code here
        vector<vector<int>> graph(V);
        vector<bool> vis(V, false), pathVis(V, false);
        
        for(auto edge: edges)
            graph[edge[0]].push_back(edge[1]);
        
        for(int i=0; i<V; ++i){
            if(!vis[i])
                if(dfs(i, vis, pathVis, graph))
                    return true;
        }
        return false;
    }
};