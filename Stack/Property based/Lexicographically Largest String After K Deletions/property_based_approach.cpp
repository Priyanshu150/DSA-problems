#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(n + n)
// Space complexity :- O(n)

// Approach :-
// use stack to keep tack of all the char in the string 
// if we get the char which is smaller than that present on the top
// do this until the k expires or otherwise stack is empty

// Link :- https://www.geeksforgeeks.org/problems/lexicographically-largest-string-after-deleting-k-characters/1

class Solution {
  public:
    string maxSubseq(string& s, int k) {
        // code here
        stack<int> st;
        
        for(auto ch: s){
            int num = ch - 'a';
            while(!st.empty() && k>0 && num>st.top()){
                st.pop();
                k--;
            }
            st.push(num);
        }
        while(k-->0){
            st.pop();
        }
        string res = "";
        while(!st.empty()){
            res += (st.top() + 'a');
            st.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
