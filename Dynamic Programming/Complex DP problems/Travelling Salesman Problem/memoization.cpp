#include<bits/stdc++.h>
using namespace std;

//Time complexity :- O(n^2 * 2^n)
//Space complexity :- O(n* 2^n) 

// Approach :-
// use bitmask to keep track of node that are visited 
// using bitmask there will be 2 changing parameter for the same 
// we can memoize the solution using 2d dp, the bitmask will max be (2^n - 1)

//link :- https://www.geeksforgeeks.org/problems/travelling-salesman-problem2732/1

class Solution {
  private:
    int solve(int mask, int last, vector<vector<int>> &cost, vector<vector<int>> &dp){
        int n = cost.size();
        // base case 
        if(mask == (1<<n)-1){
            return cost[last][0];
        }
        // memoization 
        if(dp[last][mask] != -1)
            return dp[last][mask];
        
        int ans = INT_MAX;
        // explore all possibilities 
        for(int node=0; node<n; ++node){
            // check not is visited or not 
            if((mask & (1<<node)) == 0){
                // find the cost to move to the next and so on 
                int currCost = cost[last][node] + solve(mask | (1<<node), node, cost, dp);
                // keep track of min cost accross all the ways 
                ans = min(ans, currCost);
            }
        }
        return dp[last][mask] = ans;
    }
  
  public:
    int tsp(vector<vector<int>>& cost) {
        int n = cost.size();
        // initialize a 2d dp of size (n*2^n) size 
        vector<vector<int>> dp(n, vector<int> (1<<n, -1));
        // start from 0 city 
        int mask = 1, last = 0;
        return solve(mask, last, cost, dp);
    }
};