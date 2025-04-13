#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(N*W)  
// Space complexity :- O(N*W*N)

// Approach :-
// We've try all possibilities and take out the maximum ans out of it, we can use recursion for the same 
// there will two chaning state ind(n-1), Weight(W) and there will be 2 possiblities 
// 1st possibility, we don't take current ind in our ans and move to ind-1
// 2nd possibility, we consider the current ind but the weight of that index should be less than knapsack(W)
// the base case will be when we reach ind==0, then consider 0th element if we've the capacity of knapsack
// and take the max of (1st & 2nd) possibility as our answer

// we can memoize the state as only two states are changing ind & W, by taking 2d dp
// we'll save the answer the in those state and reduce the redundant calucaltion of recursion 

// Link :- https://www.geeksforgeeks.org/problems/0-1-knapsack-problem0945/1

class Solution {
  private:
    int solve(int ind, int w, vector<int> &val, vector<int> &wt, vector<vector<int>> &dp){
        if(ind == 0){
            if(wt[0] <= w)
                return val[0];
            
            return 0;
        }
        if(w == 0)      return 0;
        if(dp[ind][w] != -1)
            return dp[ind][w];
        
        int notTake = solve(ind-1, w, val, wt, dp), take = 0;
        if(wt[ind] <= w)
            take = val[ind] + solve(ind-1, w-wt[ind], val, wt, dp);
        
        return dp[ind][w] = max(take, notTake);
    }
  
  public:
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        // code here
        int n = val.size();
        vector<vector<int>> dp(n, vector<int> (W+1, -1));
        return solve(n-1, W, val, wt, dp);
    }
};