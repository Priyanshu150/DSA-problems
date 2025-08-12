#include<bits/stdc++.h>
using namespace std;

//Time complexity :- O(n*n*n)
//Space complexity :- O(n*1001) 

// Approach :-
// Capitailising on LIS we can use the same concept here 
// where dp[ind][diff] will represent the value of largest artimetic seq till ind with difference as diff
// we'll choose 2 numbers and find the difference among them 
// normally the lis will be of 2 length, if the dp[prev_num][diff] > 0, then some seq already exist 
// then the maximum till curr ind will be dp[ind][diff] = 1+dp[prev_num][diff], 1 for current number
// maintain a variable to store max answer
// take diff + 500 to avoid the overflow, Since the number can be negative according to constraints


//link :- https://leetcode.com/problems/longest-arithmetic-subsequence/

class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        int n = nums.size();
        if(n <= 2)      return n;

        int ans = 0;
        vector<vector<int>> dp(n, vector<int> (1001, 0));

        for(int i=1; i<n; ++i){
            for(int j=0; j<i; ++j){
                int diff = nums[i] - nums[j] + 500;
                int cnt = 2;
                if(dp[j][diff] > 0)
                    cnt = max(1+dp[j][diff], cnt);
                
                dp[i][diff] = cnt;
                ans = max(ans, cnt);
            }
        }
        return ans;
    }
};