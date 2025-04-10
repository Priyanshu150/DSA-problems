#include<bits/stdc++.h>
using namespace std;

// Time complexity :- O(n*n*log(n))
// Space complexity :- O(n*n)              

// Approach :- 
// we can use disjoint set to solve this problem, each house can be considered as a node
// we'll make a weighted edge graph where wieght will be distance b/w two houses
// keep the nodes in the above format in array {wt, u, v}
// sort the array, and apply disjoint set on the same 
// Traverse on the sorted array, take u & v, if the not connected connect them and consider the weight


// Links :- https://www.geeksforgeeks.org/problems/minimum-cost-to-connect-all-houses-in-a-city/1

class DisjointSet{
  private:
    vector<int> parent, rank;
 
  public:
    DisjointSet(int node){
        parent.resize(node+1);
        rank.resize(node+1, 0);
        
        for(int i=0; i<=node; ++i)
            parent[i] = i;
    }
    
    int findParent(int node){
        if(parent[node] == node)
            return node;
        
        return parent[node] = findParent(parent[node]);
    }
    
    bool unionByRank(int u, int v){
        int ulp_u = findParent(u);
        int ulp_v = findParent(v);
        
        if(ulp_u == ulp_v)  
            return false;
        
        if(rank[ulp_u] == rank[ulp_v]){
            parent[ulp_u] = ulp_v;
            rank[ulp_v] += 1;
        }
        else if(rank[ulp_u] > rank[ulp_v])
            parent[ulp_v] = ulp_u;
        else 
            parent[ulp_u] = ulp_v;
        
        return true;
    }
};

class Solution {
  public:
    int minCost(vector<vector<int>>& houses) {
        // code here
        int n = houses.size(), res = 0;
        vector<vector<int>> graph;
        
        for(int i=0; i<n-1; ++i){
            for(int j=i+1; j<n; ++j){
                int dist = abs(houses[i][0] - houses[j][0]) + abs(houses[i][1] - houses[j][1]);
                graph.push_back({dist, i, j});
            }
        }
        sort(graph.begin(), graph.end());
        DisjointSet dsu(n);
        
        for(auto edge: graph){
            int wt = edge[0], u = edge[1], v = edge[2];
            
            if(dsu.unionByRank(u, v))
                res += wt;
        }
        return res;
    }
};