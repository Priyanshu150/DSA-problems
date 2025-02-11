#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O((n + m)*n) // where m is size of part and n is the size of s
// Space complexity :- O(n)

// Approach :-  
// Use stack to store char of the string
// Traverse the string char by char and store each char in stack
// Check if the last char of part is matching with current char and also the size of stack is greater than size of m 
// If yes, then take out the top m char of stack and match with part 
// If doensn't match then put it back in stack

// Link :- https://leetcode.com/problems/remove-all-occurrences-of-a-substring/description/

class Solution {
private:
    void check(stack<char> &st, string &part, int &m){
        string temp = "";

        for(int i=0; i<m; ++i){
            temp = st.top() + temp;
            st.pop();
        }
        if(temp == part)    return;

        for(auto ch: temp)
            st.push(ch);
    }

public:
    string removeOccurrences(string s, string part) {
        int n = s.size(), m = part.size();

        if(n <= m){
            if(s == part)       return "";
            return s;
        }
        stack<char> st;

        for(auto ch: s){
            st.push(ch);
            
            if(ch == part[m-1] && st.size() >= m)
                check(st, part, m);
        }
        string res = "";

        while(!st.empty()){
            res = st.top() + res;
            st.pop();
        }
        return res;
    }
};