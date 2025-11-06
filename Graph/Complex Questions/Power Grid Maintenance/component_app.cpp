#include<bits/stdc++.h>
using namespace std;

// Time complexity :- O(c+e+q)
// Space complexity :- O(c)              

// Approach :- 
// for every component, is the current node is offline then smallest online node will be our answer
// segregate graph based on component, for every componenet fix an untimate parent 
// based on ultimate parent as a key maintain a ordered set of nodes 
// while checking the query find the next available node based on ultimate node if current node is offline 
// for query of type 2 directly make the node as offline in O(1) time 


// Links :- https://leetcode.com/problems/power-grid-maintenance/

class Solution {
private:
    void dfs(int node, int parent, vector<int> &ulp, vector<vector<int>> &graph, unordered_map<int, set<int>> &mp){

        ulp[node] = parent;
        mp[parent].insert(node);

        // traverse on adjacent nodes which is not visited 
        for(auto adjNd: graph[node]){
            if(ulp[adjNd] == -1){
                dfs(adjNd, parent, ulp, graph, mp);
            }
        }
    }

public:
    vector<int> processQueries(int c, vector<vector<int>>& connections, vector<vector<int>>& queries) {
        vector<vector<int>> graph(c+1);

        // build graph
        for(auto edge: connections){
            int u = edge[0], v = edge[1];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        vector<int> ulp(c+1, -1), ans;
        unordered_map<int, set<int>> mp;

        // standard dfs
        for(int i=1; i<=c; ++i){
            if(ulp[i] == -1){
                dfs(i, i, ulp, graph, mp);
            }
        }
        vector<bool> isOnline(c+1, true);

        for(auto q: queries){
            int type = q[0], node = q[1];

            if(type == 1){
                // current node is online 
                if(isOnline[node] == true){
                    ans.push_back(node);
                    continue;
                }
                // find the ulp parent of node 
                int ulpNode = ulp[node];
                // find next smallest index node which is online 
                int smallestStation = mp[ulpNode].size() > 0 ? *mp[ulpNode].begin() : -1;

                while(mp[ulpNode].size() > 0 && isOnline[smallestStation] == false){
                    mp[ulpNode].erase(mp[ulpNode].begin());
                    smallestStation = mp[ulpNode].size() > 0 ? *mp[ulpNode].begin() : -1;
                }

                ans.push_back(smallestStation);
            }
            else{
                isOnline[node] = false;
            }
        }
        return ans;
    }
};