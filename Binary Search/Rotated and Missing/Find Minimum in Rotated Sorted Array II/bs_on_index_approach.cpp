#include<bits/stdc++.h>
using namespace std;

//Time complexity :- O(log(n))   
//Space complexity :- O(1)

// Approach :-
// the approach remains same from 'Find the minimum element in roatated sorted array'
// only test case that fails which are on the pattern '10 5 10 10 10'
// due to the present of duplicate, hecne we can check that whenever low == mid == high
// we can increament the low and decrement the high by 1


//Link :- https://leetcode.com/problems/find-minimum-in-rotated-sorted-array-ii/

class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size(), low = 0, high = n-1, res = INT_MAX;

        while(low <= high){
            int mid = low + (high - low)/2;
            
            if(nums[mid] == nums[low] && nums[mid] == nums[high]){
                res = min(res, nums[low]);
                low += 1;
                high -= 1;
            }
            else if(nums[low] <= nums[mid] && nums[mid] <= nums[high]){
                res = min(res, nums[low]);
                break;
            }
            else if(nums[low] <= nums[mid]){
                res = min(res, nums[low]);
                low = mid+1;
            }
            else{
                res = min(res, nums[mid]);
                high = mid-1;
            }
        }
        return res;
    }
};

class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size(), low = 0, high = n-1, res = INT_MAX;

        while(low <= high){
            int mid = low + (high - low)/2;
            
            if(nums[mid] == nums[low] && nums[mid] == nums[high]){
                res = min(res, nums[low]);
                low += 1;
                high -= 1;
            }
            else if(nums[low] <= nums[mid]){
                res = min(res, nums[low]);
                low = mid+1;
            }
            else{
                res = min(res, nums[mid]);
                high = mid-1;
            }
        }
        return res;
    }
};