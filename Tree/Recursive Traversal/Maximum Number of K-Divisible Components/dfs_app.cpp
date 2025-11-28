#include<bits/stdc++.h>
using namespace std;

// Time complextiy :- O(N+E)
// Space complexity :- O(N+E)

// Approach :-   
// for every child node of the tree we'll check if they are divisible by k or not 
// if they are then we're broke the edge and make a new component otherwise we leave it 
// and add child sum to the current component itself 

//Link :- https://leetcode.com/problems/maximum-number-of-k-divisible-components/description/

class Solution {
private:
    int dfs(int node, vector<vector<int>> &graph, vector<bool> &vis, vector<int> &values, int &res, int &k){
        // mark node as visited
        vis[node] = true;
        int sum = values[node];
        
        // traverse on adjacent nodes
        for(int adjNd: graph[node]){
            if(!vis[adjNd]){
                // find the each child of sum 
                int childSum = dfs(adjNd, graph, vis, values, res, k) % k;
                if(childSum == 0){
                    res++;
                }else{
                    sum = (sum + childSum) % k;
                }
            }
        }
        return sum;
    }

public:
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        vector<vector<int>> graph(n);

        // build graph
        for(auto edge: edges){
            int u = edge[0], v = edge[1];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        int res = 0;
        // standard dfs
        vector<bool> vis(n, false);
        dfs(0, graph, vis, values, res, k);

        return res+1;
    }
};