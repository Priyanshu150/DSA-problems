#include <bits/stdc++.h>
using namespace std;

//Time complextiy :- O(n)
// Space complexity :- O(n)

// Approach :-  
// for solving these problem instead of generating all the subsequences
// we can use find the sequence generated at each level which will be 2*times_of_previous_level


//Link :- https://leetcode.com/problems/distinct-subsequences-ii/

class Solution {
private:
    int mod = 1e9+7;

    int solve(int num, vector<int> &dp, vector<int> &prev){
        if(num == 0)
            return 1;
        
        if(dp[num] != -1)
            return dp[num];
        
        int total = (solve(num-1, dp, prev) * 2 ) % mod;

        if(prev[num] != 0){
            int duplicates = solve(prev[num]-1, dp, prev);
            total = (total - duplicates + mod) % mod;
        }
        return dp[num] = total;
    }

public:
    int distinctSubseqII(string s) {
        int n = s.size();
        vector<int> lastInd(26, 0), prev(n+1, 0);

        for(int i=1; i<=n; ++i){
            int ind = s[i-1] - 'a';
            prev[i] = lastInd[ind];
            lastInd[ind] = i;
        }
        vector<int> dp(n+1, -1);
        return (solve(n, dp, prev) - 1 + mod) % mod;
    }
};