#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(n)
// Space complexity :- O(n)

// Approach :- 
// push every people into stack and keep check if top two persons knowns each other or not 
// utill there is only 1 person left in the stack 
// At last check that person can be a celebrity or not 


//Link :- https://www.geeksforgeeks.org/problems/the-celebrity-problem/1

class Solution {
  public:
    int celebrity(vector<vector<int>>& mat) {
        // code here
        stack<int> st;
        int n = mat.size(), sz = n;
        
        for(int i=0; i<n; ++i)
            st.push(i);
        
        while(sz > 1){
            int a = st.top();
            st.pop();
            int b = st.top();
            st.pop();
            sz -= 2;
            
            if(mat[a][b]){
                st.push(b);
                sz += 1;
            }
            else if(mat[b][a]){
                st.push(a);
                sz += 1;
            }
        }
        if(sz == 0)
            return -1;
        
        int ans = st.top();
        st.top();
        
        for(int row=0; row<n; ++row){
            if(mat[row][ans] != 1)
                return -1;
        }
        for(int col=0; col<n; ++col){
            if(col != ans && mat[ans][col] != 0)
                return -1;
        }
        return ans;
    }
};