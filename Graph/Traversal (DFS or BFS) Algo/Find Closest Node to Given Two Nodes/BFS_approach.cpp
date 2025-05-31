#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(2*N + N*log(N))
// Space complexity :- O(2*N)

//Approach :- 
// Step 1 :- Multisource BFS to calculate the dist of all nodes from node1 and node2
//    -> use dist array of size n*2 were initially dist is INFINITY and this will also reflect as visited array
//    -> apply multisource bfs to traverse on adjacent node and update distance accordingly
// Step2 :- Minimize the maximum distance of a node from node1 and node2 and track the meeting point
//    -> traverse in the array of size n*2 and find the min distance among the max distance of (dist[i][0] & dist[i][1])
//    -> we'll check for only those whose dist values are not INFINITY means it's reachable


//Link :- https://leetcode.com/problems/find-closest-node-to-given-two-nodes/

class Solution {
public:
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n = edges.size(), level = 1;
        vector<vector<int>> dist(n, vector<int> (2, INT_MAX));
        queue<pair<int,int>> q;

        q.push({node1, 0});
        q.push({node2, 1});
        dist[node1][0] = 0;
        dist[node2][1] = 0;

        // Step 1 :- Multisource BFS to calculate the dist of all nodes from node1 and node2
        while(!q.empty()){
            int sz = q.size();

            while(sz-- > 0){
                int node = q.front().first;
                int type = q.front().second;
                q.pop();

                if(edges[node] == -1)
                    continue;
                
                int adjNd = edges[node];

                if(dist[adjNd][type] > level){
                    dist[adjNd][type] = level;
                    q.push({adjNd, type});
                }
            }
            ++level;
        }
        int minDist = INT_MAX, nodeNum = -1;
        
        // Step2 :- Minimize the maximum distance of a node from node1 and node2 and track the meeting point
        for(int i=0; i<n; ++i){
            if(dist[i][0] == INT_MAX || dist[i][1] == INT_MAX)
                continue;
            
            if(max(dist[i][0], dist[i][1]) < minDist){
                minDist = max(dist[i][0], dist[i][1]);
                nodeNum = i;
            }
        }
        return nodeNum;
    }
};