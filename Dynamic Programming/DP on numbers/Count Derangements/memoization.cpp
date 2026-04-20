#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(n)
// Space complexity :- O(n)


// Link :- https://www.geeksforgeeks.org/problems/dearrangement-of-balls0918/1

class Solution {
  private:
    int solve(int num, vector<int> &dp){
        if(num <= 3)
            return (num-1);
        if(dp[num] != -1)
            return dp[num];
        
        return dp[num] = (num-1) * (solve(num-1, dp) + solve(num-2, dp));
    }
  
  public:
    int derangeCount(int n) {
        vector<int> dp(n+1, -1);
        return solve(n, dp);
    }
};