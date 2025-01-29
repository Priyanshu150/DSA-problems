#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(N)
// Space complexity :- O(3*N)

//Approach :- 
// Use dijoint set for making component out of edge
// Make component from each each edge 
// At any point when we  found the edge is already part of component then that edge will be redundant one

//Link :- https://leetcode.com/problems/redundant-connection/description/

class DisjointSet{
  private:
    vector<int> parent, rank, size;
  
  public:
    DisjointSet(int n){
        parent.resize(n);
        rank.resize(n, 0);
        size.resize(n, 1);

        for(int i=0; i<n; ++i)
            parent[i] = i;
    }

    int findParent(int node){
        if(parent[node] == node)
            return node;
        
        return parent[node] = findParent(parent[node]);
    }
    
    void unionByRank(int u, int v){
        int ulp_u = findParent(u);
        int ulp_v = findParent(v);

        if(ulp_u == ulp_v)      return;
        if(rank[ulp_u] == rank[ulp_v]){
            parent[ulp_v] = ulp_u;
            rank[ulp_u] += 1;
        }
        else if(rank[ulp_u] < rank[ulp_v]) 
            parent[ulp_u] = ulp_v;
        else
            parent[ulp_v] = ulp_u;
    }

    void unionBySize(int u, int v){
        int ulp_u = findParent(u);
        int ulp_v = findParent(v);

        if(ulp_u == ulp_v)      return;
        if(size[ulp_v] <= size[ulp_u]){
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
        else{
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
    }
};

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        DisjointSet graph(n+1);

        for(int i=0; i<n; ++i){
            int u = edges[i][0], v = edges[i][1];
            if(graph.findParent(u) == graph.findParent(v))
                return edges[i];
            
            // graph.unionByRank(u, v);
            graph.unionBySize(u, v);
        }
        return {};
    }
};


