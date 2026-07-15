#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(n*200*200)
// Space complexity :- O(n*200*200)

// Approach :-
// we've to try all ways to build the subsequence 
// either we skip the element, add it to first sequence or add it to second sequence 
// maintain the gcd among all these sequence on the fly 
// at base case i.e when ind == n, we check if the both sequence are not empty and they have same value then we return 1 otherwise 0
// we can memoize this solution using (n*maxEle*maxEle) dimension array 


// Link :- https://leetcode.com/problems/find-the-number-of-subsequences-with-equal-gcd/description/

class Solution {
private:
    int mod = 1e9+7;

    int solve(int ind, int a, int b, vector<int> &nums, int &n, vector<vector<vector<int>>> &dp){
        if(ind == n){
            bool notEmpty = (a > 0 && b > 0);
            bool equalGcd = (a == b);

            return (notEmpty && equalGcd) ? 1 : 0;
        }
        if(dp[ind][a][b] != -1)
            return dp[ind][a][b];

        int skip = solve(ind+1, a, b, nums, n, dp);
        int opn1 = solve(ind+1, __gcd(a, nums[ind]), b, nums, n, dp);
        int opn2 = solve(ind+1, a, __gcd(b, nums[ind]), nums, n, dp);

        return dp[ind][a][b] = (0LL + skip + opn1 + opn2) % mod;
    }

public:
    int subsequencePairCount(vector<int>& nums) {
        int n = nums.size();
        int maxEle = *max_element(nums.begin(), nums.end());
        vector<vector<vector<int>>> dp(n, vector<vector<int>> (maxEle+1, vector<int> (maxEle+1, -1)));
        return solve(0, 0, 0, nums, n, dp);
    }
};