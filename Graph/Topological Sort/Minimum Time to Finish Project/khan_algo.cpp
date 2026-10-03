#include <bits/stdc++.h>
using namespace std;

// Time complexity :- O(V + E)  
// Space complexity :- O(V)

// Approach :- Topological Sort
// We can use Kahn's algorithm to find the minimum time to finish the project.
// We can use a queue to store the nodes with in-degree 0 and process them one by one.
// We can keep track of the finish time of each node and update the finish time of its adjacent nodes.
// Using topological sort, we can traverse the minimum inDegree nodes first and 
// keep updating the finish time of the adjacent nodes

//Link :- https://www.geeksforgeeks.org/problems/project-manager--141631/1

class Solution {
  public:
    int minTime(vector<int> &duration, vector<vector<int>> &dependencies) {
        int n = duration.size();
        
        vector<int> inDegree(n, 0);
        vector<vector<int>> graph(n);
        
        for(auto edge: dependencies){
            int u = edge[0];
            int v = edge[1];
            
            graph[u].push_back(v);
            inDegree[v] += 1;
        }
        
        queue<int> q;
        vector<int> finishTime(duration.begin(), duration.end());
        
        for(int i=0; i<n; ++i){
            if(inDegree[i] == 0){
                q.push(i);
            }
        }
        int res = 0;
        int visited = 0;
        
        while(!q.empty()){
            int node = q.front();
            q.pop();
            
            visited++;
            res = max(res, finishTime[node]);
            
            for(auto adjNd: graph[node]){
                finishTime[adjNd] = max(finishTime[adjNd], finishTime[node] + duration[adjNd]);
                    
                inDegree[adjNd] -= 1;
                if(inDegree[adjNd] == 0){
                    q.push(adjNd);
                }
            }
        }
            
        if(visited != n)
            return -1;
            
        return res;
    }
};