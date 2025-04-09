#include<bits/stdc++.h>
using namespace std;

// Time complexity :- O(v*(v+e))          
// Space complexity :- O(v+e)              

// Approach :- 
// Try deleting every node and then check if the number of component increases 
// Dof this for every node and count the component with help of dfs


// Links :- https://www.geeksforgeeks.org/problems/articulation-point2616/1

class Solution {
  private:
    void dfs(int node, int blockedNode, vector<bool> &vis, vector<vector<int>> &graph){
        vis[node] = true;
        
        for(auto adjNd: graph[node]){
            if(adjNd == blockedNode)
                continue;
            else if(!vis[adjNd])
                dfs(adjNd, blockedNode, vis, graph);
        }
    }
 
  public:
    vector<int> articulationPoints(int V, vector<vector<int>>& edges) {
        // Code here
        vector<vector<int>> graph(V);
        
        for(auto edge: edges){
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        int comp = 0;
        vector<bool> vis(V, false);
        
        for(int i=0; i<V; ++i){
            if(!vis[i]){
                comp++;
                dfs(i, -1, vis, graph);   
            }
        }
        vector<int> ans;
        
        for(int nd=0; nd<V; ++nd){
            int comp1 = 0;
            vis = vector<bool> (V, false);
            
            for(int i=0; i<V; ++i){
                if(i == nd)
                    continue;
                else if(!vis[i]){
                    comp1++;
                    dfs(i, nd, vis, graph);
                }
            }
            if(comp1 > comp)    ans.push_back(nd);
        }
        if(ans.empty()) ans.push_back(-1);
        return ans;
    }
};