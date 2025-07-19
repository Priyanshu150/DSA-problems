#include<bits/stdc++.h>
using namespace std;

//Time complexity :- O(n*k)
//Space complexity :- O(k*k)

// Approach :-
// for find the maximum length the sequence should be either of equal element or alternating element 
// for every modulo value of k we'll find the alternating or equal sequence for current element
// so the state of dp[curr][prev] = 1 + dp[prev][curr]
// which represents for the curr value for all prev will be the prev's prev value which will be curr
// since it will be alternating sequence, also maintain the maximum value of all the sequence 


//Link :- https://leetcode.com/problems/find-the-maximum-length-of-valid-subsequence-ii/

class Solution {
public:
    int maximumLength(vector<int>& nums, int k) {
        int n = nums.size(), max_len = 0;
        vector<vector<int>> dp(k, vector<int> (k, 0));

        for(int i=0; i<n; ++i){
            int curr = nums[i]%k;
            for(int prev=0; prev<k; ++prev){
                dp[curr][prev] = 1+dp[prev][curr];
                max_len = max(max_len, dp[curr][prev]);
            }
        }
        return max_len;
    }
};