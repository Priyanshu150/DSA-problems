#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(n*k*n)
// Space complexity :- O(n*k + n)

// Approach :-  
// Instead of generating every sequence and counting the valid permutation 
// we can directly count the number of valid combinations using recursions 
// the chaning state will be n & k 
// by placing the largest number we can make the 1 to n-1 inversion pair 
// f(n, k) => f(n-1, k-inv), where inv will be from 0 to min(k, n-1)
// that means try out all the inversion from previous number and check what will be count to attain that
// that way we'll use recursion to solve the current problem and the sub-problem 
// we can accucmulate all the possible ways 
// the base cases will be when n become 0 there will be 0 ways and k becomes 0 then it will have 1 way


//Link :- https://leetcode.com/problems/k-inverse-pairs-array/


class Solution {
private:
    int mod = 1e9+7;

    int solve(int n, int k, vector<vector<int>> &dp){
        if(n == 0) 
            return 0;
        
        if(k == 0)
            return 1; // sorted array is only valid permuation

        if(dp[n][k] != -1)
            return dp[n][k];
        
        int res = 0;
        // for any array of length n we can have at max n-1 inversions 
        for(int inv=0; inv<=min(k, n-1); ++inv){
            // if we already have inv inversion we'll only be needing k-inv inversions
            res = (res%mod + solve(n-1, k-inv, dp)%mod) % mod;
        }
        return dp[n][k] = res;
    }

public:
    int kInversePairs(int n, int k) {
        vector<vector<int>> dp(n+1, vector<int> (k+1, -1));
        return solve(n, k, dp);
    }
};