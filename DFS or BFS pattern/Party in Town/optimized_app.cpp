#include <bits/stdc++.h>
using namespace std;

//Time complextiy :- O(n)
// Space complexity :- O(n)

// Approach :-  
// 1. The problem can be solved using the concept of tree diameter.
// 2. The diameter of a tree is the longest path between any two nodes in the tree.
// 3. The optimal party house is located at the center of the diameter.
// 4. To find the diameter, we can perform two BFS traversals:
//    a. First BFS: Start from any node (e.g., node 0)
//       and find the farthest node from it. This node will be one endpoint of the diameter.
//    b. Second BFS: Start from the farthest node found in the first BFS
//       and find the farthest node from it. The distance to this node will be the diameter of the tree.
// the optimal party house is at the center of the diameter i.e ceil (diameter/2) = (diameter+1)/2


//Link :- https://www.geeksforgeeks.org/problems/party-in-town3951/1

class Solution {
  private:
    pair<int,int> bfs(vector<vector<int>> &adj, int start){
        int n = adj.size();
        
        vector<int> dist(n, -1);
        queue<int> q;
        
        dist[start] = 0;
        q.push(start);
        
        int farthestNode = start;
        int farthestDist = 0;
        
        while(!q.empty()){
            int node = q.front();
            q.pop();
            
            for(int next: adj[node]){
                // convert 1-based house number to 0-based index
                next--;
                
                if(dist[next] == -1){
                    dist[next] = dist[node]+1;
                    q.push(next);
                    
                    // update the farthest house 
                    if(dist[next] > farthestDist){
                        farthestDist = dist[next];
                        farthestNode = next;
                    }
                }
            }
        }
        return {farthestNode, farthestDist};
    }
  
  public:
    int partyHouse(vector<vector<int>> &adj) {
        // code here
        int n = adj.size();
        
        // first bfs:
        // find one endpoint of the tree's diameter
        pair<int,int> first = bfs(adj, 0);
        int diameterEnd = first.first;
        
        // second bfs:
        // starting from the diameter endpoint,
        // find the diameter length
        pair<int,int> second = bfs(adj, diameterEnd);
        int diameter = second.second;
        
        // the optimal party house is at the center of the diameter
        // ceil (diameter/2) = (diameter+1)/2
        return (diameter + 1)/2;
    }
};