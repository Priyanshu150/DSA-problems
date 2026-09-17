#include <bits/stdc++.h>
using namespace std;

//Time complextiy :- O(2*n)
// Space complexity :- O(n)

// Approach :- 
// 1. We will use two pointers to find the subarrays with the target sum.
// 2. We will maintain a variable to keep track of the best minimum length of the subarray found so far.
// 3. We will also maintain a vector to keep track of the minimum length of the subarray found till the current index.
// 4. If we find a subarray with the target sum, we will check if there is a valid subarray before it and update the result accordingly.
// 5. Finally, we will return the result if found, otherwise return -1.

//Link :- https://leetcode.com/problems/find-two-non-overlapping-sub-arrays-each-with-target-sum/description/

class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n = arr.size(), sum = 0, left = 0;
        int result = INT_MAX, bestMin = INT_MAX;
        vector<int> minTillIndex(n, INT_MAX);

        for(int right=0; right<n; ++right){
            sum += arr[right];

            while(sum > target){
                sum -= arr[left];
                ++left;
            }

            if(sum == target){
                int len = (right - left + 1);
                if(left-1 > 0 && minTillIndex[left-1] != INT_MAX){
                    result = min(result, minTillIndex[left-1] + len);
                }
                bestMin = min(len, bestMin);
            }
            
            minTillIndex[right] = bestMin;
        }
        return (result == INT_MAX) ? -1 : result;
    }
};