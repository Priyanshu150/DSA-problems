#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(N)
// Space complexity :- O(N)

// Approach :-
// use stack to calulate the result and start traversing the arr left to right
// Whenever we get number push that into the stack by converting it to integer
// if we get any operator pop last two element from stack apply the operation on them 
// and push result of those into the stack

// Link :- https://www.geeksforgeeks.org/problems/evaluation-of-postfix-expression1735/1

class Solution {
  public:
    int evaluate(vector<string>& arr) {
        // code here
        stack<int> st;
        
        for(auto str: arr){
            if(str == "+" || str == "-" || str == "*" || str == "/"){
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
                else 
                    st.push(second / first);
            }
            else    st.push(stoi(str));
        }
        return st.top();
    }
};