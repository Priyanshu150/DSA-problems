#include<bits/stdc++.h>
using namespace std;

//Time complexity :- O(n)
//Space complexity :- O(1)

// Approach :-
// start from index  1 we'll traverse on array till index n-1
// for current index, if it's not divisible by 2 then we can skip it because it'll give us decimal value
// we find the sum of 1st and 3rd element of subarray which will be at index i-1 & i+1
// if the sum is equal to currrent_number/2, count the subarray in our answer and increment the index by 1


//link :- https://leetcode.com/problems/count-subarrays-of-length-three-with-a-condition/

class Solution {
public:
    int countSubarrays(vector<int>& nums) {
        int n = nums.size(), res = 0;

        for(int i=1; i<n-1; ++i){
            if(nums[i] % 2)      continue;

            int sum = nums[i-1] + nums[i+1];
            if(sum == (nums[i]/2))
                res += 1;
        }
        return res;
    }
};