#include<bits/stdc++.h>
using namespace std;

// Time complexity :- O(n)                  // Where n is size of array 
// Space complexity :- O(n+n)               // n is space for dp arrays and stack space

// Approach :-
// we've to try all possibilities to get max score, we can use recursion for the same 
// ind will be the changing parameter, and we've to try all possibilities 
// notTake will be move to next index without considering current one 
// take case will be take curr score and skip questions[ind][1] index and move to next of that 
// take max of both screnario and base case will be when ind>=n return 0

// memoize the solution based to avoid recalculation of subproblem and storing the answer for the same
// since only 1 parameter is changing 1d dp will suffice 


// Links :- https://leetcode.com/problems/solving-questions-with-brainpower/

class Solution {
private:
    #define ll long long

    ll solve(int ind, int &n, vector<vector<int>>& questions, vector<ll> &dp){
        if(ind >= n)    return 0;
        if(dp[ind] != -1)       return dp[ind];

        ll notTake = solve(ind+1, n, questions, dp);
        ll take = (ll)questions[ind][0] + solve(ind+questions[ind][1]+1, n, questions, dp);

        return dp[ind] = max(take, notTake);
    }

public:
    long long mostPoints(vector<vector<int>>& questions) {
        int n = questions.size();
        vector<ll> dp(n, -1);
        return solve(0, n, questions, dp);
    }
};