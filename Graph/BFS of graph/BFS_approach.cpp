#include<bits/stdc++.h>
using namespace std;

// Time complexity :- O(n)                  // Where n is number of nodes
// Space complexity :- O(n)                  // n is space for vis arrays and queue

// Approach :-
// since we've to visit level first, we can make use of queue as it's best suited for such cases
// we'll start with root node 0, push it onto queue and mark that as visited
// for every node in queue pop that one out and put the node in our answer 
// traverse on all the adjacent node of the current node which is poped out and push into queue
// mark them as visited and repeat the process untill all the nodes are traversed


// Links :- https://www.geeksforgeeks.org/problems/bfs-traversal-of-graph/1

class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfs(vector<vector<int>> &adj) {
        // Code here
        int n = adj.size();
        queue<int> q;
        vector<int> res, vis(n, 0);
        
        q.push(0);
        vis[0] = 1;
        
        while(!q.empty()){
            int nd = q.front();
            q.pop();
            
            res.push_back(nd);
            
            for(auto adjNd: adj[nd]){
                if(!vis[adjNd]){
                    q.push(adjNd);
                    vis[adjNd] = 1;
                }
            }
        }
        return res;
    }
};