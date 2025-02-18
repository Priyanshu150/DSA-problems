#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(n)
// Space complexity :- O(n)

// Approach :-  
// digit is in the range 1 to 9
// increasing sequence will be (1 2 3 4) which will be lexicographically smallest 
// similary for decresing reverse the seq and add it to out ans to get exicographically smallest one (4 3 2 1)
// Traverse from 1 to n+1 put number in stack (which will help in reverse fragment operation)
// If we got 'I' then add it into ans
// else just put all the decresing seq in ans and when we got next 'I' or n+1 reverse the seq and add it

// Link :- https://leetcode.com/problems/construct-smallest-number-from-di-string/

class Solution {
    public:
    string smallestNumber(string pattern) {
        stack<int> st;
        string res = "";
        int n = pattern.size();

        for(int i=1; i<=n+1; ++i){
            st.push(i);
            char curr = (i<=n) ? pattern[i-1] : '#';

            if(i == n+1 || curr == 'I'){
                while(!st.empty()){
                    res += (st.top() + '0');
                    st.pop();
                }
            }
        }
        return res;
    }
};