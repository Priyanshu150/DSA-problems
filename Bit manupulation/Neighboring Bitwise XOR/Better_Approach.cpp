#include<bits/stdc++.h>
using namespace std;

//Time complexity :- O(N)
//Space complexity :- O(1) 

//Approach :-
// Derived[i] = arr[i]^arr[i+1]
// Then every element is occuring twice
// Xor of same number is zero
// find xor of derived array
// if it's equal to 0 then it's possible otherwise not

//link :- https://leetcode.com/problems/neighboring-bitwise-xor/

class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        int n = derived.size(), xorr = 0;

        for(int i=0; i<n; ++i)
            xorr ^= derived[i];
        
        return (xorr == 0);
    }
};
