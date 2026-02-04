#include<bits/stdc++.h>
using namespace std;

//Time complexity :- O(n*4)
//Space complexity :- O(n*4) 

// Approach :-
// explore all possibilities to create the pattern using recursion 
// keep a 'trend' variable to keep track of increasing/decresing slope
// changing parameter will be (ind, trend)
// explore all possibility of creating the trends 
// base case will be when we reach at end index and we're present at last trend return 0
// and memoize the solution using 2d dp of size (n*4)

//link :- https://leetcode.com/problems/trionic-array-ii/description/

class Solution {
private:
    typedef long long ll;
    int n;

    ll solve(int ind, int trend, vector<int> &nums, vector<vector<ll>> &dp){
        // base case, reached at end of array 
        if(ind == n){
            // we completed all the trend 
            if(trend == 3)
                return 0;
            
            // the trend left un-complete 
            return LLONG_MIN/2;
        }
        if(dp[ind][trend] != LLONG_MIN)
            return dp[ind][trend];

        ll notTake = LLONG_MIN/2, take = LLONG_MIN/2;
        // didn't started trend yet 
        if(trend == 0){
            notTake = solve(ind+1, 0, nums, dp);
        }
        // at last trend, stop at current index 
        if(trend == 3){
            take = nums[ind];
        }

        if(ind+1 < n){
            int next = nums[ind+1], curr = nums[ind];
            // start the trend with current index 
            if(trend == 0 && next > curr){
                take = max(take, curr + solve(ind+1, 1, nums, dp));
            }
            // first increasing trend 
            else if(trend == 1){
                // continue the trend
                if(next > curr){
                    take = max(take, curr + solve(ind+1, 1, nums, dp));
                }
                // start the decreasing one 
                else if(next < curr){
                    take = max(take, curr + solve(ind+1, 2, nums, dp));
                }
            }
            // decreasing trend
            else if(trend == 2){
                // continue the trend 
                if(next < curr){
                    take = max(take, curr + solve(ind+1, 2, nums, dp));
                }
                // started the second increasing trend 
                else if(next > curr){
                    take = max(take, curr + solve(ind+1, 3, nums, dp));
                }
            }
            // seocnd increasing trend 
            else if(trend == 3 && next > curr){
                take = max(take, curr + solve(ind+1, 3, nums, dp));
            }
        }
        // max of both case 
        return dp[ind][trend] = max(notTake, take);
    }


public:
    long long maxSumTrionic(vector<int>& nums) {
        n = nums.size();
        vector<vector<ll>> dp(n+1, vector<ll> (4, LLONG_MIN));
        return solve(0, 0, nums, dp);
    }
};