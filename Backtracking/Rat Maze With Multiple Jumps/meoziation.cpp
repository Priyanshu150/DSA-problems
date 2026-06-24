#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(n² × maxJump)
// Space complexity :- O(n²)

// Approach :- 


//Link :- https://www.geeksforgeeks.org/problems/rat-maze-with-multiple-jumps3852/1

class Solution {
  private:
    
    // recursive function to find the path 
    bool findPath(int row, int col, vector<vector<int>>& mat, vector<vector<int>>& ans, int& n, vector<vector<int>>& dp){

        // bonunds + blocked check FIRST
        if(row >= n || col >= n || mat[row][col] == 0)
            return false;
    
        if(row == n-1 && col == n-1){
            ans[row][col] = 1;
            return true;
        }
    
        if(dp[row][col] != -1)
            return dp[row][col];
    
        ans[row][col] = 1;
    
        for(int jump = 1; jump <= mat[row][col]; ++jump){
            if(findPath(row, col+jump, mat, ans, n, dp))
                return dp[row][col] = 1;
            if(findPath(row+jump, col, mat, ans, n, dp))
                return dp[row][col] = 1;
        }
    
        ans[row][col] = 0;
        return dp[row][col] = 0;
    }
    
  public:
    vector<vector<int>> shortestDist(vector<vector<int>>& mat) {
        int n = mat.size();
        
        // special case: 1X1 matrxi 
        if(n == 1)
            return {{1}};
        
        // initalize the path matrix 
        vector<vector<int>> ans(n, vector<int> (n, 0));
        
        // blocked start cell check 
        if(mat[0][0] == 0)
            return {{-1}};
        
        // memoization table initialized to -1 (unvisited state)
        vector<vector<int>> dp(n, vector<int> (n, -1));
        
        // if no path exist then return -1
        if(!findPath(0, 0, mat, ans, n, dp))
            return {{-1}};
        
        return ans;
    }
};