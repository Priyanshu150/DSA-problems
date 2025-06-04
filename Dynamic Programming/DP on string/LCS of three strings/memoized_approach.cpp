#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(n^3)
// Space complexity :- O(n^3 + stack_space)

// Approach :- 
// using lcs on 2 string memoization approach

// Link :- https://www.geeksforgeeks.org/problems/lcs-of-three-strings0028/1


int dp[21][21][21];

int lcs(string a, string b, string c, int n1, int n2, int n3){
    if(n1 == 0 || n2 == 0 || n3 == 0)
        return 0;
        
    if(dp[n1][n2][n3] != -1)
        return dp[n1][n2][n3];
        
    if(a[n1-1] == b[n2-1] && b[n2-1] == c[n3-1])
        dp[n1][n2][n3] =  1+lcs(a,b,c,n1-1,n2-1,n3-1);
    else{
        int one = lcs(a,b,c,n1-1,n2,n3);
        int two = lcs(a,b,c,n1,n2-1,n3);
        int three = lcs(a,b,c,n1,n2,n3-1);
        dp[n1][n2][n3] = max({one,two,three});
    }
    return dp[n1][n2][n3];
}

int LCSof3 (string A, string B, string C, int n1, int n2, int n3){
    memset(dp,-1,sizeof(dp));
    return lcs(A,B,C,n1,n2,n3);
}