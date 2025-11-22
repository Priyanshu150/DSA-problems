#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O((V+E)logV)
// Space complexity :- O(V+E)

// Approach :- 
// find the sortest path from node a to every other node using dijistra's 
// repeat same for b, there will be 3 possibilities of min distance
// 1. a to b,  2. a to u + curved_edge + b to v  & 3. a to v + curved_edge + b to u 
// traverse on each curved edge one by one and try all these possibilities  

// Link :- https://www.geeksforgeeks.org/problems/shortest-path-using-atmost-one-curved-edge--170647/1

class Solution {
  private:
    vector<int> dijkstra(int a,int b,int n,vector<pair<int,int>> adj[]){
        vector<int> dist(n+1,1e9);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        dist[a]=0;
        pq.push({0,a});
        
        while(!pq.empty())
        {
            auto curr=pq.top();
            pq.pop();
            int dis=curr.first;
            int node=curr.second;
            
            for(auto it:adj[node])
            {
                int v=it.first;
                int wt=it.second;
                if(dist[v]>dist[node]+wt)
                {
                    dist[v]=dist[node]+wt;
                    pq.push({dist[v],v});
                }
            }
        }
        return dist;
    }
  
  public:
    int shortestPath(int n, int a, int b, vector<vector<int>> &edges) {
        int m = edges.size();
        vector<pair<int,int>> adj[n+1];
        vector<vector<int>> curved;
        
        for(int i=0;i<m;i++)
        {
            int u=edges[i][0];
            int v=edges[i][1];
            int wt=edges[i][2];
            int cwt=edges[i][3];
            
            adj[u].push_back({v,wt});
            adj[v].push_back({u,wt});
            
            curved.push_back({u,v,cwt});
        }
        vector<int> dist1=dijkstra(a,b,n,adj);
        vector<int> dist2=dijkstra(b,a,n,adj);
        
        int ans=dist1[b];
        
        for(int i=0;i<m;i++)
        {
            int u=curved[i][0];
            int v=curved[i][1];
            int cwt=curved[i][2];
            
            ans=min(ans,dist1[u]+cwt+dist2[v]);
            ans=min(ans,dist1[v]+cwt+dist2[u]);
        }
        
        if(ans>=1e9) return -1;
        return ans;
    }
};