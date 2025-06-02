#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(n*n)
// Space complexity :- O(1)

// Approach :- 
// using lis find the longest palindromic string (lps)
// The the all the redundant char apart from lps needs to be deleted i.e. length - lps

// Link :- https://www.geeksforgeeks.org/problems/minimum-deletitions1648/1

class Solution {
  private:
    int lcs(string s, string t, int &n){
        vector<int> prev(n+1, 0), curr(n+1, 0);
        
        for(int i=1; i<=n; ++i){
            for(int j=1; j<=n; ++j){
                if(s[i-1]==t[j-1])
                    curr[j] = 1+prev[j-1];
                else 
                    curr[j] = max(prev[j], curr[j-1]);
            }
            prev = curr;
        }
        return prev[n];
    }
  
  public:
    int minDeletions(string s) {
        // code here
        int n = s.size();
        string t = s;
        reverse(begin(t), end(t));
        return n-lcs(s, t, n);
    }
};