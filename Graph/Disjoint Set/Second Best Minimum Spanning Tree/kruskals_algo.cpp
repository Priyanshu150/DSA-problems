#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(E*log(E) + (V+E) + E*(V+E))
// Space complexity :- O(E + (E+V))

// Approach :-   
// we'll find the min MST value using krushkal algo and save the edge used in making that 
// remove each edge one by one from MST tree and find new MST value 
// record the second largest MST value that will be our answer 

//Link :- https://www.geeksforgeeks.org/problems/second-best-minimum-spanning-tree/1

class DisjointSet{
  private:
    vector<int> parent, rank;
    
  public:
    DisjointSet(int numOfNode){
        parent.resize(numOfNode+1);
        rank.resize(numOfNode+1, 0);
        
        for(int i=0; i<=numOfNode; ++i)
            parent[i] = i;
    }
    
    int findParent(int node){
        if(node == parent[node])
            return node;
        
        return parent[node] = findParent(parent[node]);
    }
    
    bool unionByRank(int u, int v){
        int ulpU = findParent(u);
        int ulpV = findParent(v);
        
        if(ulpU == ulpV)
            return false;
        
        if(rank[ulpU] > rank[ulpV]){
            parent[ulpV] = ulpU;
        }
        else if(rank[ulpV] > rank[ulpU]){
            parent[ulpU] = ulpV;
        }
        else{
            rank[ulpU] += 1;
            parent[ulpV] = ulpU;
        }
        return true;
    }
};

class Solution {
  private:
    int krushkal(int V, vector<vector<int>> &edges, int skipU, int skipV){
        int sz = edges.size(), cost = 0;
        DisjointSet graph(V);
        
        for(auto edge: edges){
            int u = edge[0], v = edge[1], wt = edge[2];
            
            // ignore the chosen MST edge 
            if((u == skipU && v == skipV) || (u == skipV && v == skipU))
                continue;
            
            // merge u,v 
            if(graph.unionByRank(u, v)){
                cost += wt;
            }
        }
        return cost;
    }
  
  public:
    int secondMST(int V, vector<vector<int>> &edges) {
        int n = edges.size();
        // number of edge is less than v-1 then it's not possible 
        if(n < V)
            return -1;
        
        // sort the edge based on weight
        sort(edges.begin(), edges.end(), [&](vector<int> &edge1, vector<int> &edge2){
            return edge1[2] < edge2[2];
        });
        
        DisjointSet dsu(V);
        vector<pair<int,int>> mstEdges;
        int minMSTVal = 0, secondMinMstVal = INT_MAX;
        
        // find the minimum MST value using krushkal's 
        for(auto edge: edges){
            int u = edge[0], v = edge[1], wt = edge[2];
            
            // merge u,v 
            if(dsu.unionByRank(u, v)){
                minMSTVal += wt;
                mstEdges.push_back({u, v});
            }
        }
        
        for(auto &edge: mstEdges){
            int u = edge.first, v = edge.second;
            // find new cost of MST after removing edge
            int newCost = krushkal(n, edges, u, v);
            
            if(newCost > minMSTVal && newCost < secondMinMstVal)
                secondMinMstVal = newCost;
        }
        return secondMinMstVal == INT_MAX ? -1 : secondMinMstVal;
    }
};
