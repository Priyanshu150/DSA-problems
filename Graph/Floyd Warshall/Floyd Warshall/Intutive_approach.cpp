#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(V*V*V)
// Space complexity :- O(V*V*V)

// Approach :-   
// Try to find shortest node using every via every other node 
// for find shortest path from i to j, take path from i to k and then k to j
// similarly for all the combination of 0 to n-1


// Link :- https://www.geeksforgeeks.org/problems/implementing-floyd-warshall2042/1

class Solution {
  public:
    void floydWarshall(vector<vector<int>> &dist) {
        // Code here
        int n = dist.size();
        
        for(int k=0; k<n; ++k){
            for(int j=0; j<n; ++j){
                for(int i=0; i<n; ++i){
                    if(dist[i][k] == 1e8 || dist[k][j] == 1e8)
                        continue;
                    
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                    
                }
            }
        }
    }
};