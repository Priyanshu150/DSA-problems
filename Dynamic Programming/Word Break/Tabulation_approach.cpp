#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(n*m*n)
// Space complexity :- O(n)

//Link :- https://www.geeksforgeeks.org/problems/word-break1352/1

class Solution {
  public:
    bool wordBreak(string &s, vector<string> &dictionary) {
        int n = s.size();
        vector<bool> dp(n + 1, false);
        dp[0] = true;  

        for (int i = 0; i < n; i++) {
            if (!dp[i])
                continue;
            for (const string &word : dictionary) {
                int len = word.size();
           
                if (i + len <= n && s.substr(i, len) == word) {
                    dp[i + len] = true;
                }
            }
        }
        return dp[n] ? 1 : 0;
    }
};