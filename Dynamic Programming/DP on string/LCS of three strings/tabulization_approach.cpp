#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(n^3)
// Space complexity :- O(n^3)

// Approach :- 
// using lcs on 2 string tabulation approach

// Link :- https://www.geeksforgeeks.org/problems/lcs-of-three-strings0028/1

class Solution
{
    public:
    int LCSof3 (string a, string b, string c, int n1, int n2, int n3){
        // your code here
        vector<vector<vector<int>>> dp(n1+1, vector<vector<int>> (n2+1, vector<int> (n3+1, 0)));
        for(int i=1; i<=n1; ++i){
            for(int j=1; j<=n2; ++j){
                for(int k=1; k<=n3; ++k){
                    if(a[i-1] == b[j-1] && b[j-1] == c[k-1])
                        dp[i][j][k] = 1 + dp[i-1][j-1][k-1];
                    else
                        dp[i][j][k] = max({dp[i-1][j][k], dp[i][j-1][k], dp[i][j][k-1]});
                }
            }
        }
        return dp[n1][n2][n3];
    }
};