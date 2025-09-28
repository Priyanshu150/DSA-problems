#include<bits/stdc++.h>
using namespace std;

//Time complexity :- O(N)
//Space complexity :- O(N)

// Approach :-
// Use sliding window approach, maximum window size at any point will be our answer 
// Valid window will be different b/w largest element and smallest element is less than target given
// we'll use deque to maintain seprate ds for min and max element 

//link :- 
// gfg :- https://leetcode.com/problems/strange-printer/
// leetcode :- https://leetcode.com/problems/longest-continuous-subarray-with-absolute-diff-less-than-or-equal-to-limit/

class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int i=0, j=0, n = nums.size(), maxLen = 0;
        deque<int> maxi, mini;

        while(j < n){
            while(!maxi.empty() && nums[maxi.back()] < nums[j])     maxi.pop_back();
            maxi.push_back(j);

            while(!mini.empty() && nums[mini.back()] > nums[j])     mini.pop_back();
            mini.push_back(j);

            int diff = nums[maxi.front()] - nums[mini.front()];

            while(i<=j && diff > limit){
                i = min(maxi.front(), mini.front()) + 1;
                while(!maxi.empty() && maxi.front() < i)    maxi.pop_front();
                while(!mini.empty() && mini.front() < i)    mini.pop_front();
                diff = nums[maxi.front()] - nums[mini.front()];
            }
            maxLen = max(maxLen, j-i+1);
            j++;
        }
        return maxLen;
    }
};