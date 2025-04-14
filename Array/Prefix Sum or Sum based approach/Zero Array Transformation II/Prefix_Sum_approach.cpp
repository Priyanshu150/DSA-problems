#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(n + q)  
// Space complexity :- O(n)

// Approach :- 
// Difference array concept can be used to calculate the prefix sum in O(1)
// we'll maintain an array(diff) of size n+1 initially 0 
// and for every query we can update start_ind in diff by +val and end_ind+1 by -val
// traversing through the element of each number we can calculate the sum 
// Idea is make diff array either equal to or greater than the value of original array
// We'll update the diff array and at the same time maintain a sum traversing on elemnent of array 
// so that we can check wheather we can sum of that index match with differnce array

// Link :- https://leetcode.com/problems/zero-array-transformation-ii/

class Solution {
public:
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size(), sum = 0, pos = 0, sz = queries.size();
        vector<int> diff(n+1, 0);

        for(int i=0; i<n; ++i){
            while(sum + diff[i] < nums[i]){
                if(pos == sz)
                    return -1;
                
                int start = queries[pos][0], end = queries[pos][1], val = queries[pos][2];
                pos++;
                
                if(end < i)     continue;

                diff[max(start, i)] += val;
                diff[end+1] -= val;
            }
            sum += diff[i];
        }
        return pos;
    }
};