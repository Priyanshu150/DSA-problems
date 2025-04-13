#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(N*M)
// Space complexity :- O(M)

// Approach :-
// We've further reduced the time time complexity, as we only need prev col of 2d matrix dp
// so we'll maintain 2 array => prev & curr instead of 2d array => dp
// and we can use the same logic and chang the condition accordingly

// Link :- https://www.geeksforgeeks.org/problems/edit-distance3702/1

class Solution {
  public:
    // Function to compute the edit distance between two strings
    int editDistance(string& s1, string& s2) {
        // code here
        int n = s1.size(), m = s2.size();
        vector<int> prev(m+1, 0), curr(m+1, 0);
        
        for(int j=0; j<=m; ++j)
            prev[j] = j;
        
        for(int i=1; i<=n; ++i){
            curr[0] = i;
            for(int j=1; j<=m; ++j){
                if(s1[i-1] == s2[j-1])
                    curr[j] = prev[j-1];
                else{
                    int insert = curr[j-1];
                    int rem = prev[j];
                    int replace = prev[j-1];    
                    
                    curr[j] = 1 + min({insert, rem, replace});
                }
            }
            prev = curr;
        }
        return prev[m];
    }
};