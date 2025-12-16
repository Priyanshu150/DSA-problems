#include<bits/stdc++.h>
using namespace std;

//Time complexity :- O(n!)
//Space complexity :- O(n) 

// Approach :-
// starting from 0 try out all ways to explore path using recursion and backtracking 
// base case will be whenever all node are visited return the distance from last visited not to 0
// use for loop to traverse on each node and mark then as vis and call recursion 
// later backtrack and mark them as un-visited to explore all paths 

//link :- https://www.geeksforgeeks.org/problems/travelling-salesman-problem2732/1

class Solution {
  private:
    int solve(int last, int cnt, vector<int> &vis, vector<vector<int>> &cost, int &n){
        if(cnt == n){
            return cost[last][0];
        }
        
        int minCost = 1e9;
        
        for(int node=1; node<n; ++node){
            if(vis[node])       continue;
            
            // make node as visited 
            vis[node] = true;
            
            // explore option using recursions 
            int currCost = cost[last][node] + solve(node, cnt+1, vis, cost, n);
            // take min accross all the path 
            minCost = min(minCost, currCost);
            // backtrack 
            vis[node] = false;
        }
        return minCost;
    }
  
  public:
    int tsp(vector<vector<int>>& cost) {
        int n = cost.size();
        
        vector<int> vis(n, false);
        // mark 0 as visited 
        vis[0] = true;
        // try our all ways 
        return solve(0, 1, vis, cost, n);
    }
};