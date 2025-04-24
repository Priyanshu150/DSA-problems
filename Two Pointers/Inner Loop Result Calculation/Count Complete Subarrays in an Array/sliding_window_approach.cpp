#include<bits/stdc++.h>
using namespace std;

//Time complexity :- O(n)
//Space complexity :- O(1)

// Approach :-
// count the number is distinct element in whole array (cnt) also maintain a vaiable for distinct in subarray (distinct)
// try applying sliding window to calculate the subarray, left & right ptr
// while moving right ptr, hash the element and if it's appearing first time the distinct will increase by 1
// if we got distinct == cnt, then all the element on left side of right ptr will also be valid 
// calculate the answer accordinly and remove element from left ptr using hashing
// if the element cnt becomes 0 that means distinct need to be decrement by 1


//link :- https://leetcode.com/problems/count-complete-subarrays-in-an-array/

class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        int n = nums.size(), distinct_in_array = 0;
        unordered_map<int,int> mp;

        for(int i=0; i<n; ++i)
            mp[nums[i]] += 1;
        
        distinct_in_array = mp.size();
        mp.clear();

        int distinct_in_sub = 0, i = 0, j = 0, res = 0;

        while(j < n){
            mp[nums[j]] += 1;
            if(mp[nums[j]] == 1) 
                distinct_in_sub += 1;
            
            while(distinct_in_sub == distinct_in_array){
                res += (n - j);
                mp[nums[i]] -= 1;

                if(mp[nums[i]] == 0)
                    distinct_in_sub -= 1;
                
                i++;
            }
            j++;
        }
        return res;
    }
};