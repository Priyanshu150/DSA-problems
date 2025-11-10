#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(n*d)  , where d is the number of elements in array 
// Space complexity :- O(n)

// Approach :-  
// store the unique element into the set 
// for each number traverse on array and find the minimum number of operations you'll apply

// Link :- https://leetcode.com/problems/minimum-operations-to-convert-all-elements-to-zero/

class Solution {
public:
    int minOperations(vector<int>& nums) {
        // add every element to hash-set
        unordered_set<int> st(nums.begin(), nums.end());
        int n = nums.size(), res = 0;

        for(auto target: st){
            if(target == 0)
                continue;

            bool flag = false;

            for(int i=0; i<n; ++i){
                if(nums[i] == target){
                    if(!flag){
                        flag = true;
                        res++;
                    }
                }
                else if(nums[i] < target)
                    flag = false;
            }
        }
        return res;
    }
};