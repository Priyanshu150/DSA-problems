#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(N + M)
// Space complexity :- O(1)

// Approach :- 
// Don't assume that after collision ant changes it's path instead they are going in normal directions
// so find the timing of each ant who'll reach the end and take the maximum time as answer 


// Link :- https://www.geeksforgeeks.org/problems/last-moment-before-all-ants-fall-out-of-a-plank/1

class Solution {
  public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        // code here
        int res = 0;
        
        for(auto pos: left)
            res = max(res, pos);
        
        for(auto pos: right)
            res = max(res, n - pos);
        
        return res;
    }
};
