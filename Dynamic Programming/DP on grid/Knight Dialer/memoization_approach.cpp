#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(10*n*stack_size)  
// Space complexity :- O(10*n)

// Approach :-
// For every number we'll store the possible numbers it can go to in a data structure
// changing parameter will we'be key and the sequence number we formed till now 
// trying all the possiblities will be the number of ways of all keys we can go to
// and finally we can add all the ways and the base case will be when the count reaches n return 1
// As there are 2 changing parameters we can take a 2-d array to memoize for dp

// Link :- https://leetcode.com/problems/knight-dialer/

class Solution {
private:
    int mod = 1e9 + 7;
    vector<vector<int>> dirs = {{4,6}, {6,8}, {7,9}, {4,8}, {0,3,9}, {}, {0,1,7}, {2,6}, {1,3}, {2,4}};

    int ways(int key, int cnt, int &n, vector<vector<int>> &dp){
        if(cnt == n)
            return 1;
        if(dp[key][cnt] != -1)
            return dp[key][cnt];
        
        int total = 0;
        for(auto nextKey: dirs[key]){
            total = (total + ways(nextKey, cnt+1, n, dp))%mod;
        }
        return dp[key][cnt] = total % mod;
    }

public:
    int knightDialer(int n) {
        int res = 0;
        vector<vector<int>> dp(10, vector<int> (n, -1));

        for(int key=0; key<10; ++key){
            res = (res + ways(key, 1, n, dp))%mod;
        }
        return res;
    }
};