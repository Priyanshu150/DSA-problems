#include<bits/stdc++.h>
using namespace std;

// Time Complexity: O(n)
// Space Complexity: O(n)

// Approach :- 
// use stack to store the string and numbers in form of string 
// push any other char into the stack
// and whenver we get an open bracket ']' we pop until we found a open bracket '['
// and next we take and number and find the final number 
// repeat the string that number of time and push that into the stack 

// Link :- https://www.geeksforgeeks.org/problems/decode-the-string2444/1

class Solution {
public:
    string decodedString(string &s) {
        stack<string> st;
        
        for(char ch : s){
            if(ch == ']'){
                string temp = "";
                // collect the string until we find open bracket
                while(!st.empty() && st.top() != "["){
                    temp = st.top() + temp; // prepend to maintain order
                    st.pop();
                }
                
                // remove the open bracket
                st.pop();
                
                // take the number before '['
                string numStr = "";
                while(!st.empty() && isdigit(st.top()[0])){
                    numStr = st.top() + numStr;
                    st.pop();
                }
                int digit = stoi(numStr);
                
                // repeat the string
                string newStr = "";
                for(int cnt=0; cnt<digit; ++cnt)
                    newStr += temp;
                
                st.push(newStr);
            }
            else {
                st.push(string(1, ch));
            }
        }
        
        // build the final answer
        string result = "";
        while(!st.empty()){
            result = st.top() + result;
            st.pop();
        }
        return result;
    }
};
