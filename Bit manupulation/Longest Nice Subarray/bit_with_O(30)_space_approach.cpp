#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(n)  
// Space complexity :- O(1)

// Approach :-  
// nums[i] can go till 1e9 which can be accomodated in 30 bits
// for finding every pair in subarray to have '&' value as 0, every bit in 30 bit should only be occupied once
// becuase if any two number have same bit it will give us some value instead of giving us 0
// this is based on the property of '&' operator i.e. 1&1 = 1 otherwise 0
// we'll use sliding window approach to check the valid subarray and calulate the max length accordingly
// we can add the contribution bit depending on which bit is present in the num
// we check that if the any place has more than 1 value then the current subarray will not be valid
// we'll start removing from left side until it becomes valid
// the length of subbarray will be right_ind - left_ind + 1
// we can create separation function to add and remove contribution of bits 
// and to check if the current subbarray is valid or not


// Link :- https://www.geeksforgeeks.org/problems/subset-sum-problem2014/1

class Solution {
private:
    void contribution(int num, vector<int> &freq, int val){
        for(int i=0; i<32; ++i){
            if(num & (1<<i))
                freq[i] += val;
        }
    }

    bool isValid(vector<int> &freq){
        for(int i=0; i<32; ++i){
            if(freq[i] > 1)
                return false;
        }
        return true;
    }

public:
    int longestNiceSubarray(vector<int>& nums) {
        int i=0, j=0, res=0, n = nums.size();
        vector<int> freq(32, 0);

        while(j<n){
            contribution(nums[j], freq, 1);

            while(!isValid(freq)){
                contribution(nums[i], freq, -1);
                i++;
            }
            res = max(res, j-i+1);
            j++;
        }
        return res;
    }
};