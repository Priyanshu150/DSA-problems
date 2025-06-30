#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(n*log(n))  
// Space complexity :- O(1)

// Approach :-  
// sort the array because it'll keep the number as closest as possible
// mainatin a window where the difference b/w the first and last element is 1
// move the sliding window and find the maximum length 


class Solution {
public:
    int findLHS(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size(), res = 0, left = 0;

        for(int right=0; right<n; ++right){
            while(nums[right] - nums[left] > 1){
                ++left;
            }
            if(nums[right] - nums[left] == 1)
                res = max(res, right - left + 1);
        }
        return res;
    }
};