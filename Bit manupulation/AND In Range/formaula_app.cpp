#include<bits/stdc++.h>
using namespace std;

// Time complextiy :- O(log(L))
// Space complexity :- O(1)

// Approach :-   
// there is a formual which make LSB set bit to make 0 i.e (n & (n-1))
// we can apply this on right number to make it either less than or equal to left
// after that if we do left & right, we'll get the common prefix of both 

//Link :- 
// gfg - https://www.geeksforgeeks.org/problems/second-best-minimum-spanning-tree/1
// leetcode - https://leetcode.com/problems/bitwise-and-of-numbers-range/

class Solution {
  public:
    int andInRange(int left, int right) {
        while(left < right){
            right = right & (right - 1);
        }
        return left & right;
    }
};