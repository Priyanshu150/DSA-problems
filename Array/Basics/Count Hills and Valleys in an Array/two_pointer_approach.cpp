#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(n)  
// Space complexity :- O(1)

// Approach :- 
// use two pointers(i & j), where j is pointing to the current number
// and i will be pointer to previous number which is not equals to j 
// j+1 will be the number on the right side 
// if the condition is satisfied either for hill or valley, the count the contribution 
// and make i = j, intially i(0) & j(1)

// Link :- https://leetcode.com/problems/count-hills-and-valleys-in-an-array/

class Solution {
public:
    int countHillValley(vector<int>& nums) {
        int n = nums.size(), i(0), j(1), res = 0;

        while(j < n-1){
            if((nums[i] < nums[j] && nums[j+1] < nums[j]) || (nums[j] < nums[i] && nums[j] < nums[j+1])){
                res += 1;
                i = j;
            }
            ++j;
        }
        return res;
    }
};