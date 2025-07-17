#include<bits/stdc++.h>
using namespace std;

//Time complexity :- O(log(n))
//Space complexity :- O(1)

// Approach :-
// while using standard binary search we eliminate one half, but in this problem we can't do that 
// Instead we can make use of both the part 
// Start with standard binary search using mid find which part is sorted 
// take the min of sorted part and eliminate that from serch space and try searching in the un-sorted part
// for further optimization we can check when whole array is sorted then the min will be smallest element

//Link :- https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/

class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        if(n == 1)      return nums[0];

        int low = 0, high = n-1, res = INT_MAX;
        //standard binary search
        while(low <= high){
            int mid = low + (high - low)/2;
            // If the complete array is sorted 
            if(nums[low] <= nums[high]){
                res = min(res, nums[low]);
                break;
            }
            // If left half is sorted compare with nums[low] which is sorted and eliminate the left half
            if(nums[low] <= nums[mid]){
                res = min(res, nums[low]);
                low = mid+1;
            }
            // If the right half is sorted compare with nums[mid] which is sorted and eliminate the right half
            else{
                res = min(res, nums[mid]);
                high = mid-1;
            }
        }
        return res;
    }
};
