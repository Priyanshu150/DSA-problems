#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(n)
// Space complexity :- O(1)

// Approach :-   
// formula -> min(leftMax, rightMax) - current_height
// we only need one of the both value to find the contribution of current bar 
// and we also need to traverse on all the cell hence we'll use two pointer technique 
// pick the smallest height from both side and traverse it first 
// maintain left_max_height and right_max_height 
// if we pick left height then, 
// if left_max_height is smaller than current height then update it 
// else use the formula with left_max_height 
// because on the right there will always be someone greater than left_max_height
// since we're traversing in the same pattern 
// repeat the same pattern for right side 
// and move the repsective pointer 

// Link :- https://leetcode.com/problems/trapping-rain-water/description/

class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int left = 0, right = n-1;
        int lmax = 0, rmax = 0, res = 0;

        // two pointer approach
        while(left < right){
            // pick the smaller tower 
            if(height[left] <= height[right]){
                // lmax is smaller then it can hold the water 
                if(lmax <= height[left])
                    lmax = height[left];
                else  
                    // water hold will be lmax - height of current 
                    res += (lmax - height[left]);
                
                left += 1;
            }else{
                // rmax is smaller then it can hold the water 
                if(rmax <= height[right])
                    rmax = height[right];
                else 
                    // water hold will be rmax - height of current 
                    res += (rmax - height[right]);
                
                right -= 1;
            }
        }
        return res;
    }
};