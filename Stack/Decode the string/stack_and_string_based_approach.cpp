#include<bits/stdc++.h>
using namespace std;

//Time complexity :- O(N)
//Space complexity :- O(N)    

//Approach :-
// We can use stack to calculate our ans and push string into it
// traverse the string from left to right, if we got a digit the accumulate all the digt and push it into the stack as string
// if we got '[' the push "[" on the stack
// if we got a letter repeat the same project as we did for digit
// if we get ']' then accumulate the string until we found the '['
// reverse the string as it will be reversed order because of stack operation
// take one more string from the stack which will be digit
// repeat the string digit number of times and push it onto the stack
// At last accumulate the strings from the stack and reverse the string to get the ans


//link :- https://www.geeksforgeeks.org/problems/decode-the-string2444/1

class Solution {
  public:
    string decodedString(string &s) {
        // code here
        stack<string> st;
        int ind = 0, n = s.size();
        string res = "";
        
        while(ind < n){
            if(isdigit(s[ind])){
                string temp = "";
                while(ind<n && isdigit(s[ind])){
                    temp += s[ind];
                    ++ind;
                }
                st.push(temp);
            }
            else if(s[ind] == ']'){
                string temp = "", repeated = "";
                
                while(!st.empty() && st.top()!="["){
                    temp = st.top() + temp;
                    st.pop();
                }
                if(!st.empty())
                    st.pop();
                    
                int times = !st.empty() && isdigit(st.top()[0]) ? stoi(st.top()) : 1;
                st.pop();
                
                while(times-- > 0)
                    repeated += temp;
                
                st.push(repeated);
                ++ind;
            }
            else if(s[ind] == '['){
                st.push("[");
                ++ind;
            }
            else{
                string temp = "";
                while(ind<n && isalpha(s[ind]) ){
                    temp +=s[ind];
                    ind++;
                }
                st.push(temp);
            }
        }
        while(!st.empty()){
            res = st.top() + res;
            st.pop();
        }
        return res;
    }
};