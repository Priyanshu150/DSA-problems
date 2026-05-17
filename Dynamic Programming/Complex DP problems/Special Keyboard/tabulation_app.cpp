#include<bits/stdc++.h>
using namespace std;

// Time complexity :- O(n^2)
// Space complexity :- O(n)

// Approach :- 
// we've to try all possibilities to find the maximum A values 
// n <= 6 then we can print at max n A's 
// for any number n we have to try pasting the value maximum number of time which we can 
// 3 operation should be taken in order to select copy paste 
// for any number n, the option will be 
// print A to n times or dp[n-3] * 2 or dp[n-4] * 3 or dp[n-5] * 4 and so on 
// wehre 2,3,4 are number of times it get pasted + 1 (which is original string)



// Links :- https://www.geeksforgeeks.org/problems/special-keyboard3018/1

class Solution {
  public:
    int optimalKeys(int n) {
        // base case 
        if(n <= 6) 
            return n;
        
        vector<int> dp(n+1, 0);
        
        // start from 7 to n 
        for(int i=0; i<=n; ++i){
            dp[i] = i;      // print A i number of times 
            
            if(i <= 6)
                continue;
            
            int cnt = 2, num = i-3; // for copying 3 step has to be taken 
            
            // starts pasting the char 
            while(num > 0){
                // current value will be number of times * maximum value we can attain for previous number
                int val = dp[num] * cnt;
                // update the max value of dp 
                dp[i] = max(val, dp[i]);
                // decrement the count of A's by one 
                num--;
                // increment the pasting capacity by 1
                cnt++;
            }
        }
        return dp[n];
    }
};