#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(2*N)
// Space complexity :- O(N)

// Approach :- 
// Greedily choose the index which max b/w x & y and try to pick first string 'ab' or 'ba' accordingly
// with the help of stack, traverse the string and eliminate the choosen string and accumulate the points
// repeat it twice first for the string which has maximum value associated with it 
// and after that the other string 

// Link :- https://leetcode.com/problems/maximum-score-from-removing-substrings/

class Solution {
private:
    int pointsForString(string &s, string target, int points){
        int total = 0;
        stack<char> st;

        for(char ch: s){
            if(!st.empty() && st.top() == target[0] && ch == target[1]){
                total += points;
                st.pop();
            }
            else    st.push(ch);
        }
        s = "";
        while(!st.empty()){
            s += st.top();
            st.pop();
        }
        reverse(s.begin(), s.end());
        return total;
    }

public:
    int maximumGain(string s, int x, int y) {
        string s1 = "ab", s2 = "ba";
        if(y > x)   swap(s1, s2), swap(x, y);
        return pointsForString(s, s1, x) + pointsForString(s, s2, y);
    }
};