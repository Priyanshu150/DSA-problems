#include<bits/stdc++.h>
using namespace std;

// Time complexity :- O(V+#)                 
// Space complexity :- O(V+E)                  

// Approach :-
// make adjacency list based on the edge provided
// apply cycle detection using dfs approach, if cycle found the return true
// repeat this for all the component in the graph
// after trying all these if cycle not detected then return false denoting no cycle exists


// Links :- https://www.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1

class Solution {
  private:
    bool dfs(int node, int par, vector<bool> &vis, vector<vector<int>> &graph){
        vis[node] = true;
        
        for(auto adjNd: graph[node]){
            if(!vis[adjNd]){
                if(dfs(adjNd, node, vis, graph))   
                    return true;
            }
            else if(adjNd != par)   
                return true;
        }
        return false;
    }
  
  public:
    bool isCycle(int V, vector<vector<int>>& edges) {
        // Code here
        vector<vector<int>> graph(V);
        vector<bool> vis(V, false);
        
        for(auto edge: edges){
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        
        for(int i=0; i<V; ++i){
            if(!vis[i] && dfs(i, -1, vis, graph))
                return true;
        }
        return false;
    }
};