#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(n)
// Space complexity :- O(n)

// Approach :-   
// Use sliding window technique, use left and right pointer to mark a window
// traverse the right pointer and update the count of element 
// if the count is greater that 1, that means a pair exists 
// The number repeats in a window and prev count is cnt then it'll contribute to cnt-1 pairs 
// A valid window will exist if count of pairs in window is greater than k 
// for a valid subarray, the count will be (n - right_ptr)
// move the left pointer and decrement the count of number at left_ptr
// The pairs that will be removed from removing current number will be cnt-1 pairs, where cnt is freq of that nubmer 


// Link :- https://leetcode.com/problems/count-the-number-of-good-subarrays/

class Solution {
    #define ll long long 

public:
    long long countGood(vector<int>& nums, int k) {
        int n = nums.size(), left = 0;
        ll res = 0, pairs = 0;
        unordered_map<int,int> mp;

        for(int right=0; right<n; ++right){
            mp[nums[right]] += 1;
            if(mp[nums[right]] > 1)
                pairs += (mp[nums[right]] - 1);

            while(k <= pairs){
                res += (n - right);
                mp[nums[left]] -= 1;
                pairs -= mp[nums[left]];
                left++;
            }
        }
        return res;
    }
};

