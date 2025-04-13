#include<bits/stdc++.h>
using namespace std;

//Time complexity :- O(n)
//Space complexity :- O(n + stack_space)

// Approach :-
// We've to try all possbilities for which we can use recursive approach
// Index(ind) will be the only changing parameter here 
// we can consider the possibilites of take and notTake for each index
// and finally returning max of both possibilities
// base case will be if ind >= n then return 0
// Traversing 0 to n-1 will be easier than n-1 to 0, as from 1 if we skip 2 char we'll end at -ve ind
// we'll call the recursion twice because either starting from 0 and 1 will give max answer

// since only 1 state is changing we can memoize the solution using 1-d dp array
// initialize a dp array of size 1 with -1 value, save the answer for calculate state inorder to avoid recalculation

//link :- https://www.geeksforgeeks.org/problems/stickler-theif-1587115621/1

class Solution {
  private:
    int solve(int ind, int &n, vector<int> &arr, vector<int> &dp){
        if(ind >= n)    return 0;
        if(dp[ind] != -1)   return dp[ind];
        
        int notTake = solve(ind+1, n, arr, dp);
        int take = arr[ind] + solve(ind+2, n, arr, dp);
        return dp[ind] = max(notTake, take);
    }
    
  public:
    int findMaxSum(vector<int>& arr) {
        // code here
        int n = arr.size();
        vector<int> dp(n, -1);
        return max(solve(1, n, arr, dp), solve(0, n, arr, dp));
    }
};