#include<bits/stdc++.h>
using namespace std;

// Time complexity :- O(log(digit))
// Space complexity :- O(1)

// Approach :- 
// count the number of bit in pos-1, if odd then it will be "Doctor" otherwise "Engineer"

// Link :- https://www.geeksforgeeks.org/problems/finding-profession3834/1

class Solution {
  public:
    string profession(int level, int pos) {
        int countBits = __builtin_popcount(pos - 1);
        return (countBits % 2 == 1) ? "Doctor" : "Engineer";
    }
};