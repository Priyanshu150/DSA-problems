#include<bits/stdc++.h>
using namespace std;

//Time complexity :- O(N^2)
//Space complexity :- O(N)

// Approach :-
// we can express the memoized approach in term of tabulation that way space space will be reduced 
// ind will go from n-1 to 0 vice versa of recursion 
// express the base case in the array first and the possbilities remains same 
// instead of recusion make use of dp array 

//link :- https://www.geeksforgeeks.org/problems/total-decoding-messages1235/1

class Solution {
  public:
    int countWays(string &digit) {
        // Code here
        int n = digit.size();
        vector<int> dp(n+1, 0);
        dp[n] = 1;
        
        for(int ind=n-1; ind>=0; --ind){
            int num = 0;
            if(digit[ind] == '0')   continue;
            
            for(int i=ind; i<n; ++i){
                num = num*10 + (digit[i]-'0');
                
                if(num < 27)
                    dp[ind] += dp[i+1];
                else
                    break;
            }
        }
        return dp[0];
    }
};