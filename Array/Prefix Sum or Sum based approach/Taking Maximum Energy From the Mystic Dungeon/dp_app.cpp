#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(n)
//Space complexity :- O(n)

// Approach :-  
// Make a dp array which is initally equal to the given energy array 
// traverse from right to left, check if curr_ind + k < n
// then add the contribution of dp[curr_ind + k] into curr_ind
// answer will be maximum among all the values 


// Link :- https://leetcode.com/problems/taking-maximum-energy-from-the-mystic-dungeon/

class Solution {
public:
    int maximumEnergy(vector<int>& energy, int k) {
        vector<int> dp = energy;
        int res = INT_MIN, n = energy.size();

        for(int i=n-1; i>=0; --i){
            if(i+k < n){
                dp[i] += dp[i+k];
            }
            res = max(dp[i], res);
        }
        return res;
    }
};