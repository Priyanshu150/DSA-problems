#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(log4(n))
// Space complexity :- O(1)

// Approach :-  
// if the number is -ve then it's not possible
// divide the number as long as divisble 
// if at last the remainder is 1 then we can say that it's power of 2


//Link :- https://leetcode.com/problems/power-of-four/

class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n <= 0)      return false;
        
        while(n%4 == 0)
            n /= 4;
        
        return (n == 1);
    }
};