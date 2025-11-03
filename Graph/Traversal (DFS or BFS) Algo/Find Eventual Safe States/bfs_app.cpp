#include<bits/stdc++.h>
using namespace std;

//Time complexity :- O(V+E)
//Space complexity :- O(V)

// Approach :-
// Instead of following the mentioned approach from the question 
// reverse the graph given and apply the kahns algorithm 

//link :- 
// leetcode - https://leetcode.com/problems/find-eventual-safe-states/description/
// gfg - https://www.geeksforgeeks.org/problems/eventual-safe-states/1

class Solution {
  public:
    vector<int> safeNodes(int V, vector<vector<int>>& edges) {
        // Code here
        vector<int> inDegree(V, 0);
        vector<vector<int>> graph(V);
        
        // create reverse graph
        for(auto edge: edges){
            int u = edge[0], v = edge[1];
            graph[v].push_back(u);
            inDegree[u] += 1;
        }
        
        queue<int> q;
        // push those node into the queue having indegree edge = 0
        for(int i=0; i<V; ++i){
            if(inDegree[i] == 0)
                q.push(i);
        }
        vector<int> ans;
        // kahn's algorithm using bfs
        while(!q.empty()){
            int node = q.front();
            q.pop();
            
            ans.push_back(node);
        
            // deleting the edge hence inDegre to adjNd decreases
            for(auto adjNd: graph[node]){
                inDegree[adjNd] -= 1;
                if(inDegree[adjNd] == 0)
                    q.push(adjNd);
            }
        }
        return ans;
    }
};