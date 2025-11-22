#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O((V+E)logV)
// Space complexity :- O(V+E)

// Approach :- 
// use standard dijistra's algo with slight modification 
// instead of using a 1d array use 2d to keep track of distance 
// maintains min & second min distance in array using dijistras algo

// Link :- https://www.geeksforgeeks.org/problems/shortest-path-using-atmost-one-curved-edge--170647/1

class Solution {
  public:
    int shortestPath(int V, int a, int b, vector<vector<int>> &edges) {
        vector<vector<tuple<int,int,int>>> graph(V);
        
        // build graph: tuple = {neighbor, normal_weight, curved_weight}
        for (auto& edge : edges) {
            int u = edge[0], v = edge[1], w1 = edge[2], w2 = edge[3];
            graph[u].push_back({v, w1, w2});
            graph[v].push_back({u, w1, w2});
        }
        
        // dist[node][taken] = shortest distance to node; taken=0 if curved edge unused, 1 if used
        vector<vector<int>> dist(V, vector<int>(2, INT_MAX));
        
        // priority queue of tuples: {distance, node, taken}
        priority_queue<tuple<int,int,int>, vector<tuple<int,int,int>>, greater<tuple<int,int,int>>> pq;
        
        dist[a][0] = 0;
        pq.emplace(0, a, 0);
        
        while (!pq.empty()) {
            auto [distTillNow, node, taken] = pq.top();
            pq.pop();
            
            // If this state is already outdated, skip
            if (distTillNow > dist[node][taken])
                continue;
            
            if (node == b) return distTillNow;
            
            // Relax neighbors
            for (auto& nbr : graph[node]) {
                int adjNd, w1, w2;
                tie(adjNd, w1, w2) = nbr;
                
                // Take normal edge
                if (distTillNow + w1 < dist[adjNd][taken]) {
                    dist[adjNd][taken] = distTillNow + w1;
                    pq.emplace(dist[adjNd][taken], adjNd, taken);
                }
                
                // Take curved edge if not taken yet
                if (taken == 0 && distTillNow + w2 < dist[adjNd][1]) {
                    dist[adjNd][1] = distTillNow + w2;
                    pq.emplace(dist[adjNd][1], adjNd, 1);
                }
            }
        }
        
        return -1;  // If unreachable
    }
};