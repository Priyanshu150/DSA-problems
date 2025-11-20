#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(V*E)
// Space complexity :- O(V)

// Approach :-   
// For find the least distacne we can use Dijistra's algorithm but when -ve edge / cycle exist in graph then use bellman-ford
// In this algorithm, we've to realax the edges for n-1 times 
// every we've to traverse on each edge and try to minimize each distance 
// If after n-1, we're still able to minimize it that means it contains negative edge cylce 

// Why only n-1 ?
// since in a graph of N nodes, in worst case, you will take N-1 edges to reach from the first to last,
// thereby we iterate for N-1 iterations.
// Try drawing a graph which takes more than N-1 edges for any path, it is not possible


// Link :- https://www.geeksforgeeks.org/problems/distance-from-the-source-bellman-ford-algorithm/1

class Solution {
  public:
    vector<int> bellmanFord(int V, vector<vector<int>>& edges, int src) {
        // Code here
        vector<int> dist(V, 1e8);
        dist[src] = 0;
        
        for(int i=0; i<=V; ++i){
            for(auto edge: edges){
                int u = edge[0], v = edge[1], wt = edge[2];
                
                if(dist[u] != 1e8 && dist[u] + wt < dist[v]){
                    if(i == V)      return {-1};
                    dist[v] = dist[u] + wt;
                }
            }
        }
        return dist;
    }
};