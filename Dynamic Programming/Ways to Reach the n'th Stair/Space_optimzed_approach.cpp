#include<bits/stdc++.h>
using namespace std;

//Time complexity :- O(N)
//Space complexity :- O(1)

// Approach :-
// For calulation of number of way to reach n stairs, we can deduce the formula which will be
// calculation till (n-1) step + calculation till (n-2) steps
// we can use two variable to keep track of previous two step value 
// we can loop from 4 to n and repeat the process to get our result 

//link :- https://www.geeksforgeeks.org/problems/count-ways-to-reach-the-nth-stair-1587115620/1

class Solution {
  public:
    int countWays(int n) {
        // your code here
        if(n < 4)   return n;
        
        int prev1 = 2, prev = 3;
        
        for(int i=4; i<=n; ++i){
            int curr = prev + prev1;
            prev1 = prev;
            prev = curr;
        }
        return prev;
    }
};
