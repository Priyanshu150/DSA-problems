#include<bits/stdc++.h>
using namespace std;

// Time complexity :- O(n)          
// Space complexity :- O(n)              

// Approach :- 
// we can use ordered set and keep all the element in the set 
// to get a sorted and non duplicate numbers 
// if k > smallest number then it's not possible because smallest can never be converted to k
// if k == smallest number then we'll need distinct numbers - 1 operations as we've to convert rest into smallest number
// if k < smallest_number then we'll need distinct number operations as we've to convert all to smallest number


// Links :- https://leetcode.com/problems/minimum-operations-to-make-array-values-equal-to-k/

class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int n = nums.size();
        set<int> st;

        for(int i=0; i<n; ++i)
            st.insert(nums[i]);
        
        int strt = *st.begin(), sz = st.size();
        if(k > strt)      return -1;
        if(k == strt)     return sz-1;
        return sz;
    }
};