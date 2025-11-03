#include<bits/stdc++.h>
using namespace std;

//Time complexity :- O()
//Space complexity :- O()

// Approach :-
// All the nodes which are part of cycle or which leads to cycle will not be safe node 
// apart from that everyone can be safe nodes 
// Using dfs cycle detection technique we can mark vis & pathVis of the graph 
// which graph is not pathVis will be safe nodes 

//link :- 
// leetcode - https://leetcode.com/problems/find-eventual-safe-states/description/
// gfg - https://www.geeksforgeeks.org/problems/eventual-safe-states/1

class Solution {
  private:
    bool dfs(int node, vector<vector<int>> &graph, vector<bool> &vis, vector<bool> &pathVis){
        // mark the current node as visited and path visited 
        vis[node] = true;
        pathVis[node] = true;
        
        // traverse on the adj node of current node 
        for(auto adjNd: graph[node]){
            if(!vis[adjNd]){
                if(dfs(adjNd, graph, vis, pathVis))
                    return true;
            }
            else if(pathVis[adjNd])
                return true;
        }
        // backtrack pathVis as no loop found 
        pathVis[node] = false;
        return false;
    }
  
  public:
    vector<int> safeNodes(int V, vector<vector<int>>& edges) {
        // Code here
        vector<vector<int>> graph(V);
        
        // build graph
        for(auto edge: edges){
            int u = edge[0], v = edge[1];
            graph[u].push_back(v);
        }
        
        vector<bool> vis(V, false), pathVis(V, false);
        
        // cycle detection technique using dfs
        for(int i=0; i<V; ++i){
            if(!vis[i]){
                dfs(i, graph, vis, pathVis);
            }
        }
        
        vector<int> ans;
        // check which node where not part of loop
        for(int i=0; i<V; ++i){
            if(!pathVis[i]){
                ans.push_back(i);
            }
        }
        return ans;
    }
};