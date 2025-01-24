#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(2*N + N*log(N))
// Space complexity :- O(2*N)

//Approach :- 
// Find the number of outdegree of each node 
// Push the node which have zero outdegree to queue
// Reverse the graph to traverse from the terminal node to all the safe node
// Apply bfs on the nodes present in queue 
// For a node traverse to its adjacent nodes and reduce it's outdegree by 1 
// which means removing a edge from that node to terminal node / safe node
// If indegree of that node becomes 0 then we can push that node into the queue which means it's a safe node


//Link :- https://leetcode.com/problems/find-eventual-safe-states/description/

class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> outDegree(n, 0), res;
        vector<vector<int>> reversed_graph(n);
        queue<int> q;

        for(int i=0; i<n; ++i){
            outDegree[i] = graph[i].size();

            for(auto nd: graph[i])
                reversed_graph[nd].push_back(i);

            if(outDegree[i] == 0)
                q.push(i);
        }

        while(!q.empty()){
            int nd = q.front();
            q.pop();

            res.push_back(nd);

            for(auto adjNd: reversed_graph[nd]){
                outDegree[adjNd] -= 1;
                if(outDegree[adjNd] == 0)
                    q.push(adjNd);
            }
        }
        sort(res.begin(), res.end());
        return res;
    }
};  