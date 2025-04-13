#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(n*s)  
// Space complexity :- O(n*s)

// Approach :-  
// Inorder to further optimize the space we can use tabulation approach instead of memoization
// ind will go from 1 to n and s will go from 1 to sum vice versa of memoization
// express based case explicitly for the respective cases
// express the possibilities same as memoization instead of recursion use dp array to find previous state answer
// finally the answer will be present at the last element of array

// Link :- https://www.geeksforgeeks.org/problems/subset-sum-problem-1611555638/1

class Solution {
  public:
    bool isSubsetSum(vector<int>& arr, int sum) {
        // code here
        int n = arr.size();
        vector<vector<bool>> dp(n, vector<bool> (sum+1, false));
        
        for(int ind=0; ind<n; ++ind)
            dp[ind][0] = true;
        
        for(int s=1; s<=sum; ++s){
            if(s == arr[0])
                dp[0][s] = true;
        }
        
        for(int ind=1; ind<n; ++ind){
            for(int s=1; s<=sum; ++s){
                dp[ind][s] = dp[ind-1][s];
                
                if(arr[ind] <= s)
                    dp[ind][s] = dp[ind][s] | dp[ind-1][s-arr[ind]];
            }
        }
        return dp[n-1][sum];
    }
};

class Solution {
  public:
    bool isSubsetSum(vector<int>& arr, int sum) {
        // code here
        int n = arr.size();
        vector<vector<bool>> dp(n+1, vector<bool> (sum+1, false));
        
        for(int ind=0; ind<=n; ++ind)
            dp[ind][0] = true;
        
        for(int ind=1; ind<=n; ++ind){
            for(int s=1; s<=sum; ++s){
                dp[ind][s] = dp[ind-1][s];
                
                if(arr[ind-1] <= s)
                    dp[ind][s] = dp[ind][s] | dp[ind-1][s-arr[ind-1]];
            }
        }
        return dp[n][sum];
    }
};