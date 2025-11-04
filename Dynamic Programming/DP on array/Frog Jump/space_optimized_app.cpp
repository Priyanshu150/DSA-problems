#include<bits/stdc++.h>
using namespace std;

//Time complexity :- O(n)
//Space complexity :- O(1)

// Approach :-
// optimized the tabulation approach by keeping track of next two value stored in variable 

//link :- https://www.geeksforgeeks.org/problems/geek-jump/1

class Solution {
  public:
    int minCost(vector<int>& height) {
        // Code here
        int n = height.size();
        if(n == 1)
            return 0;
            
        vector<int> dp(n);
        int prev1 = 0;
        int prev = abs(height[n-1] - height[n-2]);
        
        for(int i=n-3; i>=0; --i){
            int oneJump = prev + abs(height[i] - height[i+1]);
            int twoJump = prev1 + abs(height[i] - height[i+2]);
            int curr = min(oneJump, twoJump);
            prev1 = prev;
            prev = curr;
        }
        return prev;
    }
};