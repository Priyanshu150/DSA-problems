#include<bits/stdc++.h>
using namespace std;

// Time Complexity: O(V+E)
// Space Complexity: O(V)

// Approach :- 
// leave node will give the maximum height, hence we need to find the middle node 
// at max 1 or 2 nodes can be our answer due to the property 
// we'll start level order traversal from leaf and use inDegree 
// we'll decrement the size of graph by removing the leave nodes and making it smaller 
// untill only 1 or 2 node is left which will be our answer 

// Link :- https://www.geeksforgeeks.org/problems/minimum-height-roots/1

class Solution {
  public:
    vector<int> minHeightRoot(int V, vector<vector<int>>& edges) {
        vector<int> graph[V], inDegree(V, 0);
        
        for(auto edge: edges){
            int u = edge[0], v = edge[1];
            // build a un-directed graph
            graph[u].push_back(v);
            graph[v].push_back(u);
            
            // count the indegree 
            inDegree[u] += 1;
            inDegree[v] += 1;
        }
        
        queue<int> q;
        
        for(int i=0; i<V; ++i){
            // add leaves node into queue 
            if(inDegree[i] == 1){
                q.push(i);
            }
        }
        vector<int> res;
        
        // multisource bfs or level order traversal 
        while(!q.empty()){
            int sz = q.size();
            res.clear();
            
            while(sz-- > 0){
                int node = q.front();
                q.pop();
                
                res.push_back(node);
                
                // traverse on adjacent node 
                for(auto adjNd: graph[node]){
                    // relax the edge 
                    inDegree[adjNd] -= 1;
                    // add the next set of leaves node
                    if(inDegree[adjNd] == 1){
                        q.push(adjNd);
                    }
                }
            }
        }
        return res;
    }
};