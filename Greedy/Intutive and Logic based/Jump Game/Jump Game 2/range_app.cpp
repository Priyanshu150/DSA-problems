#include<bits/stdc++.h>
using namespace std;

//Time complexity :- O(n)
//Space complexity :- O(1) 

// Approach :-
// try to maintain a range after every range [left ,right]
// if the right reach end, then we're done. Just keep a count of jumps take so far 
// in this way we will eliminate the need to evaluate each index and their jump
// after every jump the range can be update as :-
// left = right+1 and right = fartherst point reachable from current range 

//link :- https://leetcode.com/problems/jump-game-ii/

class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        // let [left, right] be the range for each jumps 
        int left = 0, right = 0, jumps = 0;

        // untill right reach end 
        while(right < n-1){
            int farthest = 0;
            // from current range, find the maximum range that can be reached 
            for(int i=left; i<=right; ++i){
                farthest = max(farthest, nums[i]+i);
            }
            // update the next range to [right+1, farthest]
            left = right+1;
            right = farthest;
            // increment the jumps count 
            jumps++;
        }
        return jumps;
    }
};