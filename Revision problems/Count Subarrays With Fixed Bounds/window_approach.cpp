#include<bits/stdc++.h>
using namespace std;

//Time complexity :- O(n)
//Space complexity :- O(1)

// Approach :-
// Found those index that are breaking point for qestions
// i.e. number that is either greater than maxK or less than minK
// because such number will not be part of valid subarray 
// the answer will exist b/w such number and we'll have a valid subbary b/w breaking point 
// In the valid window the number will be in the range either greater than equal to minK or less than equal to maxK
// capture the indexes of minK and maxK, while traversing in the array
// for counting the subarray use the formula min(minI, maxI) - lb
// where minI reperesent the index of minK element 
// maxI represents the index of maxK element 
// lb is the bound where breaking point was found intially it will be -1, and once we find one we'll updae the index
// the ans will not exists when minI is -1 or maxI is -1 and (min(minI, maxI) - lb) is negative


//link :- https://leetcode.com/problems/count-subarrays-with-fixed-bounds/

class Solution {
    #define ll long long 

public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        int n = nums.size(), minI = -1, maxI = -1, lb = -1;
        ll res = 0;

        for(int i=0; i<n; ++i){
            if(nums[i] == minK)
                minI = i;
            if(nums[i] == maxK)
                maxI = i;
            if(nums[i] > maxK || nums[i] < minK)
                lb = i;
            
            if(minI == -1 || maxI == -1 || (min(minI, maxI) - lb) < 0)
                continue;
            
            res += min(minI, maxI) - lb;
        }
        return res;
    }
};