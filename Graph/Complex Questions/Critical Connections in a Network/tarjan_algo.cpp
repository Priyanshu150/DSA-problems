#include<bits/stdc++.h>
using namespace std;

// Time complexity :- O(v+e)
// Space complexity :- O(v+e)              

// Approach :- 
// use tarjan algo to determine how many edge are bridge in complete graph 
// i.e. start a timer and record the time to reach each node in tin 
// also maintain low timer to reach adj node apart from parent in ltin
// if node is not visited then update the lowest time after traversal of child 
// and imediately after that delete the edge and check if it's a bridge or not 
// if it's a bridge then lowsest time of adj node will be greater than insertion time of node i.e ltin[adjNd] > tin[node]
// because it can't access someone before it to update it's timing
// otherwise if node is visited, then only update the lowest time of current node comparing with adj node 
// it can never be a bridge as it already visited via some path, even if we break the edge it will be visited 


// Links :- https://leetcode.com/problems/critical-connections-in-a-network/description/

class Solution {
private:
    int timer = 1;
    vector<int> tin, ltin, vis;
    vector<vector<int>> graph, ans;

    void dfs(int node, int parent){
        vis[node] = 1;
        tin[node] = ltin[node] = timer;
        timer++;

        for(auto adjNd: graph[node]){
            // skip the parent 
            if(adjNd == parent)
                continue;
            // adjacent node is not visited 
            else if(vis[adjNd] == 0){
                dfs(adjNd, node);
                // update the lowest time for current node based on child traversal 
                ltin[node] = min(ltin[node], ltin[adjNd]);

                // check if it's a bridge or not 
                if(ltin[adjNd] > tin[node]){
                    ans.push_back({node, adjNd});
                }
            }
            // adjacent node is visited 
            else{
                // that edge can never be a bridge because adjNd is already visited via some other path
                ltin[node] = min(ltin[node], ltin[adjNd]);
            }
        }
    }

public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        graph.resize(n);

        // build a undirected graph 
        for(auto edge: connections){
            int u = edge[0], v = edge[1];

            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        // intialize time of intersion, lowest time of insertion and visited with n size and default values  
        tin.resize(n, INT_MAX);
        ltin.resize(n, INT_MAX);
        vis.resize(n, 0);

        // standard dfs with parent node 
        dfs(0, -1);
        return ans;
    }
};