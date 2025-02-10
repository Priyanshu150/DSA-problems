#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(n)
// Space complexity :- O(n)

// Approach :-  
// Traverse the string by each char and build the answer simultanuously
// if we got digit pop prev char from the string otherwise add that into the string

// Link :- https://leetcode.com/problems/clear-digits/description/


class Solution {
    public:
        string clearDigits(string s) {
            string res = "";
    
            for(auto ch: s){
                if(isdigit(ch))         res.pop_back();
                else    res += ch;
            }
            return res;
        }
    };