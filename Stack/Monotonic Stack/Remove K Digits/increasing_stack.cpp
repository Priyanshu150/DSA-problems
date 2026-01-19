#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(n)
// Space complexity :- O(n)

// Approach :-  
// using stack maintain a monotonice increasing stack 
// pop the element to make it monotonic until k is valid 
// eliminate all the leading zero and return '0' if nothing exists 


//Link :- https://www.geeksforgeeks.org/problems/remove-k-digits/1

class Solution {
  public:
    string removeKdig(string &s, int k) {
        stack<char> st;
        
        // traverse from left to right on digits 
        for(auto ch: s){
            // maintain a monotonic stack of increasing 
            // until k expires
            while(!st.empty() && k>0 && (st.top()-'0') > (ch - '0')){
                st.pop();
                k--;
            }
            // add current element to the stack
            st.push(ch);
        }
        // remove exactly k element from the stack if not already removed 
        while(k--){
            st.pop();
        }
        string res = "";
        
        // build result from the number left in stack
        while(!st.empty()){
            res += st.top();
            st.pop();
        }
        // reverse the string to get the actual answer 
        reverse(res.begin(), res.end());
        
        // delete all the leading zeros
        while(res.size()>0 && res[0] == '0')
            res = res.substr(1);
        
        return res.size() == 0 ? "0" : res;
    }
};