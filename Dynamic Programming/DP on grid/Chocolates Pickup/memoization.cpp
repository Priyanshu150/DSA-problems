#include<bits/stdc++.h>
using namespace std;

// Time Complexity: O(n*m*m)
// Space Complexity: O(n*m*m)

// Approach :- 
// since there are 3 parameter changing 
// we can memoize the solution using 3d dp 
// using standard memoization tenchique we can achieve the same 

// Link :- https://www.geeksforgeeks.org/problems/chocolates-pickup/1

class Solution {
  private:
    int n, m;
    
    // check if the two columns are valid or not 
    bool isValid(int col1, int col2){
        return (col1 >= 0 && col1 < m && col2 >= 0 && col2 < m);
    }
    
    int solve(int row, int col1, int col2, vector<vector<int>> &grid, vector<vector<vector<int>>> &dp){
        int value = 0, res = 0;
        
        // compute chocolate collected by robot depending on the col they are present
        if(col1 == col2){
            value = grid[row][col1];        // same col contribution 
        }
        else{
            value = grid[row][col1] + grid[row][col2];      // idifferent col contribution
        }
        
        // base case 
        if(row == n-1){
            return value;
        }
        // memoization step 
        int &mem = dp[row][col1][col2];
        if(mem != -1){
            return mem;
        }
        
        // try out all ways to move two robots 
        for(int c1=-1; c1<=1; ++c1){
            for(int c2=-1; c2<=1; ++c2){
                // find the next columns value 
                int ncol1 = col1 + c1;
                int ncol2 = col2 + c2;
                
                // if the columns are valid then 
                if(isValid(ncol1, ncol2)){
                    int newVal = solve(row+1, ncol1, ncol2, grid, dp);
                    // maintain max value from all ways 
                    res = max(res, newVal + value);
                }
            }
        }
        return mem = res;
    }
  
  public:
    int maxChocolate(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>> (m+1, vector<int> (m+1, -1)));
        
        return solve(0, 0, m-1, grid, dp);
    }
};