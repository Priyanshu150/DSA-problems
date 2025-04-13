#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(N*M)
// Space complexity :- O(N*M)

// Approach :-
// There are two states that are changing which are index of both the string
// In the memoization we're moving n to 1 so in tablulation we'll loop from 1 to n and vice versa
// Using same logic we'll write the loop for string s2
// Set all the values of string to 0 because initally common string will be of length 0
// repeat the same possiblites in term of dp states and calulate the length till that indexes
// the ans will be stored at dp[n][m] 

// Link :- https://www.geeksforgeeks.org/problems/longest-common-subsequence-1587115620/1

class Solution{
    public:
    //Function to find the length of longest common subsequence in two strings.
    int lcs(int n, int m, string s1, string s2){
        vector<vector<int>> dp(n+1, vector<int> (m+1, 0));
        
        for(int i=1; i<=n; ++i){
            for(int j=1; j<=m; ++j){
                if(s1[i-1]==s2[j-1])
                    dp[i][j] = 1 + dp[i-1][j-1];
                else
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
        return dp[n][m];
    }
};