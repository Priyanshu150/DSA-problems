#include<bits/stdc++.h>
using namespace std;

// Time complexity :- O(n)                  // Where n is number of nodes
// Space complexity :- O(n)                  // n is space for arrays

// Approach :-
// we'll start visinting the depth first than the neighbour
// the approach we can use is recursion because of it's property for the same 
// we can maintain a vis array to check if the node are visited or not 
// loop trough the node and call the recursion if node is not visited otherwise ignore and move to next
// IN recrsion function mark the node we're visiting and vis the other node linked to that one
// at the same time push it into the ans array to get the traversal stored

// Links :- https://www.geeksforgeeks.org/problems/depth-first-traversal-for-a-graph/1

class Solution {
  private:
    void dfs(int node, vector<vector<int>>& adj, vector<int> &vis, vector<int> &ans){
        vis[node] = true;
        ans.push_back(node);
        
        for(auto nd: adj[node]){
            if(!vis[nd])
                dfs(nd, adj, vis, ans);
        }
    }
  
  public:
    vector<int> dfs(vector<vector<int>>& adj) {
        // Code here
        int n = adj.size();
        vector<int> ans, vis(n, 0);

        for(int i=0; i<n; ++i){
            if(!vis[i])
                dfs(i, adj, vis, ans);
        }
        // dfs(0, adj, vis, ans); // If the graph is connected then add this line instead of looping
        return ans;
    }
};