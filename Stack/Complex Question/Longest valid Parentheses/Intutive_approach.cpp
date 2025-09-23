#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(n + n)
// Space complexity :- O(n)

// Approach :-
// remove all the valid parentheses from the string using stack
// After that only those index will be present in the stack that is not part of valid parentheses
// Calculate the distance b/w invalid parentheses and store the maximum
// store -1 and n respectively for tackling corner case if only first or last bracket remains invalid


// Link :- https://www.geeksforgeeks.org/problems/longest-valid-parentheses5657/1

class Solution {
    private:
    void removeValidParentheses(string &s, stack<int> &st, int &n){
        st.push(-1);
        for(int i=0; i<n; ++i){
            if(s[i] == ')' && st.top()!=-1 && s[st.top()] == '(')
                st.pop();
            else
                st.push(i);
        }
    }
  
  public:
    int maxLength(string& s) {
        // code here
        int n = s.size();
        stack<int> st;
        
        removeValidParentheses(s, st, n);
        if(st.size() == 1)      return n;
        
        int res = 0, index = n;
        while(!st.empty()){
            int ele = st.top();
            st.pop();
            
            res = max(res, index - ele - 1);
            index = ele;
        }
        return res;
    }
};