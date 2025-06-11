#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(N)
// Space complexity :- O(N)

// Approach :-  
// use a stack to keep track of previous elements 
// until previous element is equal to curr element remove element from the stack
// if the current element have not removed any element then only push that element into stack


// Link :- https://www.geeksforgeeks.org/problems/remove-the-balls--170647/1

class Solution {
  #define pii pair<int,int>
  
  public:
    int findLength(vector<int> &color, vector<int> &radius) {
        // code here
        int n = color.size();
        stack<pii> st;
        
        for(int i=0; i<n; ++i){
            bool flag = true;
            
            while(!st.empty() && st.top().first == color[i] && st.top().second == radius[i]){
                st.pop();
                flag = false;
            }
            if(flag)        st.push({color[i], radius[i]});
        }
        return st.size();
    }
};