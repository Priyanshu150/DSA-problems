#include<bits/stdc++.h>
using namespace std;

//Time complexity :- O(n*m)
//Space complexity :- O(n*m + recursion_stack)

// Approach :-
// we'll try all possibilities to find the min answer 
// we can use the concept of lcs and slightly change the logic
// states will i,j pointer of two string 
// base case will be sum of all the char when other string expires 
// if current index of both are matching check for f(i-1, j-1)
// otherwise delete one char from either of string and check which one give minimum answer
// memoize the solution using 2d dp array solution 

//link :- https://leetcode.com/problems/minimum-ascii-delete-sum-for-two-strings/

class Solution {
private:
    int solve(int i, int j, string &s1, string &s2, vector<vector<int>> &dp){
        int &ans = dp[i][j];

        if(i==0){
            int sum = 0;
            while(j > 0){
                sum += s2[j-1];
                j--;
            }
            return sum;
        }

        if(j==0){
            int sum = 0;
            while(i > 0){
                sum += s1[i-1];
                i--;
            }
            return sum;
        }
        
        if(ans != -1)
            return ans;
        
        if(s1[i-1] == s2[j-1])
            return ans = solve(i-1, j-1, s1, s2, dp);
        
        int op1 = s1[i-1] + solve(i-1, j, s1, s2, dp);
        int op2 = s2[j-1] + solve(i, j-1, s1, s2, dp);
        return ans = min(op1, op2);
    }

public:
    int minimumDeleteSum(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();
        vector<vector<int>> dp(n+1, vector<int> (m+1, -1));
        return solve(n, m, s1, s2, dp);
    }
};