#include<bits/stdc++.h>
using namespace std;

// Time complexity :- O(n*n*log(n))
// Space complexity :- O(n*n)              

// Approach :- 
// Make a weighted edge graph where wieght will be distance b/w two houses
// use priority_queue and maintain it in format of {dist, node}
// Intially push {0, 0} into the queue
// Traverse in the queue find the node at the top if node is vistied then consider the another node
// add the dist in the res and find the adjacent node of current node if not visited push that into queue


// Links :- https://www.geeksforgeeks.org/problems/minimum-cost-to-connect-all-houses-in-a-city/1

class Solution {
    #define pii pair<int,int>
    
  public:
    int minCost(vector<vector<int>>& houses) {
        // code here
        int n = houses.size(), res = 0;
        vector<vector<pii>> graph(n);
        
        for(int i=0; i<n-1; ++i){
            for(int j=i+1; j<n; ++j){
                int dist = abs(houses[i][0] - houses[j][0]) + abs(houses[i][1] - houses[j][1]);
                graph[i].push_back({j, dist});
                graph[j].push_back({i, dist});
            }
        }
        vector<bool> vis(n, false);
        priority_queue<pii, vector<pii>, greater<pii>> pq;
        
        pq.push({0, 0});
        
        while(!pq.empty()){
            int node = pq.top().second;
            int dist = pq.top().first;
            pq.pop();
            
            if(vis[node])   continue;
            
            vis[node] = true;
            res += dist;
            
            for(pii curr : graph[node]){
                int adjNd = curr.first, wt = curr.second;
                
                if(!vis[adjNd])
                    pq.push({wt, adjNd});
            }
        }
        return res;
    }
};