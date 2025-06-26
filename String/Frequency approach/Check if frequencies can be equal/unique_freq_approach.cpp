#include<bits/stdc++.h>
using namespace std;

//Time complexity :- O(N)       
//Space complexity :- O(26)    

//Approach :-
// Count the frequency of each char, and again count how many unique frequency exists 
// if unique frequency is greater than 2 then return false 
// if only 1 unique frequency exist then return true 
// otherwise if 2 unique frequency exists then check these conditions 
// 1. it should either be 1 char having 1 freq 
// 2. both freq should have diff of 1 and only 1 cnt of freq should exist which have higher frequency

// Link :- https://www.geeksforgeeks.org/problems/check-frequencies4211/1

class Solution {
  public:
    bool sameFreq(string& s) {
        // code here
        vector<int> freq(26, 0);
        
        for(auto ch: s){
            freq[ch - 'a'] += 1;
        }
        int cnt1 = 0, freq1 = -1, cnt2 = 0, freq2 = -1;
        
        for(int i=0; i<26; ++i){
            if(freq[i] == 0)
                continue;
            else if(freq[i] == freq1)
                cnt1++;
            else if(freq[i] == freq2)
                cnt2++;
            else if(freq1 == -1){
                freq1 = freq[i];
                cnt1 = 1;
            }
            else if(freq2 == -1){
                freq2 = freq[i];
                cnt2 = 1;   
            }
            else
                return false;
        }
        if(freq2 == -1)     return true;
        if(freq1 == 1 && cnt1 == 1)     return true;
        if(freq2 == 1 && cnt2 == 1)     return true;
        if(abs(freq1 - freq2) == 1){
            if(freq1 > freq2 && cnt1 == 1)
                return true;
            if(freq2 > freq1 && cnt2 == 1)
                return true;
        }
        return false;
    }
};