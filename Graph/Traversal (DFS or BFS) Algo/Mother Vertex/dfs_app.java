#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(V+E)
// Space complexity :- O(V)

// Approach :-  
// The vertex which in last visited can be a potential candidate for the mother vertex 
// if all the vertex are not visited in last then no mother vertex exists 


//Link :- https://www.geeksforgeeks.org/problems/mother-vertex/1

class Solution {
    private void dfs(int node, boolean[] visited, List<List<Integer>> graph){ 
        visited[node] = true;
        
        for(int adjNd: graph.get(node)){
            if(!visited[adjNd]){
                dfs(adjNd, visited, graph);
            }
        }
    }
    
    public int findMotherVertex(int V, int[][] edges) {
        List<List<Integer>> graph = new ArrayList<>();
        
        // initialize the adjacency list 
        for(int i=0; i<V; ++i){ 
            graph.add(new ArrayList<>());
        }
        
        // build the graph 
        for(int[] edge: edges){
            int u = edge[0];
            int v = edge[1];
            
            graph.get(u).add(v);
        }
        
        boolean[] visited = new boolean[V];
        int candidate = 0;
        
        // find the last finished vertex
        for(int i=0; i<V; ++i){
            if(!visited[i]){
                dfs(i, visited, graph);
                candidate = i;
            }
        }
        
        // check if the candidate reached all vertex
        Arrays.fill(visited, false);
        dfs(candidate, visited, graph);
    
        // validate if the candidate is mother vertex 
        for(boolean v : visited){
            if(!v)      return -1;
        }
        return candidate;
    }
}