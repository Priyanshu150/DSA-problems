#include<bits/stdc++.h>
using namespace std;

// Time Complexity: O(V+E)
// Space Complexity: O(V)

// Approach :- 
// for find the diameter of graph use the same concept as of tree 
// maintain a variable for diameter 
// for any node, find the two path having highest depth
// diameter will be max of these two nodes 
// and return the maximum among them to the parent node which is calling the current node 


// Link :- https://www.geeksforgeeks.org/problems/diameter-of-a-graph/1

class Solution {
  private:
    int dfs(int node, vector<int> &vis, vector<vector<int>> &graph, int &res){
        // mark the current node as visited
        vis[node] = true;
        int maxi = 0, maxi2 = 0;
        
        // traverse on the adjNd is not visited
        for(auto adjNd : graph[node]){
            if(!vis[adjNd]){
                int val = 1 + dfs(adjNd, vis, graph, res);
                if(val > maxi){
                    maxi2 = maxi;
                    maxi = val;
                }
                else 
                    maxi2 = max(maxi2, val);
            }
        }
        res = max(res, maxi + maxi2);
        return maxi;
    }
  
  public:
    int diameter(int V, vector<vector<int>>& edges) {
        // Code here
        vector<vector<int>> graph(V);
        // build the graph 
        for(auto edge: edges){
            int u = edge[0], v = edge[1];
            
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        int res = 0;
        vector<int> vis(V, false);
        
        // apply dfs to find distance among nodes
        for(int nd=0; nd<V; ++nd){
            if(!vis[nd]){
                dfs(nd, vis, graph, res);
            }
        }
        return res;
    }
};

