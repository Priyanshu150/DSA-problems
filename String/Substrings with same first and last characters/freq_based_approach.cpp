#include<bits/stdc++.h>
using namespace std;

//Time complexity :- O(sz*sz*m*n)   
//Space complexity :- O(1)

// Approach :- 
// count the frequency of each character in the stirng 
// for every char which has freq greater than 1 it will contribute to n*(n + 1)/2 substring
// which is sum of n natural numbers, we can caluclate freq-1 sum using this formula
// add the size of string into the result formed because individual char will also be substring

//Link :- https://www.geeksforgeeks.org/problems/substrings-with-similar-first-and-last-characters3644/1

class Solution {
  private:
    int substringCnt(int num){
        return (num * (num+1))/2;
    }
  
  public:
    int countSubstring(string &s) {
        // code here
        int freq[26] = {0}, res = 0, n = s.size();
        
        for(int i=0; i<n; ++i)
            freq[s[i] - 'a'] += 1;
        
        for(int i=0; i<26; ++i){
            if(freq[i] > 1)
                res += substringCnt(freq[i]-1);
        }
        return res+n;
    }
};