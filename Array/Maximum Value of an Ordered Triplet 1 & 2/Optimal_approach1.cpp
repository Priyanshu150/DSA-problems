#include<bits/stdc++.h>
using namespace std;

// Time complexity :- O(n)                 
// Space complexity :- O(n)                  

// Approach :-
// for find the max value of (x-y)*z, we've to maximize the value of x & z 
// we can maintain an array where for every index we keep the maximum value on the left
// we traverse from left to right, considering the element as y and maintaining maximum element 
// store the result as maximum value of (max_ele - curr[i])*maxOnLeft[i]


// Links :- https://leetcode.com/problems/maximum-value-of-an-ordered-triplet-ii/


class Solution {
#define ll long long

public:
    long long maximumTripletValue(vector<int>& nums) {
        ll n = nums.size(), maxi = 0, res = 0;
        vector<ll> maxOnLeft(n, 0);

        for(int i=n-1; i>=0; --i){
            maxi = max<ll>(maxi, nums[i]);
            maxOnLeft[i] = maxi;
        }
        maxi = nums[0];

        for(int i=1; i<n-1; ++i){
            ll val = (maxi-(ll)nums[i])*maxOnLeft[i+1];
            res = max<ll>(res, val);
            maxi = max<ll>(maxi, nums[i]);
        }  
        return res;
    }
};