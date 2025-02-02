#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(n)
// Space complexity :- O(1)

// Approach :-  
// If array is rotated then there should exist only one point(dip) where nums[i+1] < nums[i] 
// If no such point exist then array is sorted but not rotated
// If only one exist then,
// the lowest on the left side which will be nums[0]
// has to greater than larget on the right side which will be num[n-1]


//Link :- https://leetcode.com/problems/check-if-array-is-sorted-and-rotated/description/

class Solution {
public:
    bool check(vector<int>& nums) {
        int n = nums.size(), dip = 0;

        for(int i=1; i<n; ++i){
            if(nums[i] < nums[i-1])
                dip++;
        }
        if(dip > 1)     return false;
        else if (dip == 1 && nums[n-1] > nums[0])
            return false;
        
        return true;
    }
};