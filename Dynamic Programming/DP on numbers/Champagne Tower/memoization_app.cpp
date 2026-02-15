#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(row*row)
// Space complexity :- O(row*row)

// Approach :-   
// for finding the champagne in the given glass, we can find 
// how much (row-1, col) and (row-1, col+1) is contribution to the given glass 
// which will become a sub-probelm and can be solve using recursion 
// reset the value of sub-cases to 0.0 if negative value is returned 
// the base case will be when an invalid case comes then return 0
// other we reach top of the tower then return poured 

// Link :- https://leetcode.com/problems/champagne-tower/

class Solution {
private:
    double solve(int poured, int row, int col, vector<vector<double>> &dp){
        // invalid cell value 
        if(row < 0 || col < 0 || row < col)
            return 0.0;
        
        // top of the tower 
        if(row == 0 && col == 0)
            return poured;
        
        // memoization check 
        if(dp[row][col] != -1.0)
            return dp[row][col];
        
        // find the left and right value of tower from which current glass will get 
        double left = (solve(poured, row-1, col-1, dp) - 1) / 2.0;
        double right = (solve(poured, row-1, col, dp) - 1) / 2.0;

        // reset value to 0.0 if we get -ve value 
        if(left < 0)        left = 0.0;
        if(right < 0)       right = 0.0;

        // total value will be sum of both left and right tower 
        return dp[row][col] = left + right;
    }

public:
    double champagneTower(int poured, int query_row, int query_glass) {
        vector<vector<double>> dp(query_row+1, vector<double> (query_glass+1, -1.0));
        // use recursion to find the value 
        return min<double>(1.0, solve(poured, query_row, query_glass, dp));
    }
};