#include<bits/stdc++.h>
using namespace std;

// Time Complexity: O(n*m)
// Space Complexity: O(n*m)

// Approach :- 
// we've to try all possible ways to find the possible maximum answer 
// instead of maintain a single answer we will main a pair of integer 
// one which is mini observed in the path and other which is maxi observed in the path
// minimum because if we multiply it with -ve number it will give us the biggest value 
// we'll use the same approach from maximum path in grid 
// memozie the solution using n*m matrix where each cell stores a pair value 


// Link :- https://leetcode.com/problems/maximum-non-negative-product-in-a-matrix/

class Solution {
private:
    int n, m;
    typedef long long ll;
    typedef pair<ll,ll> pll;

    pll solve(int row, int col, vector<vector<int>>& grid, vector<vector<pair<ll,ll>>> &dp){
        int value = grid[row][col];
        if(row == n-1 && col == m-1){
            return {value, value};
        }
        if(dp[row][col] !=  make_pair(LLONG_MIN, LLONG_MAX))
            return dp[row][col];

        ll maxVal = LLONG_MIN, minVal = LLONG_MAX;
        
        if(row+1 < n){
            pll next = solve(row+1, col, grid, dp);
            maxVal = max<ll>({maxVal, next.first * value, next.second *value});
            minVal = min<ll>({minVal, next.first * value, next.second *value});
        }
        if(col+1 < m){
            pll next = solve(row, col+1, grid, dp);
            maxVal = max<ll>({maxVal, next.first * value, next.second *value});
            minVal = min<ll>({minVal, next.first * value, next.second *value});
        }
        return dp[row][col] = {maxVal, minVal};
    }

public:
    int maxProductPath(vector<vector<int>>& grid) {
        int mod = 1e9+7;
        n = grid.size();
        m = grid[0].size();
        vector<vector<pair<ll,ll>>> dp(n, vector<pair<ll,ll>> (m, {LLONG_MIN, LLONG_MAX}));

        ll ans = solve(0,0,grid,dp).first;
        return (ans < -1) ? -1 : ans % mod;
    }
};