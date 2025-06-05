#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(v+e)
// Space complexity :- O(v+e)

// Approach :- 
// Optimizing the brute force solution by adding 1-d dp 
// saving the previously computed state in the array 

// Link :- https://www.geeksforgeeks.org/problems/count-the-paths4332/1

class Solution {
  private:
    int solve(int node, int dest, vector<vector<int>> &graph, vector<int> &dp){
        if(node == dest)
            return 1;
        if(dp[node] != 0
        )
            return dp[node];
        
        int ways = 0;
        for(auto adjNd: graph[node]){
            ways += solve(adjNd, dest, graph, dp);
        }
        return dp[node] = ways;
    }
    
  public:
    int countPaths(vector<vector<int>>& edges, int V, int src, int dest) {
        // Code here
        vector<vector<int>> graph(V);
        
        for(auto edge: edges){
            graph[edge[0]].push_back(edge[1]);
        }
        vector<int> dp(V, 0);
       return solve(src, dest, graph, dp);
    }
};



