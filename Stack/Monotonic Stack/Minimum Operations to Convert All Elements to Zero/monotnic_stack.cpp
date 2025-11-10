#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(2*n)
// Space complexity :- O(n)

// Approach :-  
// we'll use stack to solve this problem, using monotonic stack
// whenever a new element comes in we've to push into the stack and res += 1
// if the number is 0 we'll skip it, and we'll maintain a monotonic stack
// that means we'll pop bigger number from the stack until the top is smaller than current number
// avoid having continous repeatative number, only push when to st.top() != nums[i]

// Link :- https://leetcode.com/problems/minimum-operations-to-convert-all-elements-to-zero/

class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size(), res = 0;
        stack<int> st;

        for(int i=0; i<n; ++i){
            // maintian a monotonic stack
            while(!st.empty() && st.top() > nums[i])
                st.pop();
            
            // current element already a 0
            if(nums[i] == 0)
                continue;
            
            // push only those element which are greater than curret top element of stack
            if(st.empty() || st.top() != nums[i]){
                res++;
                st.push(nums[i]);
            }
        }
        return res;
    }
};