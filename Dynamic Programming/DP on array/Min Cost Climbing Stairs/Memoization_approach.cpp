#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(N)  
// Space complexity :- O(N*N)

// Approach :-
// We can memoize the brute force approach by using 1-d dp since only 1 state is changing 
// dp will be of size n+1, and we'll save the answer of every index in dp


// Link :- https://www.geeksforgeeks.org/problems/min-cost-climbing-stairs/1

class Solution {
  private:
    int helper(int ind, int &n, vector<int> &cost, vector<int> &dp){
        if(ind == 0 || ind == 1)
            return cost[ind];
        
        if(dp[ind] != -1)
            return dp[ind];
        
        int val = (ind == n) ? 0 : cost[ind];
        int opn1 = helper(ind-1, n, cost, dp);
        int opn2 = helper(ind-2, n, cost, dp);
        
        return dp[ind] = val + min(opn1, opn2);
    }
  
  public:
    int minCostClimbingStairs(vector<int>& cost) {
        // Write your code here
        int n = cost.size();
        vector<int> dp(n+1, -1);
        return helper(n, n, cost, dp);
    }
};