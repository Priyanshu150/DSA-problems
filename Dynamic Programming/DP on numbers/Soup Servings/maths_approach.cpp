#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(n*n)  
// Space complexity :- O(n*n)

// Approach :-
// probability of 'a' when it finishes first is 1.0 i.e if(a <= 0)  return 1.0
// probability of 'a' and 'b' finishes at same time is 0.5 i.e if(a <= 0 && b <= 0) return 0.5
// probability of 'b' when it finishes first is 1.0 i.e if(b <= 0)  return 0.0
// explore all the possibilities and take sum of them 
// each has a probability of 0.25 to occur hence multiply the summation with that 
// use 2-dp to memoize the solution
// since the n is to large i.e. 1e9 the test case will fail
// so we can say that for larger number the probility will be as close as 1.0
// hence we can say that if(n >= 4000) return 1.0, why 4000 ? hit and trial 


// Link :- https://leetcode.com/problems/soup-servings/

class Solution {
private:
    double solve(int a, int b, vector<vector<double>> &dp){
        if(a <= 0 && b <= 0)        return 0.5;
        if(a <= 0)      return 1.0;
        if(b <= 0)      return 0.0;
        if(dp[a][b] != -1)  return dp[a][b];

        double p1 = solve(a-100, b, dp);
        double p2 = solve(a-75, b-25, dp);
        double p3 = solve(a-50, b-50, dp);
        double p4 = solve(a-25, b-75, dp);

        return dp[a][b] = (p1 + p2 + p3 + p4)*0.25;
    }

public:
    double soupServings(int n) {
        if(n >= 4000)       return 1;
        vector<vector<double>> dp(n+1, vector<double> (n+1, -1));
        return solve(n, n, dp);
    }
};