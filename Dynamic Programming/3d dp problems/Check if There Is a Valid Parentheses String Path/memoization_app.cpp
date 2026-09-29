#include <bits/stdc++.h>
using namespace std;

// Time complexity :- O(n*m*(n+m))  where n is number of rows and m is number of columns
// Space complexity :- O(n*m*(n+m))  where n is number of rows and m is number of columns

// Approach :- 
// 1. We will use a recursive function to check if there is a valid parentheses string path from the top-left corner to the bottom-right corner of the grid.
// 2. We will keep track of the number of open brackets encountered so far in the path. If at any point the number of open brackets becomes negative, we return false.
// 3. If we reach the bottom-right corner of the grid and the number of open brackets is zero, we return true.

//Link :- https://leetcode.com/problems/check-if-there-is-a-valid-parentheses-string-path/description

class Solution {
private:
    int m, n;

    bool solve(int row, int col, int openBracket, vector<vector<char>>& grid, vector<vector<vector<int>>> &dp){

        openBracket += (grid[row][col] == '(') ? 1 : -1;

        if(openBracket < 0)
            return false;
        
        if(row == m-1 && col == n-1){
            return (openBracket == 0);
        }
        int &ans = dp[row][col][openBracket];
        if(ans != -1)
            return ans;
        

        // move down 
        if(row+1 < m){
            if(solve(row+1, col, openBracket, grid, dp)){
                return ans = true;
            }
        }

        // move right
        if(col+1 < n){
            if(solve(row, col+1, openBracket, grid, dp)){
                return ans = true;
            }
        }
        return ans = false; 
    }

public:
    bool hasValidPath(vector<vector<char>>& grid) {
        m = grid.size();
        n = grid[0].size();

        if(grid[0][0] == ')')  return false;
        if(grid[m-1][n-1] == '(')  return false;
        if((m + n - 1) % 2 != 0) return false;

        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(m + n, -1)));

        return solve(0, 0, 0, grid, dp);
    }
};