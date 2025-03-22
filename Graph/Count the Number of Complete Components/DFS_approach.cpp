#include<bits/stdc++.h>
using namespace std;

//Time complexity :- O(V+E)
//Space complexity :- O(V)

// Approach :-
// In a component the number of nodes should have ((nodes-1)*nodes)/2 edges to become complete components
// for each component we can count the edges, if we got the desired number of edges 
// then increament the count of res variable 
// since it's a undirected graph every edge will be occuring twice so the formual can be changes as (nodes - 1)*nodes


//link :- https://leetcode.com/problems/count-the-number-of-complete-components/


class Solution {
private:
    void dfs(int node, vector<bool> &vis, vector<int> graph[], int &vertexCnt, int &edgCnt){
        vis[node] = true;
        vertexCnt += 1;
        edgCnt += graph[node].size();

        for(auto adjNode: graph[node]){
            if(!vis[adjNode])
                dfs(adjNode, vis, graph, vertexCnt, edgCnt);
        }
    }

public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<int> graph[n];

        for(auto edge: edges){
            int u = edge[0], v = edge[1];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        int res = 0;
        vector<bool> vis(n, false);
        
        for(int nd=0; nd<n; ++nd){
            if(!vis[nd]){
                int vertexCnt = 0,  edgCnt = 0;
                dfs(nd, vis, graph, vertexCnt, edgCnt);

                if(vertexCnt*(vertexCnt-1) == edgCnt)
                    res++;
            }
        }
        return res;
    }
};