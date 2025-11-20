#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(n+m+26^3)
// Space complexity :- O(26*26)

// Approach :-   
// make a adjacency matrix graph using tranform array of length 26*26
// find the shortest path from all node to all other node using floyd warshal algo
// for every pair of char which are not matching in string try to find the shorter path 
// which you can get and that will be the cost to convert the character
// accumulate all such cost, that will be our final answer 


// Link :- https://www.geeksforgeeks.org/problems/make-strings-equal--150209/1

class Solution {
  private:
    void floydWarshall(vector<vector<int>> &graph){
        for(int k=0; k<26; ++k){
            for(int i=0; i<26; ++i){
                for(int j=0; j<26; ++j){
                    // not egde b/w i to k or either k to j
                    if(graph[i][k] == 1e8 || graph[k][j] == 1e8)
                        continue;
                    
                    if(graph[i][j] < graph[i][k] + graph[k][j])
                        continue;
                    
                    // update the lower cost of the via k 
                    graph[i][j] = graph[i][k] + graph[k][j];
                }
            }
        }
    }
  
  public:
    int minCost(string &s, string &t, vector<vector<char>> &transform,
                vector<int> &cost) {
        
        int n = transform.size();
        vector<vector<int>> graph(26, vector<int> (26, 1e8));
        
        // build adj matrix graph
        for(int i=0; i<26; ++i){
            graph[i][i] = 0;
        }
        
        for(int i=0; i<n; ++i){
            int u = (transform[i][0] - 'a'), v = (transform[i][1] - 'a');
            graph[u][v] = min(cost[i], graph[u][v]);
        }
        // shortest path from every node to other node 
        floydWarshall(graph);
        
        int m = s.size(), res = 0;
        
        for (int i = 0; i < m; ++i) {
            if (s[i] != t[i]) {
                int u = s[i] - 'a', v = t[i] - 'a', best = 1e8;
                for (int c = 0; c < 26; ++c) {
                    if (graph[u][c] < 1e8 && graph[v][c] < 1e8)
                        best = min(best, graph[u][c] + graph[v][c]);
                }
                if (best == 1e8)
                    return -1;
                res += best;
            }
        }
        return res;
    }
};