#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(n*26*log(n))
// Space complexity :- O(26+n)

// Approach :-   
// for every character count the freq of each char on left and right side 
// using that freq array, make all the sub-sequence of length 3 
// and store them in hash set, the size of set will be our answer 

// Link :- https://leetcode.com/problems/unique-length-3-palindromic-subsequences/

class Solution {
private:
    unordered_set<string> st;

    void ways(char c, vector<int> &freq, vector<int> &freq1){
        for(int i=0; i<26; ++i){
            if(freq[i]>0 && freq1[i]>0){
                char ch = ('a'+i);
                string str = string(1, ch) + c + ch;
                st.insert(str);
            }
        }
    }

public:
    int countPalindromicSubsequence(string s) {
        int n = s.size();
        vector<int> freq(26, 0), freq1(26, 0);

        for(int i=0; i<n; ++i){
            freq[s[i] - 'a'] += 1;
        }
        int res = 0;

        for(int i=0; i<n; ++i){
            freq[s[i] - 'a'] -= 1;
            ways(s[i], freq, freq1);
            freq1[s[i] - 'a'] += 1;
        }
        return st.size();
    }
};