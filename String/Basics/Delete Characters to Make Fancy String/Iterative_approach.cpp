#include<bits/stdc++.h>
using namespace std;

//Time complexity :- O(n)   
//Space complexity :- O(1)

// Approach :-
// traverse the string and make a result string
// if the result string size is greater than 2 and previous 2 char are same 
// the skip current char otherwise add the char to result string

//Link :- https://leetcode.com/problems/delete-characters-to-make-fancy-string/

class Solution {
public:
    string makeFancyString(string s) {
        int n = s.size(), sz = 0;
        if(n < 3)   return s;

        string res = "";

        for(auto ch: s){
            if(2 <= sz && res[sz-1] == ch && ch == res[sz-2])
                continue;
            
            res += ch;
            sz++;
        }
        return res;
    }
};