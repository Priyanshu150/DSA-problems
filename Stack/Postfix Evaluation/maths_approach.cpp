#include<bits/stdc++.h>
using namespace std;

// Time Complexity: O(n)
// Space Complexity: O(n)

// Approach :- 
// if the number are coming push that into the stack 
// otherwise perform the operation on the top 2 numbers present in the stack  


// Link :- https://www.geeksforgeeks.org/problems/evaluation-of-postfix-expression1735/1

class Solution {
  public:
    int evaluatePostfix(vector<string>& arr) {
        // code here
        stack<int> st;
        
        for(auto str: arr){
            if(str == "+" || str == "-" || str == "*" || str == "/" || str == "^"){
                int first = st.top(), second;
                st.pop();
                second = st.top();
                st.pop();
                
                if(str == "+")
                    st.push(first + second);
                else if(str == "-")
                    st.push(second - first);
                else if(str == "*")
                    st.push(first*second);
                else if(str == "^")
                    st.push(pow(second, first));
                else 
                    st.push(floor((double)second / first));
            }
            else    st.push(stoi(str));
        }
        return st.top();
    }
};