#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(n)
// Space complexity :- O(1)

// Approach :-  
// using sliding window technique count the number of maximum ones and 1 zeros in largest window 
// if all are element in the array are 1s then we've to delete 1 one 

// Link :- https://leetcode.com/problems/longest-subarray-of-1s-after-deleting-one-element/

class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size(), left = 0;
        int ones = 0, zeros = 0, res = 0;

        for(int right=0; right<n; ++right){
            if(nums[right] == 1)     
                ones++;
            else 
                zeros++;
            
            while(zeros>1){
                if(nums[left] == 1)     
                    ones--;
                else 
                    zeros--;
                
                ++left;
            }
            res = max(res, ones);
        }
        return (res == n) ? res-1 : res;
    }
};
