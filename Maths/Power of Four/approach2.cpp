#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(32)
// Space complexity :- O(1)

// Approach :-  
// if a number is -ve, not divible by 4 or not power of 2 then return false 
// If a number is a power of 4 then only even bit will be set otherwise it's not 


//Link :- https://leetcode.com/problems/power-of-four/

class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n == 1)      return true;
        if(n <= 0)      return false;
        if(n % 4)       return false;
        // if number is not power of 2
        if(n & (n-1))   return false;

        for(int bit=0; bit<32; ++bit){
            if(n & (1<<bit)){
                if(bit < 2 || bit%2)
                    return false;
            }
        }
        return true;
    }
};