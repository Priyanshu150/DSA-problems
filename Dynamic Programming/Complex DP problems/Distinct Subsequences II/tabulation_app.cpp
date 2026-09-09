#include <bits/stdc++.h>
using namespace std;

//Time complextiy :- O(n)
// Space complexity :- O(n)

// Approach :-  
// convert the memoization solution to tabulation solution by using iterative approach 
// and storing the values in dp array instead of recursive calls


//Link :- https://leetcode.com/problems/distinct-subsequences-ii/

class Solution {
public:
    int distinctSubseqII(string s) {
        int n = s.size();
        int mod = 1e9+7;

        vector<int> lastInd(26, 0), prev(n+1, 0);

        for(int i=1; i<=n; ++i){
            int ind = s[i-1] - 'a';
            prev[i] = lastInd[ind];
            lastInd[ind] = i;
        }
        vector<int> dp(n+1, 0);
        dp[0] = 1;

        for(int num=1; num<=n; ++num){
            dp[num] = (dp[num-1] * 2 ) % mod;

            if(prev[num] != 0){
                int duplicates = dp[prev[num]-1];
                dp[num] = (dp[num] - duplicates + mod) % mod;
            }
        }
        return (dp[n] + mod -1) % mod;
    }
};