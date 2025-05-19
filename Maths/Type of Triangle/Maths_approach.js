#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(1)
// Space complexity :- O(1)

// Approach :-  
// check whether the give sides form a triangle or not then check for respective conditions 

//Link :- https://leetcode.com/problems/type-of-triangle/


var triangleType = function(nums) {
    if(nums[0] + nums[1] <= nums[2])         return "none";
    else if(nums[1] + nums[2] <= nums[0])     return "none";
    else if(nums[0] + nums[2] <= nums[1])     return "none";
    else if(nums[0] == nums[1] && nums[1] == nums[2])
        return "equilateral";
    else if(nums[0] == nums[1] || nums[1] == nums[2] || nums[0] == nums[2])
        return "isosceles";

    return "scalene";
};