import java.util.*;

//Time complextiy :- O(V*E)
// Space complexity :- O(V)

// Approach :-  
// use bellmon for algo to find if negative cycle exist or not 
// initially mark node dist as 0 assuming a source attached to it with distance 0

// links :- https://www.geeksforgeeks.org/problems/negative-weight-cycle3504/1

class Solution {
    public boolean isNegativeWeightCycle(int V, int[][] edges) {
        boolean updated = false;
        int[] dist = new int[V];
        
        // relax the edge V-1 times 
        for(int i=0; i<V; ++i){
            // traverse on each edge 
            for(int[] edge: edges){
                int u = edge[0];
                int v = edge[1];
                int wt = edge[2];
                
                // update the minimum distance 
                if(dist[u] + wt < dist[v]){
                    updated = true;
                    dist[v] = dist[u] + wt;
                }
            }
        }
        if(!updated)    return false;
        
        // traverse on each edge 
        for(int[] edge: edges){
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];
                
            // update the minimum distance 
            if(dist[u] + wt < dist[v]){
                return true;
            }
        }
        
        return false;
    }
}