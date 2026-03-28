#include<bits/stdc++.h>
using namespace std;

// Time complexity :- O(v+e)          
// Space complexity :- O(v+e)              

// Approach :- 
// start a timer and maintain a timer and lower_timer for a node 
// low_timer will be time apart from parent and not visited node 
// Apply dfs to traverse on the graph and mark the timer respectively
// In dfs, intially the time[node] = low_time[node] = timer
// expect for parent vis the adjacent node
// if not visited, call dfs and maintain lowest time for the node 
// check if low_time of adj node is greater that the time of current node if yes that means it's an articulation point 
// (it should node be a root node parr != -1)
// if adj node is visited, then update low_time of cureent node low_time and adj node time 
// maintain a hashed array to mark articulation point because in case of multiple child same node can reapeat
// Handly parent case seperately, for parent count the child component if there are multiple child the parent will also be articualtion point


// Links :- https://www.geeksforgeeks.org/problems/articulation-point2616/1

class Solution {
  private:
    int timer = 1;
    vector<vector<int>> graph;
    vector<int> tin, low, vis, isAP;
    
    void dfs(int node, int parent){
        vis[node] = 1;
        tin[node] = low[node] = timer;
        ++timer;
        
        int child = 0;
        
        for(auto adjNd: graph[node]){
            // adjNd should not be parent 
            if(adjNd == parent){
                continue;
            }
            else if(!vis[adjNd]){
                dfs(adjNd, node);
                // update the lowest time for the current node base on adjNd
                low[node] = min(low[node], low[adjNd]);
                
                // check if adjNd can access someone before node then it's not AP
                // if parent is -1, then it's not possible to reach node before that
                if(tin[node] <= low[adjNd] && parent != -1){
                    isAP[node] = 1;
                }
                // count the number of child nodes for parent node 
                child++;
            }
            else{
                //for not visited node, minimum time should be insertion time for adjacent node
                // because we're deleting the node not an edge 
                low[node] = min(low[node], tin[adjNd]);
            }
        }
        // for parent check the special condition depending on the child it has
        if(child > 1 && parent == -1){
            isAP[node] = 1;
        }
    }
  
  public:
    vector<int> articulationPoints(int V, vector<vector<int>>& edges) {
        graph.resize(V);
        
        for(auto edge: edges){
            int u = edge[0], v = edge[1];
            
            // create a un-directed graph
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        // intialize time of intersion, lowest time of insertion and visited with n size and default values
        vis.resize(V, 0);
        tin.resize(V, INT_MAX);
        low.resize(V, INT_MAX);
        // initialize is articulation point with 0 indicating as no one is that 
        isAP.resize(V, 0);
        
        for(int i=0; i<V; ++i){
            // current node is not visited 
            if(!vis[i]){
                dfs(i, -1);
            }
        }
        
        vector<int> ans;
        
        for(int i=0; i<V; ++i){
            // current node is articulation point 
            if(isAP[i] == 1){
                ans.push_back(i);
            }
        }
        if(ans.size() > 0)
            return ans;
        
        // no articulation point found 
        return {-1};
    }
};