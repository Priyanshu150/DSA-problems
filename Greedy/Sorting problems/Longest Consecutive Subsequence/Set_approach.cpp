#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:

    // Function to return length of longest subsequence of consecutive integers.
    int longestConsecutive(vector<int>& arr) {
        // Your code here
        set<int> st;
        
        for(auto num: arr)
            st.insert(num);
        
        int prev = -2, lcs = 0, res = 1;
        
        for(auto num: st){
            if(prev+1 == num)  
                lcs++;
            else 
                lcs = 1;
            
            prev = num;
            res = max(lcs, res);
        }
        return res;
    }
};