#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(n + m)
// Space complexity :- O(1)

// Approach :-  
// traverse the s2 string from left to right and maintain a ind = 0 for s1
// matching char found in both then move the ind by 1
// if at any point we move traverse whole s1 string then return true 
// other after traversing the whole s2 string we've not reached at last return false 


// Link :- https://www.geeksforgeeks.org/problems/given-two-strings-find-if-first-string-is-a-subsequence-of-second/1

class Solution {
  public:
    bool isSubSeq(string& s1, string& s2) {
        // code here
        int n = s1.size(), m = s2.size(), ind = 0;
        
        for(int i=0; i<m; ++i){
            if(s1[ind] == s2[i])
                ind++;
            
            if(ind == n)
                return true;
        }
        return false;
    }
};