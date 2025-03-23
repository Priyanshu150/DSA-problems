#include<bits/stdc++.h>
using namespace std;

//Time complexity :- O(V+E)
//Space complexity :- O(V)

// Approach :-
// Trying all posibities will work here since we've to create all sequence. Hence, we'll use recursion
// Ind will be only changing parameter here, Trying all possibilities we'll check that what 1 or 2 digit number we can make
// we can use a for loop inside a recursion to traverse on digit and calculate corresponding numbers
// if the number is less than 27 the we can call the recursion further to solve and accumulate all the ways in a variable
// otherwise we can break the loop from that point 
// base case will be, ind reach n there is 1 valid ways 
// whenever the first index it pointing to a zero then making a number from that will not be possible

// since there is only 1 state changing we can make 1-d dp array and initialize all the value to -1
// We've the save the answer of each index inorder to not recalculate again

//link :- https://www.geeksforgeeks.org/problems/total-decoding-messages1235/1

class Solution {
  private:
    int solve(int ind, int &n, string &digit, vector<int> &dp){
        if(ind == n)        return 1;
        if(digit[ind] == '0')   return 0;
        if(dp[ind] != -1)   return dp[ind];
        
        int ways = 0, num = 0;
        
        for(int i=ind; i<n; ++i){
            num = num*10 + (digit[i]-'0');
            
            if(num < 27)
                ways += solve(i+1, n, digit, dp);
            else
                break;
        }
        return dp[ind] = ways;
    }
  
  public:
    int countWays(string &digit) {
        // Code here
        int n = digit.size();
        vector<int> dp(n, -1);
        return solve(0, n, digit, dp);
    }
};