#include<bits/stdc++.h>
using namespace std;

// Time complextiy :- O(N*N*log(N))
// Space complexity :- O(N)

// Approach :-   
// generate all the substring using two for loop 
// and save all those in set 
// answer will be the size of array 

//Link :- https://www.geeksforgeeks.org/problems/count-of-distinct-substrings/1

class Solution {
  public:
    int countSubs(string& s) {
        int n = s.size();
        unordered_set<string> st;
        
        for(int i=0; i<n; ++i){
            string str = "";
            for(int j=i; j<n; ++j){
                str += s[j];
                st.insert(str);
            }
        }
        return st.size();
    }
};