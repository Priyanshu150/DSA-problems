#include<bits/stdc++.h>
using namespace std;

//Time complexity :- O(n)
//Space complexity :- O(n)

// Approach :-
// Convert the array into interesting array based on the logic that (number % modulo == k)
// use the logic of find a target sum in a given array
// based on the interesting array calculate the sum of the array 
// find if the target exist in the array i.e. (sum - k + modulo) % modulo
// add the occurence of the target in our result 
// adding modulo will make sure when we're getting negative value it's comming under cycle 0 to modulo-1
// maintain the sum % modulo count in the map to keep track of all the occurence


//link :- https://leetcode.com/problems/count-complete-subarrays-in-an-array/

class Solution {
    #define ll long long

public:
    long long countInterestingSubarrays(vector<int>& nums, int modulo, int k) {
        ll res = 0, sum = 0;
        unordered_map<ll,ll> mp;
        mp[0] = 1;

        for(ll num: nums){
            sum += (num % modulo == k) ? 1 : 0;
            sum %= modulo;
            res += mp[(sum - k + modulo) % modulo];
            mp[sum] += 1;
        }
        return res;
    }
};