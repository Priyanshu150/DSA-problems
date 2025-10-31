#include<bits/stdc++.h>
using namespace std;

// Time Complexity: O(v*(v+e))
// Space Complexity: O(v)

// Approach :- 
// to find the shortest cycle in the graph we can use bfs to traverse the graph 
// for each node we'll traverse on the graph and try to find a cycle 
// if a node if already visited then it's as cycle 
// we'll use distance approach, to update distance of each node
// for every adjacent node of current node if it's visited 
// and dist[adjNd] >= dist[curr_node], then via some other path we already visited that 
// then calculate the distance of loop i.e. dist[adjNd] + dist[curr_node] + 1 (edge b/w them)
// if dist[adjNd] < dist[curr_node], that mean it's visited but it's curr_node parent 
// keep track of shortest distance in a variable 

// Link :- https://www.geeksforgeeks.org/problems/shortest-cycle/1

class Solution {
  public:
    int shortCycle(int V, vector<vector<int>>& edges) {
        // Code here
        vector<vector<int>> graph(V);
        
        for(auto edge: edges){
            int u = edge[0], v = edge[1];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        int shortest = INT_MAX;
        
        for(int start=0; start<V; ++start){
            queue<int> q;
            vector<int> dist(V, -1);
            
            q.push(start);
            dist[start] = 0;
            
            while(!q.empty()){
                int node = q.front();
                q.pop();
                
                for(auto adjNd: graph[node]){
                    if(dist[adjNd] == -1){
                        q.push(adjNd);
                        dist[adjNd] = dist[node] + 1;
                    }
                    else if(dist[adjNd] >= dist[node]){
                        shortest = min(shortest, dist[adjNd] + dist[node] + 1);
                    }
                }
            }
        }
        return (shortest == INT_MAX) ? -1 : shortest;
    }
};

