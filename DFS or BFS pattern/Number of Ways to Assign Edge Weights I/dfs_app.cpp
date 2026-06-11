#include<bits/stdc++.h>
using namespace std;

// Time complexity :- O(n+e + spaces)
// Space complexity :- O(n+e)

// Approach :- 
// Depth‑First Search (DFS) to compute the depth of each node from the root
// Find the maximum depth, max_depth
// The number of 2s doesn’t affect parity; we only need an odd number of 1s along the path
// The number of ways to choose an odd count of 1s among max_depth edges is 2^(max_depth-1)


// Links :- https://leetcode.com/problems/number-of-ways-to-assign-edge-weights-i/description/

class Solution {
private:
    int dfs(int node, vector<int> graph[], vector<bool> &vis){
        // mark current node as visited 
        vis[node] = true;       
        int maxHeight = 0;

        for(auto adjNd: graph[node]){
            // if adj node is not visited 
            if(!vis[adjNd]){
                // find the height of the subtree 
                int height = dfs(adjNd, graph, vis);
                // update the max height 
                maxHeight = max(maxHeight, 1 + height);
            }
        }
        return maxHeight;
    }

public:
    int assignEdgeWeights(vector<vector<int>>& edges) {
        int n = edges.size() + 2;
        int mod = 1e9 + 7;
        vector<int> graph[n];

        // build tree 
        for(auto edge: edges){
            int u = edge[0];
            int v = edge[1];
            // undirected - graph
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        vector<bool> vis(n, false);
        // find max height of tree using dfs algo 
        int maxHeight = dfs(1, graph, vis);

        int res = 1;
        while(maxHeight > 1){
            res = (res << 1) % mod;
            maxHeight -= 1;
        }
        return res;
    }
};