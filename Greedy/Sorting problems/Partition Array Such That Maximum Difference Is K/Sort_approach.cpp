#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(n*log(n))
// Space complexity :- O(1)

// Approach :- 
// sort the array to keep closest number as close as possible 
// mark start element of seq as min number and maintain a seq until 
// difference b/w current element and min_element is less than k 
// otherwise start a new sequence 


// Link :- https://leetcode.com/problems/partition-array-such-that-maximum-difference-is-k/ 

class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size(), mini = nums[0], seq = 1;

        for(int i=1; i<n; ++i){
            if((nums[i] - mini) > k){
                seq++;
                mini = nums[i];
            }
        }
        return seq;
    }
};