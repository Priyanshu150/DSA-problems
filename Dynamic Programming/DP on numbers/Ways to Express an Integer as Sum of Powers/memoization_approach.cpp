#include<bits/stdc++.h>
using namespace std;

//Time complexity :- O(300*n)
//Space complexity :- O(300*n*n) where one of the n represents the stack space 

// Approach :-
// Express everything in terms of num(0 to 300) and target(n)
// there will 2 case take and not take
// we'll count the sum of both the cases which will be our answer 
// and the base case will be when target reaches 0 return 1 otherwise when num reaches 0 return 0
// since there are 2 changing parameter we can use 2-d dp to express the same 


//link :- https://leetcode.com/problems/ways-to-express-an-integer-as-sum-of-powers/


class Solution {
private:
    int mod = 1e9+7;

    int solve(int num, int target, int x, vector<vector<int>> &dp){
        if(target == 0)     return 1;
        if(num == 0)        return 0;
        if(dp[num][target] != -1)
            return dp[num][target];

        int notTake = solve(num-1, target, x, dp), take = 0;
        long long val = pow(num, x);
        if(val <= target)
            take = solve(num-1, target - val, x, dp);
        
        return dp[num][target] = (take + notTake) % mod;
    }

public:
    int numberOfWays(int n, int x) {
        vector<vector<int>> dp(301, vector<int> (n+1, -1));
        return solve(300, n, x, dp);
    }
};