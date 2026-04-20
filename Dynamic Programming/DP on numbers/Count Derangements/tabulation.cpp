#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(n)
// Space complexity :- O(n)


// Link :- https://www.geeksforgeeks.org/problems/dearrangement-of-balls0918/1

class Solution {
  public:
    int derangeCount(int n) {
        vector<int> dp(n+1, 0);
        // base case 
        dp[2] = 1;
        dp[3] = 2;
        
        for(int num=4; num<=n; ++num){
            dp[num] = (num-1) * (dp[num-1] + dp[num-2]);
        }
        return dp[n];
    }
};