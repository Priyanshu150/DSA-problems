#include<bits/stdc++.h>
using namespace std;

//Time complexity :- O(n)
//Space complexity :- O(1)

// Approach :-
// the modulo of 2 will give us only 0 and 1 
// So for satisfying the condition, we'll have to find alternating sequence of 0 and 1
// or either the longest sequence of 0 and 1
// we'll traverse on the array and maintain all the three sequence and check which gives us the max seq

//Link :- https://leetcode.com/problems/find-the-maximum-length-of-valid-subsequence-i/

class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int n = nums.size();
        if(n < 3)   return n;

        int alternating = 1, ones = 0, zeros = 0, prevRem = nums[0]%2;
        if(prevRem == 1)    ones++;
        else                zeros++;

        for(int i=1; i<n; ++i){
            int rem = nums[i]%2;
            if(prevRem != rem){
                prevRem = rem;
                alternating++;
            }
            if(rem == 1)    ones++;
            else            zeros++;
        }
        return max({ones, zeros, alternating});
    }
};