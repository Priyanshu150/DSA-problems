#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(n)
// Space complexity :- O(n)

// Approach :-  
// Traverse the string by each char and use stack to track the characters
// if we got digit pop prev char from the stack otherwise push into the stack

// Link :- https://leetcode.com/problems/clear-digits/description/

class Solution {
    public:
        string clearDigits(string s) {
            stack<char> st;
    
            for(auto ch: s){
                if(isdigit(ch)){
                    if(!st.empty())
                        st.pop();
                }
                else    st.push(ch);
            }
            string res = "";
            
            while(!st.empty()){
                res = st.top() + res;
                st.pop();
            }
            return res;
        }
    };