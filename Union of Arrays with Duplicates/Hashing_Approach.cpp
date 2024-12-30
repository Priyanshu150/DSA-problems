#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    // Function to return the count of number of elements in union of two arrays.
    int findUnion(vector<int>& a, vector<int>& b) {
        // code here
        int n = a.size(), m = b.size();
        if(n > m)   findUnion(b, a);
        
        unordered_set<int> st;
        int res = 0;
        
        for(int i=0; i<n; ++i){
            if(!st.count(a[i])){
                st.insert(a[i]);
                res++;
            }
        }
        for(int i=0; i<m; ++i){
            if(!st.count(b[i])){
                st.insert(b[i]);
                res++;
            }
        }
        return res;
    }
};