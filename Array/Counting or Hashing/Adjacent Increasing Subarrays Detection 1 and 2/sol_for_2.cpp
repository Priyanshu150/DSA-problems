#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(N)
// Space complexity :- O(1)

// Approach :-  
// count the length of 2 consecutive increasing sub-array length 
// there can two case to find k 
// first the currlen subarray is of size 2*k 
// second the min of past two increasing sub-array will be k 


// Link :- https://leetcode.com/problems/adjacent-increasing-subarrays-detection-ii/

class Solution {
public:
    int maxIncreasingSubarrays(vector<int>& nums) {
        int n = nums.size(), maxLen = 1;
        int currLen = 1, prevLen = 0;

        for(int i=1; i<n; ++i){
            if(nums[i] > nums[i-1])
                currLen++;
            else{
                prevLen = currLen;
                currLen = 1;
            }
            // currLen is 2*k
            if(currLen > 1)
                maxLen = max(maxLen, currLen/2);
            
            // consecutive 2-continous increasing subarray length 
            maxLen = max(maxLen, min(currLen, prevLen));
        }
        return maxLen;
    }
};