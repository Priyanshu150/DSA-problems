#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(exponential)
// Space complexity :- O(v+e)

// Approach :- 
// Try on exploring all path and count the number of times we reach destination

// Link :- https://www.geeksforgeeks.org/problems/count-the-paths4332/1

class Solution {
  private:
    int solve(int node, int dest, vector<vector<int>> &graph, vector<int> &dp){
        if(node == dest)
            return 1;
        if(dp[node] != 0)
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

class Solution {
  public:
    int countPaths(vector<vector<int>>& edges, int V, int src, int dest) {
        // Code here
        vector<vector<int>> graph(V);
        
        for(auto edge: edges){
            graph[edge[0]].push_back(edge[1]);
        }
        
        queue<int> q;
        q.push(src);
        int res = 0;
        
        while(!q.empty()){
            int node = q.front();
            q.pop();
            
            if(node == dest)
                res += 1;
            
            for(auto adjNd: graph[node]){
               q.push(adjNd);
            }
        }
        return res;
    }
};