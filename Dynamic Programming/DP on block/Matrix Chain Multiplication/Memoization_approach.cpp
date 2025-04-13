#include<bits/stdc++.h>
using namespace std;

// Time complexity :- O(n*n)                // Where n is length of string s
// Space complexity :- O(n*n + n)          // for 2d dp array and stack spac

// Approach :-
// We've try all possible combination of block to find our the min operations. Hence, recursion can be used
// Initally the parameter will be (i,j) i.e. (1, n-1), which represent the complete block
// going further we can loop on the k = (i to j-1) to create all possible combination of blocks
// operation can be :- arr[i-1] * arr[k] * arr[j] + f(i, k) + f(k+1, j)
// where the other f() gives us the value of sub-problems 
// we can maintain a variable to track the min value in the loop 
// base case will be, when i == j then return 0 because no matrix exists 

// since there are 2 changing parameter the problem can be memoized with help of 2d dp array 
// save the state while calculation the problem inorder to reuse the same


// Links :- https://www.geeksforgeeks.org/problems/matrix-chain-multiplication0303/1

class Solution {
  private:
    int mcm(int i, int j, vector<int> &arr, vector<vector<int>> &dp){
        if(i == j)              return 0;
        if(dp[i][j] != -1)      return dp[i][j];
        
        int ans = INT_MAX;
        
        for(int k=i; k<j; ++k){
            int operations = arr[i-1]*arr[k]*arr[j] + mcm(i, k, arr, dp) + 
                    mcm(k+1, j, arr, dp);
            
            ans = min(ans, operations);
        }
        return dp[i][j] = ans;
    }
  
  public:
    int matrixMultiplication(vector<int> &arr) {
        // code here
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int> (n, -1));
        return mcm(1, n-1, arr, dp);
    }
};  