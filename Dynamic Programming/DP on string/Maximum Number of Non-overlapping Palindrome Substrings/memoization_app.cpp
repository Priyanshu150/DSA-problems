#include <bits/stdc++.h>
using namespace std;

//Time complextiy :- O(n^3)
// Space complexity :- O(n^2)

// Approach :-  
// 1. We will use a recursive function to find the maximum number of non-overlapping palindrome substrings of length k.
// 2. We will use a 2D dp array to store the results of subproblems.
// 3. We will check if the current substring is a palindrome or not.


//Link :- https://leetcode.com/problems/maximum-number-of-non-overlapping-palindrome-substrings/description/

class Solution {
private:
    // check current substring is palindrome or not
    bool isPalindrome(int i, int j, string &s){
        while(i < j){
            if(s[i] != s[j])
                return false;
            
            i++;
            j--;
        }
        return true;
    }

    int solve(int i, int j, string &s, int &k, vector<vector<int>> &dp){
        int n = s.size();
        // base case
        if(i >= n || j >= n)    return 0;
        // memoization check
        if(dp[i][j] != -1)      return dp[i][j];
        
        // if current substring is palindrome then we have 3 choices
        if(isPalindrome(i, j, s)){
            // grow the window
            int growWindow = solve(i, j+1, s, k, dp);
            // take it, and move the window to next substring of length k
            int takeIt = 1 + solve(j+1, j+k, s, k, dp);
            // slide the window to next substring of length k
            int slide = solve(i+1, j+1, s, k, dp);

            return dp[i][j] = max({growWindow, takeIt, slide});
        }
        // if current substring is not palindrome then we have 2 choices
        // grow the window or slide the window
        int growWindow = solve(i, j+1, s, k, dp);
        int slide = solve(i+1, j+1, s, k, dp);

        return dp[i][j] = max(growWindow, slide);
    }

public:
    int maxPalindromes(string s, int k) {
        int n = s.size();
        // k is 1, then all characters are palindromes of length 1, so return n
        if(k == 1)      return n;
        // 3d dp array initalization with -1
        vector<vector<int>> dp(n+1, vector<int> (n+1, -1));
        return solve(0, k-1, s, k, dp);
    }
};