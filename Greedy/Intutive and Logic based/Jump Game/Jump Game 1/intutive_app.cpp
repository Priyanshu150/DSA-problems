#include<bits/stdc++.h>
using namespace std;

//Time complexity :- O(n)
//Space complexity :- O(n) 

//link :- https://leetcode.com/problems/jump-game/description/

// approach1 :- 
// try to maintain a max jump variable and traverse on each index 
// if current index become greater than max index maintained so far then it's not reachble 
// otherwise we max index cross last one we can mark it as visited 

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size(), maxInd = 0;

        for(int i=0; i<n; ++i){
            // if current index is not reachable then it's not possible 
            if(i > maxInd)
                return false;
            
            // maintain a maximum index indicating till where max we can reach after every jump
            int nextInd = i+nums[i];
            maxInd = max(maxInd, nextInd);
        }
        return true;
    }
};

// approach2 :- 
// using the logic from jump game 2 
// we'll try to maintain a range after every jump
// if at any pointer the range remain same that mean we can go further 
// otherwise it's always possible 

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        // let [left, right] be the range for each jumps 
        int left = 0, right = 0, jumps = 0, prevRight = -1;

        // untill right reach end 
        while(right < n-1){
            int farthest = 0;
            if(prevRight == right)
                return false;
            
            // from current range, find the maximum range that can be reached 
            for(int i=left; i<=right; ++i){
                farthest = max(farthest, nums[i]+i);
            }

            prevRight = right;
            // update the next range to [right+1, farthest]
            left = right+1;
            right = farthest;
        }
        return true;
    }
};