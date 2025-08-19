#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(n)
// Space complexity :- O(1)

// Approach :-  
// find the valid window in which only zeros are present
// for every new window added the number of contribution will be (right - left + 1)
// use two varialbe to track then count of contribution of zeros and other numbers 


//Link :- https://leetcode.com/problems/number-of-zero-filled-subarrays/

class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long res = 0;
        int left = 0, n = nums.size(), zeroCnt = 0, restCnt = 0;

        for(int right=0; right<n; ++right){
            if(nums[right] != 0)    restCnt++;
            else    zeroCnt++;

            while(restCnt > 0 && left <= right){
                if(nums[left] != 0)    restCnt--;
                else    zeroCnt--;

                left++;
            }
            if(zeroCnt > 0)
                res += (right - left + 1);
        }
        return res;
    }
};