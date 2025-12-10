#include<bits/stdc++.h>
using namespace std;

// Time complexity :- O(n*n)
// Space complexity :- O(n*n + n)

// Approach :-
// using the same approach as mcm 
// we'll use pair<> return type {string, int}, which stores {resultant string, min operation}
// we can memoize the solution using 2d dp where each cell stores the pair<string, int> format

// Links :- https://www.geeksforgeeks.org/problems/brackets-in-matrix-chain-multiplication1024/1

class Solution {
  private:
    pair<string, int> solve(int i, int j, vector<int> &arr, vector<vector<pair<string,int>>> &dp){
        if(i == j){
            string temp = "";
            temp += char('A'+i-1);
            return {temp, 0};
        }
        if(dp[i][j].second != -1)
            return dp[i][j];
        
        int res = INT_MAX;
        string ans;
        
        // try out all possible split point b/w i & j 
        for(int k=i; k<j; ++k){
            pair<string, int> left = solve(i, k, arr, dp);
            pair<string, int> right = solve(k+1, j, arr, dp);
            
            // calculate multiplying the overall cost 
            int currCost = left.second + right.second + arr[i-1] * arr[k] * arr[j];
            
            if(currCost < res){
                res = currCost;
                ans = "(" + left.first + right.first + ")";
            }
        }
        return dp[i][j] = {ans, res};
    }
  
  public:
    string matrixChainOrder(vector<int> &arr) {
        int n = arr.size();
        // intialize the dp array 
        vector<vector<pair<string,int>>> dp(n, vector<pair<string,int>> (n, {"", -1}));
        
        string res = solve(1, n-1, arr, dp).first;
        return res;
    }
};