#include<bits/stdc++.h>
using namespace std;

//Time complexity :- O(300*n)
//Space complexity :- O(300*n)


//link :- https://leetcode.com/problems/ways-to-express-an-integer-as-sum-of-powers/

class Solution {
public:
    int numberOfWays(int n, int x) {
        int mod = 1e9+7;
        vector<vector<int>> dp(301, vector<int> (n+1, 0));

        for(int num=0; num<301; ++num)
            dp[num][0] = 1;
        
        for(int num=1; num<301; ++num){
            for(int target=1; target<=n; ++target){
                dp[num][target] = dp[num-1][target];
                long long val = pow(num, x);
                if(val <= target)
                    dp[num][target] = (dp[num][target] + dp[num-1][target-val]) % mod;
            }
        }
        return dp[300][n];
    }
};