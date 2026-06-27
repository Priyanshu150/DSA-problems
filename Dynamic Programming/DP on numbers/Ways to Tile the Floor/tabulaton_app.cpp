#include<bits/stdc++.h>
using namespace std;

//Time complexity :- O(N)
//Space complexity :- O(N)

// Approach :-
// convert the memoization approach to tabulation one 

//link :- https://www.geeksforgeeks.org/problems/count-the-number-of-ways-to-tile-the-floor-of-size-n-x-m-using-1-x-m-size-tiles0509/1

class Solution {
  public:
    int countWays(int n, int m) {
        int mod = 1e9+7; 
        // initialize the 1d dp with 0
        vector<int> dp(n+1, 0);
        
        for(int row=1; row<=n; ++row){
            // only hoizontal way possible
            if(row < m){
                dp[row] = 1;
            }
            // both horizontal and vertical arrangement possible
            else if(row == m){
                dp[row] = 2;
            }
            else{
                // place one tile in horizontal way and rest depends on sub-problem
                // place row*col tile in vertical way and rest depends on sub-problem
                // total ways will be sum of both 
                dp[row] = (dp[row-1] + dp[row - m]) % mod;
            }
        }
        return dp[n];
    }
}