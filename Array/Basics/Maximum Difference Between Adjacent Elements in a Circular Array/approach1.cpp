#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(N)
// Space complexity :- O(1)

// Approach :-  
// use modulo operation to handle case of overflow 


// Link :- https://leetcode.com/problems/maximum-difference-between-adjacent-elements-in-a-circular-array/

class Solution {
public:
    int maxAdjacentDistance(vector<int>& nums) {
        int n = nums.size(), res = 0;

        for(int i=1; i<=n; ++i){
            int diff = abs(nums[(i-1)%n] - nums[i%n]);
            res = max(res, diff);
        }
        return res;
    }
};