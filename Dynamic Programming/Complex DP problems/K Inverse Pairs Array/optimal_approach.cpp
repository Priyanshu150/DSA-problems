#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(n*k)
// Space complexity :- O(n*k)

// Approach :-  
// If we further oberserve the dp tabulation approach then we'll find that 
// the curr dp[i][j] is equal to sum of previous rows row's number of element 

//Link :- https://leetcode.com/problems/k-inverse-pairs-array/

class Solution {
public:
    int kInversePairs(int n, int k) {
        int mod = 1e9+7;
        vector<vector<int>> dp(n+1, vector<int> (k+1, 0));

        for(int i=0; i<=n; ++i){
            dp[i][0] = 1;
        }
        
        for(int i=1; i<=n; ++i){
            long long currSum = 1;
            for(int j=1; j<=k; ++j){
                currSum += dp[i-1][j];
                if(j >= i)
                    currSum -= dp[i-1][j-i];
                
                dp[i][j] = currSum % mod;
            }
        }
        return dp[n][k];
    }
};