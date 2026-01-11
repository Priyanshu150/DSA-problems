#include<bits/stdc++.h>
using namespace std;

//Time complexity :- O(n*m)
//Space complexity :- O(1)

// Approach :-
// use same logic as first one 

//link :- https://www.geeksforgeeks.org/problems/minimum-window-subsequence/1

class Solution {
  public:
    string minWindow(string& s1, string& s2) {
        int n = s1.size(), m = s2.size(), minLen = INT_MAX;
        string ans = "";
        
        // traverse on the string from left to right 
        for(int i=0; i<n; ++i){
            // current char s1 matches with first char of s2 
            if(s1[i] == s2[0]){
                int p1 = i, p2 = 0;
                
                // check if all the char of s2 is present in s1 or not 
                while(p1 < n && p2 < m){
                    if(s1[p1] == s2[p2])
                        p2++;
                    
                    p1++;
                }
                // s2 is present in s1 then 
                if(p2 == m){
                    int end = p1-1;
                    p2 = m-1;
                    
                    // backtracks the pointer back to  caluclate the lenght
                    while(end >= i){
                        if(s1[end] == s2[p2])       p2--;
                        if(p2 < 0)      break;
                        end--;
                    }
                    // find the lenght of string 
                    int start = end, len = p1 - start;
                    
                    // update the min len and string 
                    if(len < minLen){
                        minLen = len;
                        ans = s1.substr(start, len);
                    }
                }
            }
        }
        return ans;
    }
};