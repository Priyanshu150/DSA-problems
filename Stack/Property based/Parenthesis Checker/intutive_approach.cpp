#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(n)
// Space complexity :- O(n)

// Approach :-
// use stack to keep open brackets so that whenever we get a closing braket we can check the previous one
// If it's matching type then pop it, otherwise if not matching or empty it's not balanced
// At last stack should be empty

// Link :- https://www.geeksforgeeks.org/problems/parenthesis-checker2744/1

class Solution {
  public:
    bool isBalanced(string& s) {
        // code here
        stack<char> st;
        
        for(auto ch: s){
            if(ch == '}' || ch == ']' || ch == ')'){
                if(st.empty())  return false;
                if(ch == '}' && st.top() != '{')    return false;
                if(ch == ']' && st.top() != '[')    return false;
                if(ch == ')' && st.top() != '(')    return false;
                st.pop();
            }
            else
                st.push(ch);
        }
        return st.empty();
    }
};