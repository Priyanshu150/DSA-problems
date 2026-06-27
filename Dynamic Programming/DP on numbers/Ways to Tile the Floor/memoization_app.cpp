#include<bits/stdc++.h>
using namespace std;

//Time complexity :- O(N)
//Space complexity :- O(N)

// Approach :-
// we've to try all ways to place the tiles in  the grid, we've to option for that 
// first, place the one tile 1*m horizontally and rest use recursion to solve it 
// second, place the second tile row*m vertical tile and rest of them use recursion to place it 
// the combination to both ways will be our answer
// base case will be, whenever n <  m, then only 1 way is there to place the tiles i.e 1*m horizontal tiles
// whenever n==m, then 1 way from previous case and other way using verical tiles 
// memoize the solution using 1d dp as only 1 parameter is changing  

//link :- https://www.geeksforgeeks.org/problems/count-the-number-of-ways-to-tile-the-floor-of-size-n-x-m-using-1-x-m-size-tiles0509/1

class Solution {
  private:
    int mod = 1e9+7;  
  
    int solve(int row, int col, vector<int> &dp){
        // base case
        // only hoizontal way possible
        if(row < col)   return 1;
        // both horizontal and vertical arrangement possible
        if(row == col)  return 2;
        // memoization step
        if(dp[row] != -1)
            return dp[row];
        
        // place one tile in horizontal way and rest depends on sub-problem
        int opn1 = solve(row-1, col, dp) % mod;
        // place row*col tile in vertical way and rest depends on sub-problem
        int opn2 = solve(row-col, col, dp) % mod;
        // total ways will be sum of both 
        return dp[row] = (opn1 + opn2) % mod;
    }
  
  
  public:
    int countWays(int n, int m) {
        // initialize the 2d dp with -1
        vector<int> dp(n+1, -1);
        return solve(n, m, dp);
    }
};