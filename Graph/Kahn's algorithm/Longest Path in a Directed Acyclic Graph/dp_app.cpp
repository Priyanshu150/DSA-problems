#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(V+E)
// Space complexity :- O(V+E)

// Approach :-  
// DAG is given we can find the toposort of the graph 
// later start relaxing each node one by one from source 
// everytime we reach a node we maintain a maximum distance for that one 

// links :- https://www.geeksforgeeks.org/problems/longest-path-in-a-directed-acyclic-graph/1

class Solution {
  private:
    typedef pair<int,int> pii;
  
  public:
    vector<int> maxDistance(int V, int src, vector<vector<int>> &edges) {
        vector<pii> graph[V];
        vector<int> inDegree(V, 0);     // node -> count of indegree mapping 
        
        // build the graph 
        for(auto edge: edges){
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];
            
            graph[u].push_back({v, wt});    // u to v edge with wt weight 
            inDegree[v] += 1;       // indegree of v is increased by 1 
        }
        
        queue<int> q;
        // push the node into the queue having indegree as 0
        for(int i=0; i<V; ++i){
            if(inDegree[i] == 0)
                q.push(i);
        }
        vector<int> topoOrder;
        
        // standard topological sorting order 
        while(!q.empty()){
            int node = q.front();
            q.pop();
            
            topoOrder.push_back(node);       // maintain the toposort order 
            
            for(auto adjNbr: graph[node]){
                // relax the neighbour node 
                int adjNd = adjNbr.first;
                inDegree[adjNd] -= 1;
                // in-degree becomes 0 then add it to the quee 
                if(inDegree[adjNd] == 0){
                    q.push(adjNd);
                }
            }
        }
        
        vector<int> res(V, INT_MIN);
        res[src] = 0;
        
        for(int node: topoOrder){
            // skip the node if not reachable 
            if(res[node] == INT_MIN)
                continue;
            
            // traverse on the adjacent neighbour 
            for(auto adjNbr: graph[node]){
                int adjNd = adjNbr.first;
                int wt = adjNbr.second;
                // update the distance reachable to the next node 
                res[adjNd] = max(res[adjNd], res[node] + wt);
            }
        }
        return res;
    }
};