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
    
    void dfs(int node, int parent, vector<int> &vis, int tin[], int low[],
             vector<int> &mark, vector<vector<int>> &adj) {
                 
        vis[node] = 1;
        tin[node] = low[node] = timer;
        timer++;
        int child = 0;
        
        for (auto it : adj[node]) {
            if (it == parent) continue;
            if (!vis[it]) {
                dfs(it, node, vis, tin, low, mark, adj);
                low[node] = min(low[node], low[it]);
                if (low[it] >= tin[node] && parent != -1) {
                    mark[node] = 1;
                }
                child++;
            }
            else {
                low[node] = min(low[node], tin[it]);
            }
        }
        if (child > 1 && parent == -1) {
            mark[node] = 1;
        }
    }
  
  public:
    vector<int> articulationPoints(int n, vector<vector<int>>& edges) {
        // Code here
        vector<vector<int>> adj(n);
        
        for(auto edge: edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        vector<int> vis(n, 0);
        int tin[n];
        int low[n];
        vector<int> mark(n, 0);
        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                dfs(i, -1, vis, tin, low, mark, adj);
            }
        }
        vector<int> ans;
        for (int i = 0; i < n; i++) {
            if (mark[i] == 1) {
                ans.push_back(i);
            }
        }
        if (ans.size() == 0) return { -1};
        return ans;
    }
};