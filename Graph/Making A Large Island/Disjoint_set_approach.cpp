#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(n*n)
// Space complexity :- O(n*n)

// Approach :- 
// Consider every element of matrix as a node
// Traverse on matrix and for the cell which has value as 1 check it neighbouring cells if the are also 1
// merge those cell into one component using Disjoint set
// Once component formation is done, check whether there is any zero of not in the cell if not then max size will be n*n
// If zeros exit, then again traverse on the each cell and this time look for zeros
// Once you get a zero cell try converting this 0 to 1 and find neighbouring cell which are 1 
// And what are size of unique component that exist in neighbour
// Try converting every zero in the same way and keep and ans stored which stores maximum component size
// Use hash set to keep track of unique component around zero.

//Link :- https://leetcode.com/problems/making-a-large-island/description/

class DisjointSet{
  private:
    vector<int> parent, size;

  public:
    DisjointSet(int node){
        parent.resize(node);
        size.resize(node, 1);

        for(int i=0; i<node; ++i)
            parent[i] = i;
    }

    int findParent(int node){
        if(node == parent[node])
            return node;
        
        return parent[node] = findParent(parent[node]);
    }

    int findSize(int node){
        return size[node];
    }

    void unionBySize(int u, int v){
        int ulp_u = findParent(u);
        int ulp_v = findParent(v);

        if(ulp_u == ulp_v)
            return;
        
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
private:
    bool isValid(int row, int col, int &n){
        return (row>=0 && row<n && col>=0 && col<n);
    }

    int nodeNumber(int row, int col, int &n){
        return (row*n + col);
    }

public:
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size(), zero = 0, res = 0;
        DisjointSet graph(n*n);
        vector<int> dir = {0, 1, 0, -1, 0};

        for(int row=0; row<n; ++row){
            for(int col=0; col<n; ++col){
                if(grid[row][col]){
                    for(int i=0; i<4; ++i){
                        int nr = row + dir[i], nc = col + dir[i+1];
                        if(isValid(nr, nc, n) && grid[nr][nc])
                            graph.unionBySize(nodeNumber(row, col, n), nodeNumber(nr, nc, n));
                    }
                }else    zero++;
            }
        }
        if(zero == 0)   return n*n;

        for(int row=0; row<n; ++row){
            for(int col=0; col<n; ++col){
                if(!grid[row][col]){
                    unordered_set<int> st;
                    for(int i=0; i<4; ++i){
                        int nr = row + dir[i], nc = col + dir[i+1];
                        if(isValid(nr, nc, n) && grid[nr][nc]){
                            int node = nodeNumber(nr, nc, n);
                            st.insert(graph.findParent(node));
                        }
                    }
                    int sizeOfComponent = 0;
                    for(auto nd: st)
                        sizeOfComponent += graph.findSize(nd);
                    
                    res = max(res, sizeOfComponent+1);
                }
            }
        }
        return res;
    }
};