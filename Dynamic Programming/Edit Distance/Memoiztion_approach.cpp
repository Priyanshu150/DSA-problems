#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(N*M)
// Space complexity :- O(N*M*max(M, N)), where max(M, N) is auxilary stack space 

// Approach :-
// we've to try all possible ways inorder to find the minimum operation for which we can use recursion
// For state we can use indexes i & j which we're use to traversing the two string starting from back side
// Trying all possibilities which is
// for insert, we can assume that we've put a char so j become j-1, i remains same because we're still to mach them
// for deleting, we can assume that we've deleted current i index char of s1 and hence we move to i-1, j remains same because we've yet to match it
// for repalcing, we can assume we replace the char and the indexes will be i-1 and j-1 reptively
// whichever step gives me minimum operation + 1 for current answer will be our final results 
// the base case will be, when i < 0 => that means we've to add all the j+1 char left to s1 hence we return j+1
// and when j<0 => then we've to delete all the i+1 char hence we return i+1 

// we can memoize the result based on 2 state using dp

// Link :- https://www.geeksforgeeks.org/problems/edit-distance3702/1

class Solution {
  private:
    int helper(int i, int j, string &s1, string &s2, vector<vector<int>> &dp){
        if(i == 0)      return j;
        if(j == 0)      return i;
        if(dp[i][j] != -1)      return dp[i][j];
        
        if(s1[i-1] == s2[j-1])
            return dp[i][j] = helper(i-1, j-1, s1, s2, dp);
        
        int insert = helper(i, j-1, s1, s2, dp);
        int rem = helper(i-1, j, s1, s2, dp);
        int replace = helper(i-1, j-1, s1, s2, dp);
        
        return dp[i][j] = 1 + min({insert, rem, replace});
    }
  
  public:
    // Function to compute the edit distance between two strings
    int editDistance(string& s1, string& s2) {
        // code here
        int n = s1.size(), m = s2.size();
        vector<vector<int>> dp(n+1, vector<int> (m+1, -1));
        return helper(n, m, s1, s2, dp);
    }
};