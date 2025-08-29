#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(sizeof(s) + sizeof(p))
// Space complexity :- O(26)

// Approach :- 
// for matching the frequency of both string we can keep track of them in frequency array
// and later match their freq in constant time 
// using sliding window approach we'll generate a valid window
// a valid window where more or equal number of char are present in substring of s compared to string p 
// we'll use length variable to keep track of smallest length window and index of substring(i & j)
// Include the char in substring, until it falls under valid window
// after that start removing the char from left side of window to make it small
// until the window becomes unvalid and repeat the process untill string s expires 


//Link :- https://www.geeksforgeeks.org/problems/smallest-window-in-a-string-containing-all-the-characters-of-another-string-1587115621/1

class Solution {
  private:
    bool match(int freq1[], int freq2[]){
        for(int i=0; i<26; ++i){
            if(freq2[i] > freq1[i])
                return false;
        }
        return true;
    }
  

  public:
    string smallestWindow(string &s, string &p) {
        // code here
        int freqp[26] = {0}, freqs[26] = {0};
        
        for(auto ch: p)
            freqp[ch - 'a'] += 1;
        
        int left = 0, n = s.size();
        int minLen = n+1, i=-1, j=-1;
        
        for(int right=0; right<n; ++right){
            freqs[s[right] - 'a'] += 1;
            
            while(match(freqs, freqp)){
                if(minLen > (right - left + 1)){
                    minLen = right - left + 1;
                    i = left;
                    j = right;
                }
                
                freqs[s[left] - 'a'] -= 1;
                ++left;
            }
        }
        
        if(minLen == n+1)
            return "";
        
        string ans = "";
        for(int ind=i; ind<=j; ++ind)
            ans += s[ind];
        
        return ans;
    }
};