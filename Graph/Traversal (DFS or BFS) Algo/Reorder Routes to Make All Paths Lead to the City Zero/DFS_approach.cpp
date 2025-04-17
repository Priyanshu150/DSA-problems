#include<bits/stdc++.h>
using namespace std;

// Time complextiy :- O(v+e)
// Space complexity :- O(v+e)

// Approach :-
// Create a graph based on the logic of outgoing and incoming edge
// Start traversal from 0, if you found any edge as outgoing count them 
// count all the nodes while traversing the graph


// Link :- https://leetcode.com/problems/reorder-routes-to-make-all-paths-lead-to-the-city-zero/description/

// 1st way
class Solution {
private:
    int dfs(int node, vector<bool> &vis, vector<vector<pair<int,int>>> &graph){
        vis[node] = true;
        int res = 0;

        for(auto nbr: graph[node]){
            int adjNd = nbr.first, edge = nbr.second;
            if(!vis[adjNd]){
                if(edge == 1)       res += 1;
                res += dfs(adjNd, vis, graph);
            }
        }
        return res;
    }

public:
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<bool> vis(n, false);
        vector<vector<pair<int,int>>> graph(n);

        for(auto connection: connections){
            int u = connection[0], v = connection[1];
            graph[u].push_back({v, 1});   // OUT-GOING
            graph[v].push_back({u, 0});   // IN-COMING
        }
        return dfs(0, vis, graph);
    }
};

// 2nd way
class Solution {
private:
    void dfs(int node, int &res, vector<bool> &vis, vector<vector<pair<int,int>>> &graph){
        vis[node] = true;

        for(auto nbr: graph[node]){
            int adjNd = nbr.first, edge = nbr.second;
            if(!vis[adjNd]){
                if(edge == 1)       res += 1;
                dfs(adjNd, res, vis, graph);
            }
        }
    }

public:
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<bool> vis(n, false);
        vector<vector<pair<int,int>>> graph(n);

        for(auto connection: connections){
            int u = connection[0], v = connection[1];
            graph[u].push_back({v, 1});   // OUT-GOING
            graph[v].push_back({u, 0});   // IN-COMING
        }
        int res = 0;
        dfs(0, res, vis, graph);
        return res;
    }
};