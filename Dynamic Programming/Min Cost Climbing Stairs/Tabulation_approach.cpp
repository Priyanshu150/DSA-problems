#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(N)  
// Space complexity :- O(N)

// Approach :-
// We can convert the memoiztion approach to tabulation using the below step 
// we are going from n to 1 or 0 in memoization so considering vice-versa will from 2 to n in tabulation
// we can use same dp table and add base case as dp[0] = cost[0] and dp[1] = cost[1]
// then replicate the same possibilites which we've used in memoization

// Link :- https://www.geeksforgeeks.org/problems/min-cost-climbing-stairs/1

class Solution {
  public:
    int minCostClimbingStairs(vector<int>& cost) {
        // Write your code here
        int n = cost.size();
        vector<int> dp(n+1, 0);
        dp[0] = cost[0];
        dp[1] = cost[1];
        
        for(int ind=2; ind<=n; ++ind){
            int val = (ind == n) ? 0 : cost[ind];
            dp[ind] = val + min(dp[ind-1], dp[ind-2]);
        }
        return dp[n];
    }
};