#include<bits/stdc++.h>
using namespace std;

// Time complexity :- O(n*m*k)
// Space complexity :- O(n*m*k)           

// Approach :- 
// base case will be, everything initialized to 0 and dp[0][0][mat[0][0]] = 1
// row => 0 to n-1, col => 0 to m-1 and sum => 0 to k-1, skip when row == 0 and col == 0
// express the same possibilities from memoization approach 
// ans will be stored at  dp[n-1][m-1][k]

// Links :- https://www.geeksforgeeks.org/problems/number-of-paths-in-a-matrix-with-k-coins2728/1

// Code 1

class Solution {
  public:
    int numberOfPath(vector<vector<int>>& mat, int k) {
        int n = mat.size(), m = mat[0].size();
        // use 3d dp table 
        vector<vector<vector<int>>> dp(n, vector<vector<int>> (m, vector<int> (k+1, 0)));
        
        // base case 
        if(mat[0][0] <= k)
            dp[0][0][mat[0][0]] = 1;
        
        // explore all the option or row*col*sum
        for(int row=0; row<n; ++row){
            for(int col=0; col<m; ++col){
                for(int sum=0; sum<=k; ++sum){
                    if(row == 0 && col == 0)
                        continue;
                    
                    int up = 0, left = 0;
                    // traverse up of the grid 
                    if(row-1 >= 0 && sum - mat[row][col] >= 0){
                        up = dp[row-1][col][sum - mat[row][col]];
                    }
                    // traverse left of the grid 
                    if(col-1 >= 0 && sum - mat[row][col] >= 0){
                        left = dp[row][col-1][sum - mat[row][col]];
                    }
                    // toatal way will be sum of both 
                    dp[row][col][sum] = up + left;
                }
            }
        }
        return dp[n-1][m-1][k];
    }
};

// Code 2 

class Solution {
  public:
    int numberOfPath(vector<vector<int>>& mat, int k) {
        int n = mat.size(), m = mat[0].size();
        // use 3d dp table 
        vector<vector<vector<int>>> dp(n, vector<vector<int>> (m, vector<int> (k+1, 0)));
        
        // explore all the option or row*col*sum
        for(int row=0; row<n; ++row){
            for(int col=0; col<m; ++col){
                for(int sum=0; sum<=k; ++sum){
                    // base case 
                    if(row == 0 && col == 0 && mat[row][col] == sum){
                        dp[row][col][sum] = 1;   
                    }
                    else{
                        int up = 0, left = 0;
                        // traverse up of the grid 
                        if(row-1 >= 0 && sum - mat[row][col] >= 0){
                            up = dp[row-1][col][sum - mat[row][col]];
                        }
                        // traverse left of the grid 
                        if(col-1 >= 0 && sum - mat[row][col] >= 0){
                            left = dp[row][col-1][sum - mat[row][col]];
                        }
                        // toatal way will be sum of both 
                        dp[row][col][sum] = up + left;
                    }
                }
            }
        }
        return dp[n-1][m-1][k];
    }
};