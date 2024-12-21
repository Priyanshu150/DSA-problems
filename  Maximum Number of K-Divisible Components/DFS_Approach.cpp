#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    #define ll long long

    vector<bool> vis;
    vector<vector<int>> graph;

    ll dfs(int node, vector<int>& values, int &k, int &comp){
        ll sum = values[node];
        vis[node] = true;

        //calulation the overall sum of the parent and the child below it
        for(auto nd: graph[node]){
            if(!vis[nd]){
                sum += dfs(nd, values, k, comp);
            }
        }
        //Checking if component is divisible by k 
        if(sum%k == 0){
            //Once it's divisible dividing it into one separate component 
            comp++;
            sum = 0;
        }
        return sum;
    }

public:
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        int res = 0;
        vis.resize(n, false);
        graph.resize(n);

        //Creating the adjacency list 
        for(auto edge: edges){
            int u = edge[0], v = edge[1];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        dfs(0, values, k, res);
        return res;
    }
};