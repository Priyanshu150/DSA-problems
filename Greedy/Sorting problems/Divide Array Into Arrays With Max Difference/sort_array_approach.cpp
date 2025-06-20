#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(n*log(n))
// Space complexity :- O(1)

// Approach :- 
// sort the array to make closest number as close as possible
// Take every 3 sized subarray and check if it's satisfy the condition
// if it does build the answer with those subarrays 
// otherwise return an empty array as answer

// Link :- https://leetcode.com/problems/divide-array-into-arrays-with-max-difference/

class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        vector<vector<int>> res;
        int n = nums.size();
        sort(begin(nums), end(nums));
        vector<int> temp;
        
        for(int i=0; i<n; i++){
            if(temp.size()==3 || (!temp.empty() && nums[i]-temp[0]>k)){
                if(temp.size() < 3)     return {};
                res.push_back(temp);
                temp.clear();
            }
            temp.push_back(nums[i]);
        }
        res.push_back(temp);
        return res;
    }
};