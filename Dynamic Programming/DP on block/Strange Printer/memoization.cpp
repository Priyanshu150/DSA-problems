#include<bits/stdc++.h>
using namespace std;

//Time complexity :- O(N*N*N)
//Space complexity :- O(N*N)

// Approach :-
// For optimal print strategy we've to try every possible partition 
// first possibilities will be, we try basic printing i.e. printing every continuous char
// second possiblities will be we go on exploring the next char which is same print till that index
// print the middle char and the all the char after that (i.e subproblem)
// solve(next_ind_after_consecutive, matching_prev_ind) + solve(matching_ind, lat_ind) 
// looping on all the possibilties we'll try find the minimum printing answer 
// solve(matching_ind, lat_ind) => this covers the case of printing from starting till the contiuouse index after break
// since there are only 2 parameter changing we'll be needing 2-d dp to memoize it 

//link :- https://leetcode.com/problems/strange-printer/

class Solution {
private:
    int n;

    int solve(int i, int j, string &s, vector<vector<int>> &dp){
        if(i == j)      return 1;
        if(i > j)       return 0;
        if(dp[i][j] != -1)
            return dp[i][j];

        int ind = i+1;
        while(ind <= j && s[ind] == s[i])
            ind++;
        
        // all char was printed
        if(ind == j+1)
            return 1;
        
        // print continuous char by char  
        int basic = 1 + solve(ind, j, s, dp), res = INT_MAX;
        // print optimally by printing extra char 
        for(int k=ind; k<=j; ++k){
            if(s[k] == s[i]){
                int steps = solve(ind, k-1, s, dp) + solve(k, j, s, dp);
                res = min(res, steps);
            }
        }
        return dp[i][j] = min(res, basic);
    }

public:
    int strangePrinter(string s) {
        n = s.size();
        vector<vector<int>> dp(n, vector<int> (n, -1));
        return solve(0, n-1, s, dp);
    }
};