#include<bits/stdc++.h>
using namespace std;

// Time complexity :- O(n + n + (n+e))
// Space complexity :- O((n+e) + n)              

// Approach :- 
// Using courses prerequisites, we can make a directed graph 
// on that directed graph we can apply kahn's  algo 
// for the sequence of courses, we can take order of node whichever are push into queue
// if at last all the nodes are present in the answer ds then we can return ans i.e ans.size() == n
// otherwise return {} array

// Links :- https://www.geeksforgeeks.org/problems/course-schedule/1

class Solution {
  public:
    vector<int> findOrder(int n, vector<vector<int>> &prerequisites) {
        // code here
        vector<vector<int>> graph(n);
        vector<int> inDegree(n, 0);
        
        for(auto course: prerequisites){
            int x = course[0], y = course[1];
            // build an un-directed graph 
            graph[y].push_back(x);
            // count the indegree on node 
            inDegree[x] += 1;
        }
        
        queue<int> q;
        
        for(int i=0; i<n; ++i){
            // push the node having inde
            if(inDegree[i] == 0)
                q.push(i);
        }
        vector<int> ans;
        
        // standard bfs
        while(!q.empty()){
            int node = q.front();
            q.pop();
            
            ans.push_back(node);
            
            // traverse on the adjNode and relax the edges 
            for(auto adjNd: graph[node]){
                inDegree[adjNd] -= 1;
                
                if(inDegree[adjNd] == 0){
                    q.push(adjNd);
                }
            }
        }
        if(ans.size() == n)
            return ans;
        
        return {};
    }
};