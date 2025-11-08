#include<bits/stdc++.h>
using namespace std;

// Time complexity :- O(n*m*k)
// Space complexity :- O(n*m*k + n*m)           

// Approach :- 
// we'll try all possibilities to find the all possible way using reucrion 
// start from bottom-right traverse to top-left column, by moving up & left
// base case will be when we reach top-left cell and value is equal to sum then return 1 otherwise 0
// all possibilites is sum of both ways, up + left
// we'll need 3-d dp to memoize the solution 

// Links :- https://www.geeksforgeeks.org/problems/number-of-paths-in-a-matrix-with-k-coins2728/1

// Code 1 

class Solution {
  private:
    int solve(int row, int col, int sum, vector<vector<int>> &mat, vector<vector<vector<int>>> &dp){
        // base case 
        if(row == 0 && col == 0){
            return (mat[row][col] == sum) ? 1 : 0;
        }
        // if state is previous calculated 
        int &ans = dp[row][col][sum];
        if(ans != -1)
            return ans;
        
        int up = 0, left = 0;
        // traverse up of the grid 
        if(row-1 >= 0 && sum - mat[row][col] >= 0){
            up = solve(row-1, col, sum - mat[row][col], mat, dp);
        }
        // traverse left of the grid 
        if(col-1 >= 0 && sum - mat[row][col] >= 0){
            left = solve(row, col-1, sum - mat[row][col], mat, dp);
        }
        // toatal way will be sum of both 
        return ans = up + left;
    }
  
  
  public:
    int numberOfPath(vector<vector<int>>& mat, int k) {
        int n = mat.size(), m = mat[0].size();
        // use 3d dp table 
        vector<vector<vector<int>>> dp(n, vector<vector<int>> (m, vector<int> (k+1, -1)));
        // use recursion to try out all ways 
        return solve(n-1, m-1, k, mat, dp);
    }
};

// Code 2 

class Solution {
  private:
    int solve(int row, int col, int sum, vector<vector<int>> &mat, vector<vector<vector<int>>> &dp){
        // base case 
        if(row == 0 && col == 0){
            return (mat[row][col] == sum) ? 1 : 0;
        }
        if(sum < 0)
            return 0;
        
        // if state is previous calculated 
        int &ans = dp[row][col][sum];
        if(ans != -1)
            return ans;
        
        int up = 0, left = 0;
        // traverse up of the grid 
        if(row-1 >= 0){
            up = solve(row-1, col, sum - mat[row][col], mat, dp);
        }
        // traverse left of the grid 
        if(col-1 >= 0){
            left = solve(row, col-1, sum - mat[row][col], mat, dp);
        }
        // toatal way will be sum of both 
        return ans = up + left;
    }
  
  
  public:
    int numberOfPath(vector<vector<int>>& mat, int k) {
        int n = mat.size(), m = mat[0].size();
        // use 3d dp table 
        vector<vector<vector<int>>> dp(n, vector<vector<int>> (m, vector<int> (k+1, -1)));
        // use recursion to try out all ways 
        return solve(n-1, m-1, k, mat, dp);
    }
};