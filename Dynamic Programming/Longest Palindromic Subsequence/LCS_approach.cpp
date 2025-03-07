#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(N*N)
// Space complexity :- O(N*N)

// Approach :-
// If we reverse the given string and find the lcs b/w reversed and original string 
// that will be out longest palindromic sequence 


// Link :- https://www.geeksforgeeks.org/problems/longest-palindromic-subsequence-1612327878/1

class Solution {
  private:
    int lcs(string &s1, string &s2) {
        // code here
        int n = s1.size(), m = s2.size();
        vector<int> prev(m+1, 0), curr(m+1, 0);
        
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
  
  public:
    int longestPalinSubseq(string &s) {
        // code here
        string t = s;
        reverse(t.begin(), t.end());
        return lcs(s, t);
    }
};
