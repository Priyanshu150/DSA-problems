#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(v+e)
// Space complexity :- O(v+e)

// Approach :-   
// Since it's a undirected graph then only different component we've to connect 
// that way we'll connect the complete graph 
// We've to re-use the edge that means toatal number of edges should be greater or equal to V-1
// hence the final answer will be number_of_component-1 


// Link :- https://www.geeksforgeeks.org/problems/minimize-connections/1

class Solution {
  private:
    void dfs(int node, vector<bool> &vis, vector<vector<int>> &graph){
        vis[node] = true;
        
        for(auto adjNd: graph[node]){
            if(!vis[adjNd]){
                dfs(adjNd, vis, graph);
            }
        }
    }
  
  public:
    int minConnect(int V, vector<vector<int>>& edges) {
        int sz = edges.size();
        // number of edge is less than v-1, then it's not possible
        if(sz < V-1)        
            return -1;
        
        vector<vector<int>> graph(V);
        
        // build graph 
        for(auto edge: edges){
            int u = edge[0], v = edge[1];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        
        int compCnt = 0;
        vector<bool> vis(V, false);
        
        // standard dfs
        for(int i=0; i<V; ++i){
            if(!vis[i]){
                // count the number of component 
                compCnt++;
                dfs(i, vis, graph);
            }
        }
        return compCnt-1;
    }
};

