#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(n)
// Space complexity :- O(n)

// Approach :-
// This approach is a optimization based on previous one 
// The idea is to calulate the distance b/w unvalid parenetheses while checking for valid parentheses
// If a "(" comes in, do a blind insertion
// otherwise pop the element 
//and if stack becomes empty then push current index else dist will be curr_index - st.top()_index


// Link :- https://www.geeksforgeeks.org/problems/longest-valid-parentheses5657/1

class Solution {
    public:
    int maxLength(string& s) {
        // code here
        int n = s.size(), res = 0;
        stack<int> st;
        st.push(-1);
        
        for(int i=0; i<n; ++i){
            if(s[i] == '(')
                st.push(i);
            else{
                st.pop();
                if(st.empty())
                    st.push(i);
                else
                    res = max(res, i - st.top()); 
            }
        }
        return res;
    }
};