#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(m*n)
// Space complexity :- O(m*n)

// Approach :- 
// use bfs to create all the possibilities state 
// intially the jugs will be the empty 
// there will be total 6 possibilities 
// 1. fill jug1 
// 2. fill jug2 
// 3. empty jug1 
// 4. empty jug2
// 5. pour jug1 into jug2 
// 6. pour jug2 into jug1 


// Link :- https://www.geeksforgeeks.org/problems/two-water-jug-problem3402/1

class Solution {
  public:
    int minSteps(int m, int n, int d) {
        // check if the target is achievable or not 
        if(d > max(m, n))       return -1;
        
        int steps = 0;
        // queue with state {jug1, jug2} capacity 
        queue<pair<int,int>> q;
        // for tracing the visited states 
        vector<vector<bool>> vis(m+1, vector<bool> (n+1, false));
        
        // start with empty jugs initially 
        q.push({0, 0});
        vis[0][0] = true;
        
        while(!q.empty()){
            int sz = q.size();
            
            while(sz--){
                int jug1 = q.front().first;
                int jug2 = q.front().second;
                q.pop();
                
                // we intially reached a solution 
                if(jug1 == d || jug2 == d)
                    return steps;
                
                // all possible operation:
                // 1. fill jug1 
                if(!vis[m][jug2]){
                    vis[m][jug2] = true;
                    q.push({m, jug2});
                }
                
                // 2. fill jug2 
                if(!vis[jug1][n]){
                    vis[jug1][n] = true;
                    q.push({jug1, n});
                }
                
                // 3. empty jug1 
                if(!vis[0][jug2]){
                    vis[0][jug2] = true;
                    q.push({0, jug2});
                }
                
                // 4. empty jug2
                if(!vis[jug1][0]){
                    vis[jug1][0] = true;
                    q.push({jug1, 0});
                }
                
                // 5. pour jug1 into jug2 
                int pour1to2 = min(jug1, n-jug2);
                if(!vis[jug1 - pour1to2][jug2 + pour1to2]){
                    vis[jug1 - pour1to2][jug2 + pour1to2] = true;
                    q.push({jug1 - pour1to2, jug2 + pour1to2});
                }
                
                // 6. pour jug2 into jug1 
                int pour2to1 = min(jug2, m - jug1);
                if(!vis[jug1 + pour2to1][jug2 - pour2to1]){
                    vis[jug1 + pour2to1][jug2 - pour2to1] = true;
                    q.push({jug1 + pour2to1, jug2 - pour2to1});
                }
            }
            ++steps;
        }
        return -1;
    }
};