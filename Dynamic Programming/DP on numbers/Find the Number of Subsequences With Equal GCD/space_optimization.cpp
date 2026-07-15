#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(n*200*200)
// Space complexity :- O(200*200)

// Approach :-
// 


// Link :- https://leetcode.com/problems/find-the-number-of-subsequences-with-equal-gcd/description/

class Solution {
public:
    int subsequencePairCount(vector<int>& nums) {
        int mod = 1e9+7;
        int n = nums.size();

        int maxEle = *max_element(nums.begin(), nums.end());
        vector<vector<int>> ahead(maxEle+1, vector<int> (maxEle+1, 0));

        for(int a=1; a<=maxEle; ++a){
            for(int b=1; b<=maxEle; ++b){
                ahead[a][b] = ((a == b) ? 1 : 0);
            }
        }

        for(int ind=n-1; ind>=0; --ind){
            vector<vector<int>> curr(maxEle+1, vector<int> (maxEle+1, 0));

            for(int a = maxEle; a>=0; --a){
                for(int b = maxEle; b>=0; --b){
                    int skip = ahead[a][b];
                    int opn1 = ahead[__gcd(a, nums[ind])][b];
                    int opn2 = ahead[a][__gcd(b, nums[ind])];

                    curr[a][b] = (0LL + skip + opn1 + opn2) % mod;
                }
            }
            ahead = move(curr);
        }
        return ahead[0][0];
    }
};
