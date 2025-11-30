#include<bits/stdc++.h>
using namespace std;

//Time complexity :- O(N)
//Space complexity :- O(1)

//Approach :-
// Assume intial value of array as [0 0] if derived[0] = 0
// Else [0 1] when derived[0] = 1;
// You can also take [1, 1] and [1, 0]
//Build the array by taking xor from derived element and current number at ith place of array
// Verify the last value and first value of xorr
//If it matches then it's correct otherwise it's not
// Instead of making an array we can also take two variable first & prev and build whole array


//link :- https://leetcode.com/problems/neighboring-bitwise-xor/

class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        int n = derived.size(), first(0), prev(0);
        if(n == 1)              return (derived[0] == 1) ? false : true;
        if(derived[0] == 1)     prev = 1;

        for(int i=1; i<n-1; ++i)
            prev ^= derived[i];
        
        return (first^prev) == derived[n-1];
    }
};
