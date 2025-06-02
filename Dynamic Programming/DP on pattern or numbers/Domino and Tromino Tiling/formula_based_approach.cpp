#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(n)
// Space complexity :- O(n)

// Approach :-
// for 1 will have 1, 2 will have 2, 3 will have 5 and 4 will have 11 ways in total
// using the sequence we can deduce the formulat that dp[i] = 2*dp[i-1] + dp[i-3]


// Link :- https://leetcode.com/problems/domino-and-tromino-tiling/

class Solution {
public:
    int numTilings(int n) {
        int mod = 1e9 + 7;
        vector<int> dp(n+2, 1);
        dp[2] = 2; 

        for(int i=3; i<=n; ++i)
            dp[i] = ((2*dp[i-1])%mod + dp[i-3]) % mod;
        
        return dp[n];
    }
};