#include<bits/stdc++.h>
using namespace std;

//Time complexity :- O(26^3 + n + m)
//Space complexity :- O(26*26) 

// Approach :-
// find the short path from every char to every other char using floyd warshall algo
// using shortest distance calculate the value needed for updating the string 

//link :- https://leetcode.com/problems/minimum-cost-to-convert-string-i/

class Solution {
private:
    typedef long long ll;

    void floydWarshall(vector<vector<ll>> &graph){
        // travel from i to j via k 
        for(int k=0; k<26; ++k){
            for(int i=0; i<26; ++i){
                for(int j=0; j<26; ++j){
                    // i to k or k to j is unreachable 
                    if(graph[i][k] == INT_MAX || graph[k][j] == INT_MAX)
                        continue;
                    
                    // update the shortest distance for the nodes 
                    ll dist = graph[i][k] + graph[k][j];
                    graph[i][j] = min<ll>(dist, graph[i][j]);
                }
            }
        }
    }

public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        
        int n = cost.size(), m = source.size();
        vector<vector<ll>> graph(26, vector<ll> (26, INT_MAX));     // adj matrix 

        // create a adj matrix for every link given 
        for(int i=0; i<n; ++i){
            int u = original[i] - 'a';
            int v = changed[i] - 'a';
            ll wt = min<ll>(graph[u][v], cost[i]);
            graph[u][v] = wt;
        }

        // apply floyd warshal algo to get min cost among all the node values 
        floydWarshall(graph);
        ll res = 0;

        // for every char in source to target 
        for(int i=0; i<m; ++i){
            int u = source[i] - 'a';
            int v = target[i] - 'a';
            // if both node are already same, skip the process 
            if(u == v)  continue;

            ll dist = graph[u][v];
            // if the nodes are unreachable 
            if(dist >= INT_MAX)
                return -1;

            res += dist;        // add the current distance in answer 
        }
        return res;
    }
};