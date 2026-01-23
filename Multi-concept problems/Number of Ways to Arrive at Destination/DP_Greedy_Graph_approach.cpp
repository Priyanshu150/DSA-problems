#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(E*log(V))
// Space complexity :- O(V)

// Approach :-  
// Dijistras algorithm can be use to find the minimum distance
// Then number to arrive at destination will be equal to sum of all the ways to arrive at node throught which we can reach destination
// while calculating the dist we can also count way to reach at destination with given distance 
// if we are reaching with a minimum distance then then update the new distance 
// and ways will be equal to the ways to reach the current node from which we're reaching the destination
// if the distance is equal to the minimum node then add the ways from the current node

//Link :- https://leetcode.com/problems/number-of-ways-to-arrive-at-destination/

class Solution {
private:
    #define ll long long
    #define pii pair<long,long>
    #define mod 1000000007

public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pii>> graph(n);

        for(auto road: roads){
            int u = road[0], v = road[1], wt = road[2];

            graph[u].push_back({v, wt});
            graph[v].push_back({u, wt});
        }
        priority_queue<pii, vector<pii>, greater<pii>> pq;
        vector<ll> ways(n, 0), dist(n, LONG_MAX);

        dist[0] = 0;
        ways[0] = 1;
        pq.push({0, 0});

        while(!pq.empty()){
            ll nd = pq.top().second;
            ll dis = pq.top().first;
            pq.pop();

            for(auto it : graph[nd]){
                ll adjNd = it.first, edgWt = it.second;

                if(dis + edgWt < dist[adjNd]){
                    dist[adjNd] = dis + edgWt;
                    ways[adjNd] = ways[nd];
                    pq.push({dist[adjNd], adjNd});
                }
                else if(dis + edgWt == dist[adjNd])
                    ways[adjNd] = (ways[adjNd] + ways[nd]) % mod;
            }
        }
        return ways[n-1];
    }
};