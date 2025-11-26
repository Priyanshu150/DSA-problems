#include<bits/stdc++.h>
using namespace std;

// Time complextiy :- O(log(L))
// Space complexity :- O(1)

// Approach :-   
// on bit level, if we find the common prefix or both bit 
// and make all 0 from left side of that bit then that will be our answer 
// hence we'll move left >> 1 and right >> 1, until they are same or left becomes 0
// we'll count the number of shift done
//  and finally we'll shift the common number that number of times making rest of numbers as 0

//Link :- 
// gfg - https://www.geeksforgeeks.org/problems/second-best-minimum-spanning-tree/1
// leetcode - https://leetcode.com/problems/bitwise-and-of-numbers-range/

class Solution {
  public:
    int andInRange(int l, int r) {
        int shiftCount = 0;
        
        while(l != r && l>0){
            shiftCount++;
            l = l>>1;
            r = r>>1;
        }
        return (l << shiftCount);
    }
};