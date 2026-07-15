#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(n*200*200)
// Space complexity :- O(n*200*200)

// Approach :-
// 


// Link :- https://leetcode.com/problems/find-the-number-of-subsequences-with-equal-gcd/description/

class Solution {
public:
    int subsequencePairCount(vector<int>& nums) {
        int mod = 1e9+7;
        int n = nums.size();

        int maxEle = *max_element(nums.begin(), nums.end());
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>> (maxEle+1, vector<int> (maxEle+1, 0)));

        for(int a=1; a<=maxEle; ++a){
            for(int b=1; b<=maxEle; ++b){
                dp[n][a][b] = ((a == b) ? 1 : 0);
            }
        }

        for(int ind=n-1; ind>=0; --ind){
            for(int a = maxEle; a>=0; --a){
                for(int b = maxEle; b>=0; --b){
                    int skip = dp[ind+1][a][b];
                    int opn1 = dp[ind+1][__gcd(a, nums[ind])][b];
                    int opn2 = dp[ind+1][a][__gcd(b, nums[ind])];

                    dp[ind][a][b] = (0LL + skip + opn1 + opn2) % mod;
                }
            }
        }
        return dp[0][0][0];
    }
};