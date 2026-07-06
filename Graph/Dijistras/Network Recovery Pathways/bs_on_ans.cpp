#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(log(k) + E*log(n)) , where E is edges 
// Space complexity :- O(n + E)

// Approach :-  
// since it ask for max of min, it falls under the bs on answer pattern
// for finding the shortest path we can use dijistra algo to reach destination 
// the answer will be b/w min_cost to max_cost 
// we'll skip adding the offline nodes into the graph 
// for any mid, we'll consider it to be our answer, So any cost with less than mid we'll not consider in our path
// as soon as the sum becomes greater than k, then we'll discard that path 


//Link :- https://leetcode.com/problems/network-recovery-pathways/description/


class Solution {
private:
    typedef long long ll;
    typedef pair<ll,ll> pll;

    // function to check if it's possible to attain path or not with fixed cost 
    bool isPossible(ll minCost, int n, vector<vector<pair<ll,ll>>> &graph,  ll k){
        vector<ll> dist(n, LLONG_MAX);          // dist[node] = cost to reach it 
        priority_queue<pll, vector<pll>, greater<pll>> pq;      // {cost, node}

        // add source node into the queue
        pq.push({0, 0});
        dist[0] = 0;

        // apply standard dijistra's 
        while(!pq.empty()){
            ll cost = pq.top().first;
            ll node = pq.top().second;
            pq.pop();

            // cost of path sum is greater than k or minimum distance seen later 
            if(cost > k || cost > dist[node]){
                continue;
            }
            // we reach to the destinatio n
            if(node == n-1){
                return true;
            }
            // traverse on adjacent node 
            for(auto nbr: graph[node]){
                ll adjNd = nbr.first;
                ll adjCost = nbr.second;

                // cost should be less than minCost to satisfy binary search 
                if(adjCost < minCost){
                    continue;
                }

                // update the min distance taken in the path 
                if(cost + adjCost < dist[adjNd]){
                    dist[adjNd] = cost + adjCost;
                    pq.push({dist[adjNd], adjNd});
                }
            }
        }
        return false;
    }

public:
    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online, long long k) {
        int n = online.size();
        ll low = INT_MAX, high = INT_MIN;
        vector<vector<pair<ll,ll>>> graph(n);
        
        // build graph
        for(auto edge: edges){
            ll u = edge[0], v = edge[1], cost = edge[2];
            // node u or v is offline 
            if(!online[u] || !online[v])
                continue;
            
            // uni-dircetional edge 
            graph[u].push_back({v, cost});

            low = min(low, cost);
            high = max(high, cost);
        }
        
        ll res = -1;

        // standard bs on answer 
        while(low <= high){
            ll mid = low + (high - low)/2;
            // check with mid cost it's valid to find a path 
            if(isPossible(mid, n, graph, k)){
                res = mid;
                low = mid+1;            // increase mid, find the more larger cost
            }else{
                high = mid-1;           // decrease mid, find a valid cost
            }
        }
        return res;
    }
};
