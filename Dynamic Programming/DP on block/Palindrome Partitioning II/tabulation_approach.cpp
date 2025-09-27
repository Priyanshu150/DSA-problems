#include<bits/stdc++.h>
using namespace std;

//Time complexity :- O(N*N + N^2)
//Space complexity :- O(N*N + N) 

// Approach :-
// use recursion + dp pre-compute wheather a range in the string is palindrome or not 
// Then try creating every valid partition of string which is palindrome 
// by creating every partition get the minimum partition 
// 1-d dp will suffice here as only 1 parameter is changing 
// we can follow front partition logic in this problem

//link :- https://leetcode.com/problems/palindrome-partitioning-ii/

class Solution {
private:
    bool solve(int i, int j, string &s, vector<vector<int>> &dp){
        if(i > j)
            return true;

        if(dp[i][j] != -1)
            return dp[i][j];
        
        bool ans = false;
        if(s[i] == s[j])
            ans = solve(i+1, j-1, s, dp);
        
        return dp[i][j] = ans;
    }

public:
    int minCut(string s) {
        int n = s.size();
        vector<vector<int>> isPalindrome(n, vector<int> (n, -1));

        for(int i=0; i<n; ++i){
            for(int j=i; j<n; ++j){
                solve(i, j, s, isPalindrome);
            }
        }
        vector<int> dp(n+1, n);
        dp[n] = 0;

        for(int ind=n-1; ind>=0; --ind){
            for(int i=ind; i<n; ++i){
                if(isPalindrome[ind][i]){
                    dp[ind] = min(dp[ind], 1 + dp[i+1]);
                }
            }
        }
        return dp[0] - 1;
    }
};