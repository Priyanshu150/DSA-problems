#include<bits/stdc++.h>
using namespace std;

//Time complexity :- O(n*m)
//Space complexity :- O(1)

// Approach :-
// parallely traverse on both the string once the second string expires 
// check wheather it's smallest than the previous observed, then update the answer 
// othewise skip it 

//link :- https://www.geeksforgeeks.org/problems/minimum-window-subsequence/1

class Solution {
  public:
    string minWindow(string& s1, string& s2) {
        int i = 0, j = 0, k = 0, res = INT_MAX;
        int n = s1.size(), m = s2.size();
        string str;
        
        // traverse on the s1 and s2 parallely 
        while(j < n && k < m){
            // if both are matching, move the s2 ptr 
            if(s1[j] == s2[k]){
                k++;
            }
            
            // s2's ptr reach end
            if(k == m){
                i = j, k = m-1;
                
                // backtrack till the index where it start in s1 
                while(i >= 0 && k >= 0){
                    if(s1[i] == s2[k]){
                        k--;
                    }
                    i--;
                }
                i++;
                
                // update the length and string to have lowest value 
                if(res > j-i+1){
                    res = j-i+1;
                    str = s1.substr(i, j-i+1);
                }
                // reset the values 
                k = 0, j = i+1;
            }
            j++;
        }
        return str;
    }
};
