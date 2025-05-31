#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(2*N + N*log(N))
// Space complexity :- O(2*N)

//Approach :- 
// A single BFS that:
// 1) returns the number of nodes on even-numbered levels, and
// 2) if `included` is non-null, marks exactly those nodes at even levels
//Step-1: Find the best you can do by adding the extra edge in tree-2 
// which mean count the even node and odd node count considering tree root at 0, take maxCnt of both
//Step-2: Run BFS on tree-1, and record nodes on even levels
// mark the nodes present on even and odd level, And count the number even and odd level nodes 
//Step-3: For each i, if i was even-level or odd-level in tree-1 we connect it to tree-2's best level
// even-level or odd-level are decided by the array we made during traversing tree-1


//Link :- https://leetcode.com/problems/maximize-the-number-of-target-nodes-after-connecting-trees-ii/

class Solution {
private:
    void buildGraph(vector<vector<int>> &graph, vector<vector<int>>& edges){
        for(auto edge: edges){
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
    }

    int bfs(vector<vector<int>> &graph, int size, vector<bool> *isEvenNode = nullptr){
        vector<bool> vis(size, 0);
        queue<int> q;
        bool flag = true;
        int cnt = 0;
        
        q.push(0);
        vis[0] = true;

        while(!q.empty()){
            int sz = q.size();
            if(flag)        cnt += sz;

            while(sz-- > 0){
                int node = q.front();
                q.pop();

                if(isEvenNode && flag){
                    (*isEvenNode)[node] = true;
                }

                for(auto adjNd: graph[node]){
                    if(!vis[adjNd]){
                        vis[adjNd] = true;
                        q.push(adjNd);
                    }
                }
            }
            flag = !flag;
        }
        return cnt;
    }

public:
    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        int n = edges1.size() + 1, m = edges2.size() + 1;
        vector<vector<int>> graph1(n), graph2(m);

        buildGraph(graph1, edges1);
        buildGraph(graph2, edges2);

        int evenCnt = bfs(graph2, m);
        int oddCnt = m - evenCnt;
        int maxCnt = max(evenCnt, oddCnt);

        vector<bool> isEvenNode(n, false);
        evenCnt = bfs(graph1, n, &isEvenNode);
        oddCnt = n - evenCnt;

        vector<int> ans;
        for(int i=0; i<n; ++i){
            if(isEvenNode[i]){
                ans.push_back(evenCnt + maxCnt);
            }
            else{
                ans.push_back(oddCnt + maxCnt);
            }
        }
        return ans;
    }
};