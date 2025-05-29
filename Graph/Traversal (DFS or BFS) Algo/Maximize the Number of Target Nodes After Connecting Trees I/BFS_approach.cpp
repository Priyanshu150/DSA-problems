#include<bits/stdc++.h>
using namespace std;

// Time complexity :- O(n*n + m*m)
// Space complexity :- O(n + m)              

// Approach :- 
// form both of the graph with the edges provided
// Using bfs traversal find the maximum nodes travelled from each node with k-1 distance
// k-1 because 1 edge will use to connect both the graph
// the connection should be from current node to the node giving maximum node with distance k-1
// Using similar bfs approach, find the maximum node travelled from current node with k dist
// after getting the max nodes from current node add the maximum found from the other graph
// this comibination will give us the result for current node 


// Links :- https://leetcode.com/problems/maximize-the-number-of-target-nodes-after-connecting-trees-i/

class Solution {
private:
    int targetNodes(int node, int sz, int dist, vector<vector<int>> graph){
        int res = 0;
        queue<int> q;
        vector<bool> vis(sz, false);

        q.push(node);
        vis[node] = true;

        while(dist-- > 0){
            int totalNodes = q.size();
            res += totalNodes;

            while(totalNodes-- > 0){
                int node = q.front();
                q.pop();

                for(auto adjNd: graph[node]){
                    if(!vis[adjNd]){
                        vis[adjNd] = true;
                        q.push(adjNd);
                    }
                }
            }
        }
        res += q.size();
        return res;
    }

    void buildGraph(vector<vector<int>>& edges, vector<vector<int>>& graph){
        for(auto edge: edges){
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
    }

public:
    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2, int k) {
        int n = edges1.size(), m = edges2.size(), maxNode = 1, res = 1;
        vector<vector<int>> graph1(n+1), graph2(m+1);
        vector<int> ans;

        buildGraph(edges1, graph1);
        buildGraph(edges2, graph2);

        for(int nd=0; nd<=m; ++nd){
            int val = targetNodes(nd, m+1, k-1, graph2);
            maxNode = max(maxNode, val);
        }

        for(int nd=0; nd<=n; ++nd){
            int val = targetNodes(nd, n+1, k, graph1);
            if(k == 0)      ans.push_back(1);
            else            ans.push_back(val + maxNode);
        }
        return ans;
    }
};