#include<bits/stdc++.h>
using namespace std;

// Time complextiy :- O(n)
// Space complexity :- O(1)

// Approach :-
// Instead of using stack we can use string to handling the operation which reduces our extra space 


// Links :- 
// https://leetcode.com/problems/remove-duplicate-letters/description/
// https://leetcode.com/problems/smallest-subsequence-of-distinct-characters/description/

class Solution {
public:
    string removeDuplicateLetters(string s) {
        int n = s.size();
        vector<int> lastInd(26, -1);
        vector<bool> freq(26, false);
        string res = "";

        for(int i=0; i<n; ++i)
            lastInd[s[i]-'a'] = i;
        
        for(int i=0; i<n; ++i){
            if(freq[s[i]-'a'])      continue;

            while(!res.empty() && res.back() > s[i]  && lastInd[res.back()-'a'] > i){
                freq[res.back()-'a'] = false;
                res.pop_back();
            }
            freq[s[i]-'a'] = true;
             res.push_back(s[i]);
        }
        return res;
    }
};