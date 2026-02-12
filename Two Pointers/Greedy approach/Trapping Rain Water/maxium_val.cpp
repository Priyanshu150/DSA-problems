#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(n)  
// Space complexity :- O(n)

// Approach :-   
// for finding the water retained by current bar, the general formula will be 
// min of left max height and right max height - current height 
// maintain left and right max in array by maintaining maximum value for each index
// using both array find the contribution of each bar and calculate the total water retained 

// Link :- https://leetcode.com/problems/trapping-rain-water/description/

class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size(), res=0;
        vector<int> left(n, 0), right(n, 0);
        
        // intially the first value will be max by default 
        left[0] = height[0];
        right[n-1] = height[n-1];
        
        for(int i=1; i<n; ++i){
            // maintain a max value from left to right 
            left[i] = max(left[i-1], height[i]);
            // maintain a max value from right to left 
            right[n-1-i] = max(right[n-i], height[n-1-i]);;
        }
        for(int i=0; i<n; ++i){
            // min of leftMax and rightMax minus current height will be water retain by current bar 
            res += min(left[i], right[i]) - height[i];
        }
        return res;
    }
};