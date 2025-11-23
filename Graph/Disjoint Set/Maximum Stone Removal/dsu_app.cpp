#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(V)
// Space complexity :- O(V)

// Approach :- 
// All the (row, col) pair can be combined to form a component 
// number pair we can delete is (num_of_edge - num_of_comp)
// each row and col can be represented as nodes and can be combined using dsu
// we can use set to keep track of the total number of component 

// Link :- https://www.geeksforgeeks.org/problems/maximum-stone-removal-1662179442/1

class DisjointSet{
  private:
    int total_nodes;
    vector<int> rank, size, parent;

  public:
    DisjointSet(int n){
        total_nodes = n;
        rank.resize(n, 0);
        size.resize(n, 1);
        
        for(int i=0; i<n; ++i)
            parent.push_back(i);
    }
    
    
    int findParent(int node){
        // node is self parent 
        if(parent[node] == node)    
            return node;
        
        // path compression 
        return parent[node] = findParent(parent[node]);
    }
    
    void unionByRank(int u, int v){
        int ulp_u = findParent(u);
        int ulp_v = findParent(v);
        
        // both having same parent
        if(ulp_u == ulp_v)
            return;
        
        // both having same rank 
        if(rank[ulp_u] == rank[ulp_v]){
            rank[ulp_u] += 1;
            parent[ulp_v] = ulp_u;
        }
        // attach smaller rank node to the greater one 
        else if(rank[ulp_u] > rank[ulp_v]){
            parent[ulp_v] = ulp_u;
        }
        else{
            parent[ulp_u] = ulp_v;
        }
    }
    
     void unionBySize(int u, int v){
        int ulp_u = findParent(u);
        int ulp_v = findParent(v);
        
        // both having same parent
        if(ulp_u == ulp_v)
            return;
        
        // merge the node base on the size of components
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
    int maxRemove(vector<vector<int>>& stones) {
        int n = 0, m = 0, sz = stones.size();
        
        // count the number of row and column 
        for(auto stone: stones){
            int row = stone[0], col = stone[1];
            n = max(row, n);
            m = max(col, m);
        }
        
        DisjointSet graph(n+m+2);
        unordered_set<int> st;
        
        // build graph using disjoint set 
        for(auto stone: stones){
            int row = stone[0], col = n+stone[1]+1;
            graph.unionBySize(row, col);
            st.insert(row);
            st.insert(col);
        }
        
        int comp = 0;
        // count the number of components 
        for(auto it: st){
            if(graph.findParent(it) == it)
                comp++;
        }
        return sz-comp;
    }
};