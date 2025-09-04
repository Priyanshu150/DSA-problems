#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(1)
// Space complexity :- O(1)


// Link :- https://leetcode.com/problems/find-closest-person/

class Solution {
public:
    int findClosest(int x, int y, int z) {
        int diff1 = abs(x - z), diff2 = abs(y - z);
        if(diff1 < diff2)       return 1;
        if(diff2 < diff1)       return 2;
        return 0;
    }
};