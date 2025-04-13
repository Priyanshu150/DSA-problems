#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(N*M)
// Space complexity :- O(N)

// Approach :-
// Instead of making 2d array for dp state, we can only maintain 2 1d array that will suffice
// because for every iteration we're needed only the prev col of dp and curr col
// that ways we can reduce the space and maintain only two arrays
// and rest the approach remains same to tabulation 

// Link :- https://www.geeksforgeeks.org/problems/longest-common-subsequence-1587115620/1

class Solution {
  public:
    int lcs(string &s1, string &s2) {
        // code here
        int n = s1.size(), m = s2.size();
        vector<int> prev(m+1, 0), curr(m+1, -1);
        
        for(int i=1; i<=n; ++i){
            for(int j=1; j<=m; ++j){
                if(s1[i-1] == s2[j-1])
                    curr[j] = 1 + prev[j-1];
                else
                    curr[j] = max(curr[j-1], prev[j]);
            }
            prev = curr;
        }
        return prev[m];
    }
};