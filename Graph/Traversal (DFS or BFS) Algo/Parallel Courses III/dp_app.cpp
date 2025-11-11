#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(v+e)
// Space complexity :- O(v)

// Approach :-  
// start a dfs traversal from every node to end 
// maintain maximum time along all the path 
// store the value in 1-d dp array in order to again calculate the same node/path value 

// Link :- https://leetcode.com/problems/parallel-courses-iii/

class Solution {
private:
    int dfs(int node, vector<vector<int>> &graph, vector<int>& time, vector<int> &dp){
        int timeTake = 0;

        if(dp[node] != -1)
            return dp[node];

        // traverse on adjacent node 
        for(auto adjNd: graph[node]){
            timeTake = max(timeTake, dfs(adjNd, graph, time, dp));
        }
        // totatl time taken 
        return dp[node] = timeTake + time[node-1];
    }

public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        vector<int> inDegree(n+1, 0);
        vector<vector<int>> graph(n+1);

        for(auto relation: relations){
            int u = relation[0], v = relation[1];
            // build graph
            graph[u].push_back(v);
        }
        int res = 0;
        vector<int> dp(n+1, -1);

        for(int i=1; i<=n; ++i){
            //apply dfs
            int timeTaken = dfs(i, graph, time, dp);
            res = max(res, timeTaken);
        }
        return res;
    }
};