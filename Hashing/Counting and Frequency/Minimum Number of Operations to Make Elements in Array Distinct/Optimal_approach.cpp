#include<bits/stdc++.h>
using namespace std;

// Time complexity :- O(n)          
// Space complexity :- O(n)              

// Approach :- 
// Traverse from right to left and keep storing the elements in the set 
// If we find the element to be present in the element that means we've to apply operation till that index
// Apply maths formula to get the result, if duplicate element not found then at last return 0  


// Links :- https://leetcode.com/problems/minimum-number-of-operations-to-make-elements-in-array-distinct/


class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> st;

        for(int i=n-1; i>=0; --i){
            if(st.count(nums[i]))
                return ((i+1)/3) + ((i+1)%3!=0);
            
            st.insert(nums[i]);
        }
        return 0;
    }
};