#include<bits/stdc++.h>
using namespace std;

// Time complexity :- O(n*log(n) + n*n + n)                 
// Space complexity :- O(n+n)              

// Approach :- 
// Using lis tabulation approach we can change a condition to solve this problem
// instead of nums[i] > nums[j], use nums[i] % nums[j] == 0 as the condintion 
// For creating the array we can track which previous index (j) update current index (i) 
// keeping tracking of in array we can recreate the answer
// store the index where maximum dp length is observed 


// Links :- https://leetcode.com/problems/largest-divisible-subset/

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int maxLen = 0, n = nums.size(), ind = 0;
        vector<int> dp(n, 1), hash(n, -1), ans;
       
        for(int i=1; i<n; i++){
            for(int j=0; j<i; j++){
                if(nums[i] % nums[j] == 0){
                    if(dp[j]+1 > dp[i]){
                        dp[i] = dp[j]+1;
                        hash[i] = j;
                    }
                }
                if(dp[i] > maxLen){
                    maxLen = dp[i];
                    ind = i;
                }
            }
        }
        while(hash[ind] != -1){
            ans.push_back(nums[ind]);
            ind = hash[ind];
        }
        ans.push_back(nums[ind]);
        return ans;
    }
};