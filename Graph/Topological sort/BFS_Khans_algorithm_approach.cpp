#include<bits/stdc++.h>
using namespace std;

// Time complexity :- O(V+E)                 
// Space complexity :- O(V+V+E)              

// Approach :- 
// Apply khan's algorithm to calculate the topological sort
// count the indegree of each node and store in the array
// push the node into the queue which has 0 indegree
// traverse on the queue node, for each node traverse on adjacent node
// decrease the indegree of adjacent node and if indegree becomes 0 push it into queue
// while traverse the queue push all the node of queue parallely in answer array too


// Links :- https://www.geeksforgeeks.org/problems/topological-sort/1

class Solution {
  public:
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        // code here
        vector<vector<int>> graph(V);
        vector<int> inDegree(V, 0), ans;
        
        for(auto edge: edges){
            inDegree[edge[1]] += 1;
            graph[edge[0]].push_back(edge[1]);
        }
        queue<int> q;
        
        for(int i=0; i<V; ++i){
            if(inDegree[i] == 0)
                q.push(i);
        }
        
        while(!q.empty()){
            int nd = q.front();
            q.pop();
            
            ans.push_back(nd);
            
            for(auto adjNd: graph[nd]){
                inDegree[adjNd] -= 1;
                if(inDegree[adjNd] == 0)
                    q.push(adjNd);
            }
        }
        return ans;
    }
};