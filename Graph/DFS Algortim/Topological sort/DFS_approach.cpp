#include<bits/stdc++.h>
using namespace std;

// Time complexity :- O(V+E)                 
// Space complexity :- O(V+V+E)                  

// Approach :- 
// create graph based on edge provided, make a visited array and maintain a stack
// Apply dfs on the graph 
// In dfs after traversing the adjacent node push the current node into the stack
// Atlast built the answer from the stack

// Links :- https://www.geeksforgeeks.org/problems/topological-sort/1

class Solution {
  private:
    void dfs(int node, vector<int> &vis, stack<int> &st, vector<vector<int>> &graph){
        vis[node] = 1;
        
        for(auto adjNd: graph[node]){
            if(!vis[adjNd])
                dfs(adjNd, vis, st, graph);
        }
        st.push(node);
    }
    
  public:
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        // code here
        vector<vector<int>> graph(V);
        vector<int> vis(V, 0), ans;
        stack<int> st;
        
        for(auto edge: edges)
            graph[edge[0]].push_back(edge[1]);
        
        for(int i=0; i<V; ++i){
            if(!vis[i])
                dfs(i, vis, st, graph);
        }
        
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        return ans;
    }
};