#include<bits/stdc++.h>
using namespace std;

//Time complexity :- O(N)       
//Space complexity :- O(26 + N)    

//Approach :-
//find the unique char b/w first and last occurence of every char in string

class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int n = s.size(), res = 0;
        vector<int> firstOcc(26, -1), lastOcc(26, -1);

        for(int i=0; i<n; ++i){
            if(firstOcc[s[i]-'a'] == -1)
                firstOcc[s[i]-'a'] = i;
            
            lastOcc[s[i]-'a'] = i;
        }
        for(int i=0; i<26; ++i){
            if(firstOcc[i] == -1 || firstOcc[i] == lastOcc[i])      continue;

            unordered_set<int> st;
            for(int j=firstOcc[i]+1; j<lastOcc[i]; ++j)
                st.insert(s[j]);
            
            res += st.size();
        }
        return res;
    }
};