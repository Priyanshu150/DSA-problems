#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(v*(v+e))
// Space complexity :- O(e)

// Approach :- 
// Step1 -> Make adjacency list
// Step2 -> Check if the graph is Bipartite
// Step3 -> Calculate max distance from each node (using BFS)
// Step4 -> Find the max distance count per component


//Link :- https://leetcode.com/problems/divide-nodes-into-the-maximum-number-of-groups/description/

class Solution {
private:
    bool checkBipartite(int node, vector<vector<int>>& graph, vector<int> &colored){
        queue<int> q;
        q.push(node);
        colored[node] = 1;

        while(!q.empty()){
            int nd = q.front();
            q.pop();

            for(auto nbr: graph[nd]){
                if(colored[nbr] == 0){
                    colored[nbr] = -1*colored[nd];
                    q.push(nbr);
                }
                else if(colored[nbr] == colored[nd])
                    return false;
            }
        }
        return true;
    }

    bool isBipartite(int &n, vector<vector<int>>& graph){
        vector<int> colored(n+1, 0);

        for(int i=1; i<=n; ++i){
            if(colored[i] == 0 && !checkBipartite(i, graph, colored))
                return false;
        }
        return true;
    }

    int count_levels(int node, vector<vector<int>>& graph, int &n){
        int level = 0;
        queue<int> q;
        vector<int> vis(n+1, false);

        q.push(node);
        vis[node] = true;

        while(!q.empty()){
            int sz = q.size();

            while(sz--){
                int nd = q.front();
                q.pop();

                for(auto nbr: graph[nd]){
                    if(!vis[nbr]){
                        q.push(nbr);
                        vis[nbr] = true;
                    }
                }
            }
            ++level;
        }
        return level;
    }

    int findMaxLevelsBFS(int node, vector<int> &max_distance, vector<vector<int>>& graph, vector<bool> &vis){
        queue<int> q;
        q.push(node);

        int max_levels = -1;
        while(!q.empty()){
            int curr = q.front();
            q.pop();
            vis[curr] = true;

            max_levels = max(max_levels, max_distance[curr]);
            for(auto nbr: graph[curr]){
                if(!vis[nbr])
                    q.push(nbr);
            }
        }
        return max_levels;
    }

public:
    int magnificentSets(int n, vector<vector<int>>& edges) {
        vector<vector<int>> graph(n+1);

        for(auto edge: edges){
            int u = edge[0], v = edge[1];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        if(!isBipartite(n, graph))      return -1;

        vector<int> max_distance(n+1);
        for(int i=1; i<=n; ++i)
            max_distance[i] = count_levels(i, graph, n);
        
        vector<bool> vis(n+1, false);
        int groups = 0;

        for(int i=1; i<=n; ++i){
            if(!vis[i])
                groups += findMaxLevelsBFS(i, max_distance, graph, vis);
        }
        return groups;
    }
};