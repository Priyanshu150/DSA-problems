#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(n*m*x)
// Space complexity :- O(n*m*stack_size)

// Approach :- 
// since 2 state is changing i.e. diceCnt and sum we can memoize the solution with 2d dp

// Link :- https://www.geeksforgeeks.org/problems/dice-throw5349/1

class Solution {
  private:
    int solve(int diceCnt, int sum, int &m, int &n, vector<vector<int>> &dp){
        if(diceCnt == n){
            return (sum == 0);
        }
        if(sum == 0)    return 0;
        if(dp[diceCnt][sum] != -1)
            return dp[diceCnt][sum];
        
        int res = 0;
        for(int faceVal=1; faceVal<=m; ++faceVal){
            if(sum - faceVal >= 0){
                res += solve(diceCnt+1, sum - faceVal, m, n, dp);
            }
        }
        return dp[diceCnt][sum] = res;
    }
  
  public:
    int noOfWays(int m, int n, int x) {
        // code here
        vector<vector<int>> dp(n+1, vector<int> (x+1, -1));
        return solve(0, x, m, n, dp);
    }
};