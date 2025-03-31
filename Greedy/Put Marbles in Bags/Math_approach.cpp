#include<bits/stdc++.h>
using namespace std;

// Time complexity :- O(n*log(n))            // Where n is length of array
// Space complexity :- O(n)                  // n is space for extra array

// Approach :-
// we've to make k-1 cuts in array (a, b, c, d, e, f, g, h, i, j)
// suppose we put the cut at k random places then  the value we get is a + b + c + e + g + h + i + j
// this value we've to maximize, this can be done by getting all the adjacent value and 
// first and last element remains same but adjacent value decide which will gives us maximum or minimum
// https://www.youtube.com/watch?v=hjyFkhXKowc(for explanation)


// Links :- https://leetcode.com/problems/partition-labels/

class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        int n = weights.size();
        if(k == 1 || k == n)        return 0;

        vector<int> candidates;

        for(int i=0; i<n-1; ++i)
            candidates.push_back(weights[i] + weights[i+1]);
        
        sort(candidates.begin(), candidates.end());
        long long maxSum = 0, minSum = 0;

        for(int i=0; i<k-1; ++i){
            minSum += candidates[i];
            maxSum += candidates[n-2-i];
        }
        return maxSum - minSum;
    }
};