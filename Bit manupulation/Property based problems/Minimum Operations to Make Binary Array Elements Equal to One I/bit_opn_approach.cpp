#include<bits/stdc++.h>
using namespace std;

//Time complexity :- O(n)
//Space complexity :- O(1)

// Approach :-
// we'll traverse from left to right and check if the current value if 0
// then we'll flip the next 3 bit and we'll repeat this process until n-3 index
// if value at n-1 or n-2 is remains 0 then it's not possible otherwise it possible 
// main a counter while flipping the bit and return that as a answer


//link :- https://leetcode.com/problems/minimum-operations-to-make-binary-array-elements-equal-to-one-i/

class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size(), res = 0;
        bool flag = false;

        for(int i=0; i<n-2; ++i){
            if(nums[i] == 0){
                nums[i] = 1 - nums[i];     // nums[i] ^= 1;
                nums[i+1] = 1 - nums[i+1]; // nums[i+1] ^= 1;
                nums[i+2] = 1 - nums[i+2]; // nums[i+2] ^= 1;
                res++;
            }
        }
        if(nums[n-1]==0 || nums[n-2]==0)
            return -1;

        return res;
    }
};

class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size(), res = 0, ind = 0;
        bool flag = false;

        while(ind < n){
            if(nums[ind] == 0){
                if(ind+2 >= n)      return -1;

                for(int i=ind; i<ind+3; ++i)
                    nums[i] = !nums[i];
                ++res;
            }
            ++ind;
        }
        return res;
    }
};