#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(n + d)
// Space complexity :- O(n)

// Approach :-  
// starting from every index we've to explore all jumping option to find the maximum answer for us 
// using recursion we'll try to jump on the valid index of left first and then on right 
// maintain the max value accross all the jumps 
// since there will be repeating sub-problem due to only n index, we can memozie the solution 
// 1-d dp will suffice of size n for memoization 

// Link :- https://leetcode.com/problems/jump-game-v/description/

class Solution {
private:
    int solve(int ind, vector<int> &arr, int &d, int &n, vector<int> &dp){
        int maxSteps = 1;
        // memoization 
        if(dp[ind] != -1)
            return dp[ind];

        // jump on the left side 
        for(int i=ind-1; i>=max(0, ind-d); --i){
            // invalid jump condition 
            if(arr[i] >= arr[ind])
                break;
            
            int steps = solve(i, arr, d, n, dp);
            maxSteps = max(maxSteps, 1 + steps);
        }

        // jump on the right side
        for(int i=ind+1; i<=min(n-1, ind+d); ++i){
            // invalid jump condition 
            if(arr[i] >= arr[ind])
                break;
            
            int steps = solve(i, arr, d, n, dp);
            maxSteps = max(maxSteps, 1 + steps);
        }
        return dp[ind] = maxSteps;
    }

public:
    int maxJumps(vector<int>& arr, int d) {
        int n = arr.size();
        int result = 1;
        vector<int> dp(n, -1);

        // try all index as a possible starting point 
        for(int i=0; i<n; ++i){
            int steps = solve(i, arr, d, n, dp);
            result = max(steps, result);
        }
        return result;
    }
};