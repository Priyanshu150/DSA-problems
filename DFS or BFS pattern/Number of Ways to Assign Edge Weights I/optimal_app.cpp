#include<bits/stdc++.h>
using namespace std;

// Time complexity :- O(n+e + log(maxDepth))
// Space complexity :- O(n+e)

// Approach :- 
// instead of using a visited array, we can eliminate that logic and use a varible that track parent value 
// since it's a tree it does not have a cycle 
// for find the 2 ^ (maxDepth - 1) we can use binary exponentiation 
// rest all the logic remains same 


// Links :- https://leetcode.com/problems/number-of-ways-to-assign-edge-weights-i/description/

class Solution {
private:
    typedef long long ll;

    ll mod = 1e9 + 7;

    ll binaryExpo(int base, int expo){
        // base case 
        if(expo == 0)
            return 1;
        
        // find the half power value 
        ll half = binaryExpo(base, expo / 2);
        ll val = (half * half) % mod;

        if(expo % 2){
            val = (val*base) % mod;
        }
        return val;
    }

    int dfs(int node,  unordered_map<int, vector<int>> &graph, int parent){
        int maxHeight = 0;

        for(auto adjNd: graph[node]){
            // skip the parent node 
            if(parent == adjNd){
                continue;
            }
            // find the height of sub-tree 
            int height = dfs(adjNd, graph, node);
            // maintain the overall max height 
            maxHeight = max(maxHeight, 1 + height);
        }
        return maxHeight;
    }

public:
    int assignEdgeWeights(vector<vector<int>>& edges) {
        unordered_map<int, vector<int>> graph;

        // build the tree 
        for(auto edge: edges){
            int u = edge[0];
            int v = edge[1];
            // build the bi-directional edges 
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        // find the max depth of tree 
        int maxDepth = dfs(1, graph, -1);

        return binaryExpo(2, maxDepth-1);
    }
};