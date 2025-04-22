#include<bits/stdc++.h>
using namespace std;

//Time complexity :- O(n)
//Space complexity :- O(1)

// Approach :-
// if every number is occuring twice except for 1 then the xorr will give us that number
// because the ^ of two same number will be 0


//link :- https://www.geeksforgeeks.org/problems/find-unique-number/1

class Solution {
  public:
    int findUnique(vector<int> &arr) {
        // code here
        int xorr = 0;
        
        for(auto num: arr)
            xorr ^= num;
        
        return xorr;
    }
};