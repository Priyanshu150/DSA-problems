#include<bits/stdc++.h>
using namespace std;

//Time complexity :- O(N)       
//Space complexity :- O(26)    

//Approach :-
// Count the frequency of each char 
// Count the number of char have odd freq
// if oddCnt <= k then it is possible to create k palidromic string

class Solution {
public:
    bool canConstruct(string s, int k) {
        int n = s.size();
        if(n < k)       return false;
        if(n == k)      return true;
        
        int freq[26] = {0};
        for(auto ch: s)
            freq[ch - 'a'] += 1;

        int oddCnt = 0;
        for(int i=0; i<26; ++i){
            if(freq[i]>0){
                if(freq[i]%2)
                    oddCnt++;
            }
        }
        return oddCnt <= k;
    }
};