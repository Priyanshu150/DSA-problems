#include<bits/stdc++.h>
using namespace std;

// Time complextiy :- O((v+e)*log(v+e))
// Space complexity :- O(v)

// Approach :-
// we'll use dijistra's algorithm to find the shortest path
// the number of ways to reach at a particular node will be 
// sum of all the ways of node from which we can reach this node 

// Link :- https://www.geeksforgeeks.org/problems/number-of-ways-to-arrive-at-destination/1

class Solution {
  private:
    typedef pair<int,int> pii;
  
  public:
    int countPaths(int V, vector<vector<int>>& edges) {
        vector<vector<pii>> graph(V);
        
        // build graph
        for(auto edge: edges){
            int u = edge[0], v = edge[1], wt = edge[2];
            
            graph[u].push_back({v, wt});
            graph[v].push_back({u, wt});
        }
        
        priority_queue<pii, vector<pii>, greater<pii>> pq;
        vector<int> dist(V, INT_MAX), ways(V, 0);
        
        pq.push({0, 0});
        ways[0] = 1;
        dist[0] = 0;
        
        // dijistra's algo
        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            
            int node = it.second;
            int distTillNow = it.first;
            
            // traverse on nbr node
            for(auto nbr: graph[node]){
                int adjNd = nbr.first;
                int wt = nbr.second;
                
                // curr distance is smaller than previous one 
                if(wt + distTillNow < dist[adjNd]){
                    dist[adjNd] = wt + distTillNow;
                    ways[adjNd] = ways[node];
                    pq.push({dist[adjNd], adjNd});
                }
                // curr distance is equal to previous one 
                else if(wt + distTillNow == dist[adjNd]){
                    ways[adjNd] += ways[node];
                }
            }
        }
        return ways[V-1];
    }
};