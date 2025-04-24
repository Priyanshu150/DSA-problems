#include<bits/stdc++.h>
using namespace std;

//Time complexity :- O(n)
//Space complexity :- O(n)

// Approach :-
// count the number of distinct in whole array using hashing
// using brute force, try creating all the subarray and cnt the distinct element in that subarray 
// if both's distinct count match then cnt the number of times it happened 


//link :- https://leetcode.com/problems/count-complete-subarrays-in-an-array/

class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        set<int> st(nums.begin(), nums.end());
        int n = nums.size(), sz = st.size(), cnt=0;
        
        for(int i=0; i<n; ++i){
            st.clear()
            for(int j=i; j<n; ++j){
                st.insert(nums[j]);
                if(st.size() == sz)
                    cnt++;
            }
        }
        return cnt;
    }
};
