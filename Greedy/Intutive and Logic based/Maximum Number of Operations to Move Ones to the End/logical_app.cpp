#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(n)
// Space complexity :- O(1)

// Approach :-  
// In-order to get maximum number of operation we'll move left ones first
// hence we'll traverse from left to right, counting the ones & zeros 
// whenever we find 1's or end, the number of operation we'll be the 1's we get before that 
// only if we found any zeros in between i.e. zeros > 0


// Link :- https://leetcode.com/problems/maximum-number-of-operations-to-move-ones-to-the-end/

class Solution {
public:
    int maxOperations(string s) {
        int n = s.size(), ones = 0, zeros = 0, res = 0;

        for(int i=0; i<n; ++i){
            if(s[i] == '1' && zeros>0){
                res += ones;
                zeros = 0;
            }

            if(s[i] == '1')
                ones++;
            else
                zeros++;
        }
        if(zeros > 0)       res += ones;
        return res;
    }
};