#include<bits/stdc++.h>
using namespace std;

// Time complexity :- O(n*n)                 
// Space complexity :- O(n)                  

// Approach :-
// The idea is to maximize value of nums[i] & nums[k] and minimize value of nums[j]
// for every index we'll calculate who is the highest on the left 
// Traversing on array, i from 0 to n-2 and j from i+1 to n-1 we'll check for every index 
// what is the maximum value i.e. (nums[i] - nums[j]) * maxOnLeft[k]
// if neg value comes ignore that and move to the next iteration else maintain the max value 


// Links :- https://leetcode.com/problems/maximum-value-of-an-ordered-triplet-i/

class Solution {
#define ll long long 

public:
    long long maximumTripletValue(vector<int>& nums) {
        ll n = nums.size(), maxi = 0, res = 0;
        vector<ll> maxOnLeft(n, 0);

        for(ll i=n-1; i>=0; --i){
            maxi = max<ll>(maxi, nums[i]);
            maxOnLeft[i] = maxi;
        }

        for(ll i=0; i<n-2; ++i){
            for(ll j=i+1; j<n-1; ++j){
                ll val = ((ll)(nums[i] - nums[j])) * maxOnLeft[j+1];
                if(val > 0)
                    res = max<ll>(res, val);
            }
        }
        return res;
    }
};