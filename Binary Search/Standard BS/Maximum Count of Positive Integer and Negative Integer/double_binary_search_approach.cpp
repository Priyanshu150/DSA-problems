#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(log(n))  
// Space complexity :- O(1)

// Approach :-
// we can find the last index & first index of negative & positive number respectively using binary search
// so the number of element of negative will be index
// and the number of element of positive will be n-index
// return maximum out of both

// Link :- https://leetcode.com/problems/maximum-count-of-positive-integer-and-negative-integer/

class Solution {
private:
    int binarySearch(vector<int> &nums, int low, int high, int target){
        if(low <= high){
            int mid = low + (high - low)/2;
            if(nums[mid] <= target)
                return binarySearch(nums, mid+1, high, target);
            else
                return binarySearch(nums, low, mid-1, target);
        }
        return low;
    }

public:
    int maximumCount(vector<int>& nums) {
        int n = nums.size();
        int negCnt = binarySearch(nums, 0, n-1, -1);
        int posCnt = n - binarySearch(nums, negCnt, n-1, 0);
        return max(negCnt, posCnt);
    }
};

