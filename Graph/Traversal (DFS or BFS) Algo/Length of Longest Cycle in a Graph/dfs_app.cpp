#include<bits/stdc++.h>
using namespace std;

// Time Complexity: O(V+E)
// Space Complexity: O(V+V)

// Approach :- 
// use dfs to traverse the path 
// use path and path visited to keep track of nodes which are visited and visited in single path 
// use indexing method to count the length of loop 


// Link :- https://www.geeksforgeeks.org/problems/length-of-longest-cycle-in-a-graph/1

class Solution {
  private:
    int res = 0;
    vector<vector<int>> graph;
    
    void dfs(int node, int cnt, vector<bool> &vis, vector<int> &pathVis){
        // update the visited and pathVisited ds 
        vis[node] = true;
        pathVis[node] = cnt;
        
        // visited the adjacent node of current node 
        for(auto adjNd: graph[node]){
            // check if adjacent node is visited or not 
            if(!vis[adjNd]){
                dfs(adjNd, cnt+1, vis, pathVis);
            }
            // if node is visited check if it's path visited or not 
            else if(pathVis[adjNd] != 0){
                // keep track of maximum length using indexing 
                res = max(res, pathVis[node] - pathVis[adjNd] + 1);
            }
        }
        pathVis[node] = 0;
    }
  
  public:
    int longestCycle(int V, vector<vector<int>>& edges) {
        graph.resize(V);
        
        // build the graph 
        for(auto edge: edges){
            int u = edge[0], v = edge[1];
            
            graph[u].push_back(v);
        }
        // use vis & pathVis to track visited and path visited nodes 
        vector<bool> vis(V, false);
        vector<int> pathVis(V, 0);
        
        // standard dfs 
        for(int i=0; i<V; ++i){
            // check if node is not visited 
            if(!vis[i]){
                dfs(i, 1, vis, pathVis);
            }
        }
        // check if cycle is present or not 
        return (res == 0) ? -1 : res;
    }
};
