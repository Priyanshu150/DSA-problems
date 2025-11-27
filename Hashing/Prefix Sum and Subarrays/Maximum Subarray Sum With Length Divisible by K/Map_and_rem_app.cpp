#include<bits/stdc++.h>
using namespace std;

// Time complextiy :- O(n*log(n))
// Space complexity :- O(n)

// Approach :-   
// we can prefix sum technique to find the subarray sum whose length is divisible by k
// we'll find the subarray sum and store them into the map
// and use prefix sum technique find the value of subarray 
// while checking for the previous sub-array for current-subarray we can use remainder 
// in order words store the subarray sum based on remainder 
// we'll store the min sum of all the sub-array accross the remainder as 
// storing min will be let us to find the maximum value later 


//Link :- https://leetcode.com/problems/maximum-subarray-sum-with-length-divisible-by-k/

class Solution {
    #define ll long long 

public:
    long long maxSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        ll res = LONG_MIN, sum = 0;
        unordered_map<int, ll> mp;     // len % k = rem => preSum
        mp[0] = 0;          

        for(int i=0; i<n; ++i){
            // sum of subarray till index i
            sum += nums[i];
            // find the remainder on the length
            int rem = (i+1) % k;
            if(mp.count(rem)){
                // update the maximum sum b/w current subarray sum and previous one 
                res = max<ll>(res, sum - mp[rem]);
                // keep min subarray sum stored in map which will give maximum sum 
                mp[rem] = min<ll>(sum, mp[rem]);
            }
            else{
                // if first time getting the subarray then update the current sum
                mp[rem] = sum;
            }
        }
        return res;
    }
};