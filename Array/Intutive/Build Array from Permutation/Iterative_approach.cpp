#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(n)  
// Space complexity :- O(1)

// Approach :-


// Link :- https://leetcode.com/problems/build-array-from-permutation/

class Solution {
public:
    vector<int> buildArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;

        for(int i=0; i<n; ++i)
            ans.push_back(nums[nums[i]]);
        
        return ans;
    }
};      