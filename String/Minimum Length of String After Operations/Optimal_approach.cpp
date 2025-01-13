#include<bits/stdc++.h>
using namespace std;

//Time complexity :- O(N + 26)
//Space complexity :- O(26)    

//Approach :-
// Count the frequency of each char in the string
// If the count of a char is odd then all the character can be deleted except 1
// If the count of a char is even then all the character can be deleted except 2

//link :- https://leetcode.com/problems/minimum-length-of-string-after-operations/description/

class Solution {
public:
    int minimumLength(string s) {
        int freq[26] = {0};

        for(auto ch: s)
            freq[ch - 'a'] += 1;
        
        int res = 0;
        for(int i=0; i<26; ++i){
            if(freq[i] == 0)    continue;
            if(freq[i]%2)       res += 1;
            else    res += 2;
        }
        return res;
    }
};