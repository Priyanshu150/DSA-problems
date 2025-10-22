#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(N)
// Space complexity :- O(1)

// Approach :-  
// count the length of 2 consecutive increasing sub-array length 
// if the length is greater than 2k or min of both length is greater than k 
// then it's possible otherwise it's not 


// Link :- https://leetcode.com/problems/adjacent-increasing-subarrays-detection-ii/

class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        int currLen = 1, prevLen = 0;

        for(int i=1; i<n; ++i){
            if(nums[i-1] < nums[i]){
                currLen++;
            }
            else{
                prevLen = currLen;
                currLen = 1;
            }

            // if the curLen size is greater than 2*k
            if(currLen >= 2*k)
                return true;
            
            // if both consecutive subarray having size greater than k 
            if(min(prevLen, currLen) >= k)
                return true;
        }
        return false;
    }
};
