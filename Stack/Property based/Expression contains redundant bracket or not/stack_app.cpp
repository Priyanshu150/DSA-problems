#include<bits/stdc++.h>
using namespace std;

//Time complextiy :-  O(n)
// Space complexity :- O(n)

// Approach :- 
// brackets are valid only when there are at least 2 char and 1 operator b/w them 
// store every char apart from ')' into the stack 
// for that pop the stack until we found '('
// and count all the char and operator b/w them
// if it satisfies the 1st condition logic return false 


// Link :- https://www.geeksforgeeks.org/problems/expression-contains-redundant-bracket-or-not/1

class Solution {
  public:
    bool checkRedundancy(string &s) {
        stack<char> st;
        
        // traverse on each char 
        for(char ch: s){
            if(ch == ')'){
                int alp = 0, opr = 0;
                
                // count the number of alphabet and operator until we find '('
                while(!st.empty() && st.top() != '('){
                    if(st.top() == '+' || st.top() == '-' || st.top() == '*' || st.top() == '/'){
                        opr++;
                    }else{
                        alp++;
                    }
                    
                    st.pop();
                }
                // for braket to be valid it should have at least 2 alphabet and 1 operator 
                if(alp < 2 || opr == 0)
                    return true;
                    
                st.pop();       // remove the open bracket 
                st.push('a');
            }
            // every char apart from ')' push into the stack 
            else    st.push(ch);
        }
        return false; 
    }
};
