#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(N*M)
// Space complexity :- O(N*M)

// Approach :-
// Find the LCS among the two string 
// Whatever common part we got we've to add that only once in the result string
// rest all which are uncommon can be added in string seprately
// We'll get the lenght from LCS and for getting string we can use printing LCS algo
// While printing if we get that at both place the char are same then we'll add in once in result
// otherwise whichever char we're deleting we'll add that character and repeat the process
// Finally reverse the string 

// Link :- https://leetcode.com/problems/shortest-common-supersequence/description/

class Solution {
public:
    string shortestCommonSupersequence(string s1, string s2) {
        int n = s1.size(), m = s2.size();
        vector<vector<int>> dp(n+1, vector<int> (m+1, 0));

        for(int i=1; i<=n; ++i){
            for(int j=1; j<=m; ++j){
                if(s1[i-1] == s2[j-1])
                    dp[i][j] = 1 + dp[i-1][j-1];
                else 
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
        string res = "";
        int i = n, j = m;
        
        while(i>0 && j>0){
            if(s1[i-1] == s2[j-1]){
                res += s1[i-1];
                i -= 1;
                j -= 1;
            }
            else if(dp[i][j] == dp[i-1][j]){
                res += s1[i-1];
                i -= 1;
            }
            else{
                res += s2[j-1];
                j -= 1;
            }
        }
        while(i>0){
            res += s1[i-1];
            i -= 1;
        }
        while(j>0){
            res += s2[j-1];
            j -= 1;
        }
        reverse(res.begin(), res.end());
        return res;
    }
};