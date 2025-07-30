#include<bits/stdc++.h>
using namespace std;

//Time complexity :- O(N)
//Space complexity :- O(N)

// Approach :-
// The maximum bit AND of any array will be the maximum number in that array 
// because if we take AND operation from any other number then the number tends to decrease 
// hence the answer will be the maximum number of times maximum_number of array is repeating itself 


// link :- https://leetcode.com/problems/longest-subarray-with-maximum-bitwise-and/

class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int maxi = *max_element(nums.begin(), nums.end());
        int n = nums.size(), res = 1, len=0;

        for(int ind=0; ind<n; ++ind){
            if(nums[ind] == maxi){
                len++;
                res = max(res, len);
            }
            else{
                len = 0;
            }
        }
        return res;
    }
};
