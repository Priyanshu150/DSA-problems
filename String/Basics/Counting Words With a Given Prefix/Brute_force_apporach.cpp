#include<bits/stdc++.h>
using namespace std;

//Time complexity :- O(N*M), where n is the length of words and m is length of pref
//Space complexity :- O(1)    

//Links :- https://leetcode.com/problems/counting-words-with-a-given-prefix/description/

class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int m = pref.size(), res = 0;

        for(auto word: words){
            int n = word.size();
            if(n < m)   continue;

            string prefix = word.substr(0, m);
            if(pref == prefix)
                res++;
        }
        return res;
    }
};