#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(n)
// Space complexity :- O(1)

// Approach :-  
// sort the given array and start with the minimum element that we can form for 1st element 
// which will be nums[0]-k, loop from 2nd to last element in sorted array 
// for every element find the least unique number which we can make 
// if that number is in the range nums[i]-k to nums[i]+k
// then we'll get a distinct number otherwise we'll not 
// update the minimum number everytime after the distinct number is found with next+1 number 


// links :- https://leetcode.com/problems/maximum-number-of-distinct-elements-after-operations/

class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());

        int mini = nums[0]-k+1, n = nums.size(), res = 1;

        for(int i=1; i<n; ++i){
            int next = max(mini, nums[i]-k);
            if(nums[i]-k <= next && next <= nums[i]+k){
                res += 1;
                mini = next+1;
            }
        }
        return res;
    }
};