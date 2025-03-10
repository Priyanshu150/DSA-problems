#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(N*M)
// Space complexity :- O(N*M)

// Approach :-
// Using tabulation approach, we can delete the auxilary stack space using in memoiztion
// In dp table we can fill all the values initailly as 0
// And add the base case to the dp table accordingly 
// for index i, we will go from 1 to n 
// for index j, we will go from 1 to m
// And we can calulate each states answer depending on the logic we used in memoization
// the answer will be stored in dp table at dp[n][m]

// Link :- https://www.geeksforgeeks.org/problems/edit-distance3702/1

class Solution {
    public:
    // Function to compute the edit distance between two strings
    int editDistance(string& s1, string& s2) {
        // code here
        int n = s1.size(), m = s2.size();
        vector<vector<int>> dp(n+1, vector<int> (m+1, 0));
        
        for(int i=0; i<=n; ++i)
            dp[i][0] = i;
        
        for(int j=0; j<=m; ++j)
            dp[0][j] = j;
        
        for(int i=1; i<=n; ++i){
            for(int j=1; j<=m; ++j){
                if(s1[i-1] == s2[j-1])
                    dp[i][j] = dp[i-1][j-1];
                else{
                    int insert = dp[i][j-1];
                    int rem = dp[i-1][j];
                    int replace = dp[i-1][j-1];    
                    
                    dp[i][j] = 1 + min({insert, rem, replace});
                }
            }
        }
        return dp[n][m];
    }
};