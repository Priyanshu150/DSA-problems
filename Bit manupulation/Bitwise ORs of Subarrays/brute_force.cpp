#include<bits/stdc++.h>
using namespace std;

//Time complexity :- O(N*N)
//Space complexity :- O(N)

// Approach :-
// Generate each sub-array and calculate xorr of them 
// store them in a set and at last return the count of set size 

// link :- https://leetcode.com/problems/bitwise-ors-of-subarrays/

class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        int n = arr.size();
        unordered_set<int> st;

        for(int i=0; i<n; ++i){
            int orrValue = 0;
            for(int j=i; j<n; ++j){
                orrValue |= arr[j];
                st.insert(orrValue);
            }
        }
        return st.size();
    }
};