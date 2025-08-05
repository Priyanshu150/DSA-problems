#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(10*n)  
// Space complexity :- O(10*n)

// Approach :-
// Convert the memoization solution to the tabulation
// outer loop will be of the count and inner will be the key
// because we'll be needing random key for calculating answer so it better to calculate the key first
// rest possiblities remains same and answer can we found as dp[key][1] 
// and we've to take the maximum one in first column as answer 

// Link :- https://leetcode.com/problems/knight-dialer/

class Solution {
public:
    int knightDialer(int n) {
        int res = 0, mod = 1e9 + 7;
        vector<vector<int>> dp(10, vector<int> (n+1, 0));
        vector<vector<int>> dirs = {{4,6}, {6,8}, {7,9}, {4,8}, {0,3,9}, {}, {0,1,7}, {2,6}, {1,3}, {2,4}};

        for(int key=0; key<10; ++key)
            dp[key][n] = 1;

        for(int cnt=n-1; cnt>0; --cnt){
            for(int key=0; key<10; ++key){
                for(auto nextKey: dirs[key]){
                    dp[key][cnt] = (dp[key][cnt] + dp[nextKey][cnt+1])%mod;
                }
            }
        }

        for(int key=0; key<10; ++key){
            res = (res + dp[key][1])%mod;
        }
        return res;
    }
};
