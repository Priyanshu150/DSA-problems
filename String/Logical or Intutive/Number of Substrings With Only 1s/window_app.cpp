#include<bits/stdc++.h>
using namespace std;

// Time complexity :- O(n)               
// Space complexity :- O(1)          

// Approach :-
// find a window to where only 1's exist, the number subarray will be n*(n+1)/2
// i.e. sum of n natural number 

// Links :- https://leetcode.com/problems/number-of-substrings-with-only-1s/

class Solution {
public:
    int numSub(string s) {
        int n = s.size(), res = 0, left = 0, mod = 1e9+7;

        // slinding window template 
        for(int right=0; right<n; ++right){
            // move left ptr to next after right ptr to avoid 0's in subarray
            if(s[right] == '0'){
                left = right+1;
            }
            // add number of 1's to our anwer 
            res = (res + (right - left + 1) % mod) % mod;
        }
        return res;
    }
};