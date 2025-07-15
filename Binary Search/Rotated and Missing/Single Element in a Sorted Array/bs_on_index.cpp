#include<bits/stdc++.h>
using namespace std;

//Time complexity :- O(log(n))   
//Space complexity :- O(1)

// Approach :-
// we'll do binary search on index and find the single number 
// if we observe a pattern then we'll find that before single number 
// all the number appearing in pair are having in (even, odd) indexes
// and after single number, all the number appearing in pair are having in (odd, even) indexes
// so we'll eliminate the search space using the following observation 


//Link :- https://leetcode.com/problems/single-element-in-a-sorted-array/

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        if(n == 1)                  return nums[0];
        if(nums[0] != nums[1])      return nums[0];
        if(nums[n-1] != nums[n-2])  return nums[n-1];

        int low = 1, high = n-2;
        while(low <= high){
            int mid = low + (high - low)/2;
            if(nums[mid] == nums[mid+1]){
                if(mid % 2 == 0)    
                    low = mid+1;
                else 
                    high = mid-1;
            }
            else if(nums[mid] == nums[mid-1]){
                if(mid % 2 == 0)
                    high = mid-1;
                else 
                    low = mid+1;
            }
            else    return nums[mid];
        }
        return 5;
    }
};