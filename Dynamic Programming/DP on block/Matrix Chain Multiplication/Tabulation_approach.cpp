#include<bits/stdc++.h>
using namespace std;

// Time complexity :- O(n*n)                // Where n is length of string s
// Space complexity :- O(n*n)              // for 2d dp array

// Approach :-
// To reduce the stack space we can use tabulation solution
// Initailize a dp array with all value as INT_MAX
// Express the base case, for all value of i where i==j, then dp[i][j] will be 0
// i we will traverse from n-1 to 1 and j will be from i+1 to n 
// express the same possibilities from the memoization / recursion 
// At last the answer will be present at dp[1][n-1]


// Links :- https://www.geeksforgeeks.org/problems/matrix-chain-multiplication0303/1

class Solution {
  public:
    int matrixMultiplication(vector<int> &arr) {
        // code here
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int> (n, INT_MAX));
        
        for(int i=0; i<n; ++i)
            dp[i][i] = 0;
        
        for(int i=n-1; i>=1; --i){
            for(int j=i+1; j<n; ++j){
                for(int k=i; k<j; ++k){
                    int operations = arr[i-1]*arr[k]*arr[j] + dp[i][k] + dp[k+1][j];
                    dp[i][j] = min(dp[i][j], operations);
                }
            }
        }
        return dp[1][n-1];
    }
};