#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(n)
// Space complexity :- O(1)


// Link :- https://www.geeksforgeeks.org/problems/dearrangement-of-balls0918/1

class Solution {
  public:
    int derangeCount(int n) {
        if(n <= 3)      return n-1;
        // base case 
        int prev1 = 1, prev = 2;
        
        for(int num=4; num<=n; ++num){
            int curr = (num-1) * (prev + prev1);
            prev1 = prev;
            prev = curr;
        }
        return prev;
    }
};