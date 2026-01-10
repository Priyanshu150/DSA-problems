#include<bits/stdc++.h>
using namespace std;

//Time complexity :- O(n*m)
//Space complexity :- O(n*m)

//link :- https://leetcode.com/problems/minimum-ascii-delete-sum-for-two-strings/

class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();
        vector<vector<int>> dp(n+1, vector<int> (m+1, 0));

        int sum = 0;
        for(int j=1; j<=m; ++j){
            sum += s2[j-1];
            dp[0][j] = sum;
        }

        sum = 0;
        for(int i=1; i<=n; ++i){
            sum += s1[i-1];
            dp[i][0] = sum;
        }
        
        for(int i=1; i<=n; ++i){
            for(int j=1; j<=m; ++j){
                if(s1[i-1] == s2[j-1])
                    dp[i][j] = dp[i-1][j-1];
                else 
                    dp[i][j] = min(s1[i-1] + dp[i-1][j], s2[j-1] + dp[i][j-1]);
            }
        }
        return dp[n][m];
    }
};