#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(N)  
// Space complexity :- O(1)

// Approach :-
// We'll be using only two value for curr_ind which is ind-1 and ind-2
// instead of using a 1-d array we can keep track of 2 variable depending on that we can calculate our answer
// we'll store the base case in prev1 = cost[0] & prev = cost[1]
// looping from 2 to n we can calculate curr_ind value and update prev1 to prev & prev to curr
// At last out answer will be store at prev

// Link :- https://www.geeksforgeeks.org/problems/min-cost-climbing-stairs/1

class Solution {
  public:
    int minCostClimbingStairs(vector<int>& cost) {
        // Write your code here
        int n = cost.size(), prev1 = cost[0], prev = cost[1];
        
        for(int ind=2; ind<=n; ++ind){
            int val = (ind == n) ? 0 : cost[ind];
            int curr = val + min(prev1, prev);
            prev1 = prev;
            prev = curr;
        }
        return prev;
    }
};