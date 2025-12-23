#include<bits/stdc++.h>
using namespace std;

//Time complexity :- O(n*m)
//Space complexity :- O(n*m) 

// Approach :-
// * represents that any character before it can be represent 0, 1 or more number of time 
// ex - a* => '', a, aa, aaa, ...  &    .* => '', a, aa, b, bb, c, cc, ccc or so on 
// '.' matches with only one character 
// matching a char with char or '.' with character is straight forward 
// for '*', we have to try take or notTake case which will cover all the possibilities 
// we'll take | of all case so that even if one case returns true then it's possible 
// we can memoize the solution using 2d dp of size n*m

//link :- https://leetcode.com/problems/regular-expression-matching/

// Approach 1 
class Solution {
private:
    bool solve(int i, int j, int &n, int &m, string &s, string &p, vector<vector<int>> &dp){
        // base case 
        if(j == m){
            return (i == n);
        }
        // either of the string expires without satisfying the first condition then it's not possible 
        if(i == n || j == m){
            return false;
        }
        // dp check 
        if(dp[i][j] != -1)
            return dp[i][j];

        // condition when just next char is '*'
        if(j+1<m && p[j+1] == '*'){
            // don't match with any input string then skip the '*' and char before that 
            bool notTake = solve(i, j+2, n, m, s, p, dp), take = false;

            if((s[i] == p[j]) || (p[j] == '.')){
                // stays at same index to check more possibilities of matching 
                take |= solve(i+1, j, n, m, s, p, dp);
            }
            return dp[i][j] = notTake | take;
        }
        // input string matches with the char or '.'
        if((s[i] == p[j]) || (p[j] == '.')){
            return dp[i][j] = solve(i+1, j+1, n, m, s, p, dp);
        }
        // not match found 
        return dp[i][j] = false;
    }

public:
    bool isMatch(string s, string p) {
        int n = s.size(), m = p.size();
        vector<vector<int>> dp(n+1, vector<int> (m+1, -1));
        return solve(0, 0, n, m, s, p, dp);
    }
};

// Approach 2 
class Solution {
private:
    bool solve(int i, int j, int &n, int &m, string &s, string &p, vector<vector<int>> &dp){
        // base case 
        if(i == n){
            // if j is still left, check at odd index it should be "*"
            for(int ind=j+1; ind<m; ind+=2){
                if(p[ind] != '*')
                    return false;
            }
            // last char has to match if it's not '*'
            if(j < m && p[m-1] != '*')
                return false;
            // otherwise it's always possible 
            return true;
        }
        // either of the string expires without satisfying the first condition then it's not possible 
        if(i == n || j == m){
            return false;
        }
        // dp check 
        if(dp[i][j] != -1)
            return dp[i][j];

        // condition when just next char is '*'
        if(j+1<m && p[j+1] == '*'){
            if((s[i] == p[j]) || (p[j] == '.')){
                // stays at same index to check more possibilities of matching 
                bool opn1 = solve(i+1, j, n, m, s, p, dp);
                // move to next index assuming this is last matching char with '*'
                bool opn2 = solve(i+1, j+2, n, m, s, p, dp);
                // don't match with any input string then skip the '*' and char 
                bool opn3 = solve(i, j+2, n, m, s, p, dp);
                // don't match any 

                return dp[i][j] = opn1 | opn2 | opn3;
            }
            // don't match with any input string then skip the '*' and char before that 
            return dp[i][j] = solve(i, j+2, n, m, s, p, dp);
        }
        // input string matches with the char or '.'
        if((s[i] == p[j]) || (p[j] == '.')){
            return dp[i][j] = solve(i+1, j+1, n, m, s, p, dp);
        }
        // not match found 
        return dp[i][j] = false;
    }

public:
    bool isMatch(string s, string p) {
        int n = s.size(), m = p.size();
        vector<vector<int>> dp(n+1, vector<int> (m+1, -1));
        return solve(0, 0, n, m, s, p, dp);
    }
};