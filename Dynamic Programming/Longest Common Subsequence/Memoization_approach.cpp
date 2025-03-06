#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(N*M*(N+M))
// Space complexity :- O(N*M)

// Approach :-
// Express everything in terms of i,j which are indexes of string s1 & s2
// Try out all posibilites, if(s1[i] == s1[j])  then decrese both index
// otherwise decrease both the index by 1 at a time find the max length
// base case, when we exhaust both the string
// memoize the state using 2d DP because we're having two changing variables 

// Link :- https://www.geeksforgeeks.org/problems/longest-common-subsequence-1587115620/1

class Solution{
    public:
    int lcs(string s1, string s2, int n, int m, vector<vector<int>> &dp){
        if(n==0 || m==0)
            return 0;
            
        if(dp[n][m] != -1)
            return dp[n][m];
            
        if(s1[n-1] == s2[m-1])
            dp[n][m] = 1+lcs(s1,s2,n-1,m-1,dp);
        else
            dp[n][m] = max((lcs(s1,s2,n-1,m,dp)),lcs(s1,s2,n,m-1,dp));
            
        return dp[n][m];
    }
    
    int lcs(int n, int m, string s1, string s2){
        // your code here
        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
        return lcs(s1,s2,n,m,dp);
    }
};