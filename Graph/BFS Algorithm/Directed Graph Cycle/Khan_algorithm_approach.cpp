#include<bits/stdc++.h>
using namespace std;

// Time complexity :- O(V+E)                 
// Space complexity :- O(V)              

// Approach :- 
// Using khan's algortihm we can detect the cycle 
// which taking out the node from queue count the number of nodes that came in the queue 
// If the count of nodes is equal to the number of nodes in graph that means cycle doesn't exist 
// otherwise cycle exist because some node that have cyclic dependency will never have inDegree equals to 0


// Links :- https://leetcode.com/problems/largest-divisible-subset/

class Solution {
  public:
    bool isCyclic(int V, vector<vector<int>> &edges) {
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
        int cnt = 0;
        
        while(!q.empty()){
            int nd = q.front();
            q.pop();
            cnt++;
            
            for(auto adjNd: graph[nd]){
                inDegree[adjNd] -= 1;
                if(inDegree[adjNd] == 0)
                    q.push(adjNd);
            }
        }
        return !(cnt == V);
    }
};