#include<bits/stdc++.h>
using namespace std;

//Time complexity :- O(n)
//Space complexity :- O(n)

// Approach :-
// we can reduce the stack space by converting the memoized solution to tabulized solution
// ind will go from n-1 to 0 and calulate the answer for each index
// based on the same possibilites that we used in memoization
// express the base case first and answer will store at last element of array

//link :- https://www.geeksforgeeks.org/problems/stickler-theif-1587115621/1

class Solution {
  public:
    int findMaxSum(vector<int>& arr) {
        // code here
        int n = arr.size();
        vector<int> dp(n+2, 0);
        
        for(int ind=n-1; ind>=0; --ind)
            dp[ind] = max(dp[ind+1], arr[ind] + dp[ind+2]);
        
        return max(dp[1], dp[0]);
        // or return curr
    }
};