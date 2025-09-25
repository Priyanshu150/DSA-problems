#include<bits/stdc++.h>
using namespace std;

//Time complexity :- O(N^2)
//Space complexity :- O(N) 

// Approach :-
// index will be our changing parameter 
// we'll try all the possibilities using for loop which will go to at max k times 
// maintian a variable with maximum element seen till now 
// whatever number of element we select, we can multiply it with length and call the sub-problem f(i+1)
// the base case will be when ind reach end i.e n return 0
// the is only 1 parameter chaning hence 1-d dp will suffice 


//link :- https://leetcode.com/problems/partition-array-for-maximum-sum/

class Solution {
private:
    int solve(int ind, int &n, vector<int> &arr, int &k, vector<int> &dp){
        if(ind == n)
            return 0;
        if(dp[ind] != -1)
            return dp[ind];
        
        int res = 0, maxi = 0;

        for(int i=ind; i<min(n, ind+k); ++i){
            maxi = max(maxi, arr[i]);
            int val = maxi*(i - ind + 1) + solve(i+1, n, arr, k, dp);
            res = max(res, val);
        }
        return dp[ind] = res;
    }

public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> dp(n, -1);
        return solve(0, n, arr, k, dp);
    }
};
