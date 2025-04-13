#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(n*n)
// Space complexity :- O(n)

// Approach :- 
// For every number we'll check all the number that occured before that
// if that number is less than then the length till current index will be 1 + length_till_prev_ind
// That ways we can repeat every index and get the maintain a maximum length variable to track max length among all


//Link :- https://www.geeksforgeeks.org/problems/longest-increasing-subsequence-1587115620/1

class Solution{
    public:
    int longestSubsequence(int n, int a[]){
       // your code here
       vector<int>dp (n, 1);
       int ans = 0;
       
       for(int i=1; i<n; i++){
           for(int j=0; j<i; j++){
                if(a[i] > a[j])
                    dp[i] = max(dp[i],1+dp[j]);

                ans = max(ans, dp[i]);
           }
       }
       return ans;
    }
};