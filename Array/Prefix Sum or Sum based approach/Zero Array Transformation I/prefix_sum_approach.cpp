#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(n)  
// Space complexity :- O(n)

// Approach :- 
// Instead of iterating on the range and decrement the count one by one we can mainatin an array
// We'll decrement by 1 at query[0] index and increment by 1 at query[1]+1 index of temp array
// this denotes that we've to decrement all the values from query[0] to query[1]
// After updating all the range value, traverse in temp array and maintain a sum
// if the sum + nums[i] > 0 then it's not possible to decrement that value to 0
// at last return true denoting array can be transform to 0

// Link :- https://leetcode.com/problems/zero-array-transformation-i/


class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size(), sum = 0;
        vector<int> arr(n+1, 0);

        for(auto query: queries){
            arr[query[0]] -= 1;
            arr[query[1]+1] += 1;
        }

        for(int i=0; i<n; ++i){
            sum += arr[i];
            if(nums[i] + sum > 0)
                return false;
        }
        return true;
    }
};