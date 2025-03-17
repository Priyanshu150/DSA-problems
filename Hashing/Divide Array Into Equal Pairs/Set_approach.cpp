#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(n)
// Space complexity :- O(n)

// Approach :-  
// we will use a set to store number 
// if we're getting the number 1st time we'll store in set
// if we got the same number 2nd time we'll delete that number from set
// at last if set is empty then we can make all valid pairs otherwise not

// Link :- https://leetcode.com/problems/divide-array-into-equal-pairs/

class Solution {
public:
    bool divideArray(vector<int>& nums) {
        unordered_set<int> st;

        for(auto num: nums){
            if(st.count(num))   st.erase(num);
            else                st.insert(num);
        }
        return st.empty();
    }
};
