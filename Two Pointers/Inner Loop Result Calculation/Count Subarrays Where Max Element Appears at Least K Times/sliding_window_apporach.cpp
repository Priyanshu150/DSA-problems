#include<bits/stdc++.h>
using namespace std;

//Time complexity :- O(n)
//Space complexity :- O(1)

// Approach :-
// using sliding window approach we'll find a valid window
// cnt variable will maintain the count of maximum number in the window
// moving right ptr, if the current number is maximum element increment cnt by 1
// whenever we find that the cnt increase or equal to k, then we find our valid window
// all the element present on the right side of right ptr will also be valid, count all
// start removing element from left side if the element at left ptr equal to max element then decrement the count


//link :- https://leetcode.com/problems/count-complete-subarrays-in-an-array/

class Solution {
    using ll = long long;

public:
    long long countSubarrays(vector<int>& nums, int k) {
        ll res = 0;
        int left = 0, n = nums.size(), cnt = 0;
        int maxi = *max_element(nums.begin(), nums.end());

        for(int right=0; right<n; ++right){
            if(nums[right] == maxi)
                cnt++;
            
            while(cnt >= k){
                res += (n - right);
                if(nums[left] == maxi)
                    cnt--;
                
                ++left;
            } 
        }
        return res;
    }
};