#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(n*k*n)
// Space complexity :- O(n*k)

// Approach :-  
// using the memoization approach, convert the same to tabulation 
// initialize dp to 0, and whenever the k=0 the for all n value set dp state to 1 
// i = 1 to n and j = 1 to k, which was our 2 chaning state 
// rest possibility remains same from the recursion


//Link :- https://leetcode.com/problems/k-inverse-pairs-array/

class Solution {
public:
    int kInversePairs(int n, int k) {
        int mod = 1e9+7;
        vector<vector<int>> dp(n+1, vector<int> (k+1, 0));

        for(int i=1; i<=n; ++i){
            // sorted array is only valid permuation
            dp[i][0] = 1;
        }
        
        for(int i=1; i<=n; ++i){
            for(int j=1; j<=k; ++j){
                // for any array of length n we can have at max n-1 inversions 
                for(int inv=0; inv<=min(j, i-1); ++inv){
                    // if we already have inv inversion we'll only be needing k-inv inversions
                    dp[i][j] = (dp[i][j]%mod + dp[i-1][j-inv]%mod) % mod;
                }
            }
        }
        return dp[n][k];
    }
};