#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(n*26*log(n))
// Space complexity :- O(26+n)

// Approach :-   
// for every char in the string, store the last and first occurence of it 
// traverse on the freq array, and traverse on the first and last occurence of each char 
// store the unique char into the set, and for particular char that will be unique subsequence 


// Link :- https://leetcode.com/problems/unique-length-3-palindromic-subsequences/

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