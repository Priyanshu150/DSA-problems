#include<bits/stdc++.h>
using namespace std;

//Time complexity :- O(n*n*log(n))     // Where n is length of string s
//Space complexity :- O(n+n)          // for freq array and set 

//Approach :-
// count the freq of each char in string 
// Again traverse on the string and put each char in the set and decrease the freq of char 
// reapet this until the char present in the set has 0 freq (inner loop)
// once inner loop is completed push the length into answer vector 

// Links :- https://leetcode.com/problems/partition-labels/


class Solution {
private:
    bool check(unordered_set<char> chars, vector<int> &freq){
        for(auto ch: chars){
            if(freq[ch - 'a'] > 0)
                return true;
        }
        return false;
    }

public:
    vector<int> partitionLabels(string s) {
        int n = s.size();
        vector<int> ans, freq(26, 0);

        for(int i=0; i<n; ++i)
            freq[s[i]-'a'] += 1;
        
        int i = 0, prev = i;
        unordered_set<char> chars;

        while(i < n){
            chars.insert(s[i]);
            freq[s[i] - 'a'] -= 1;
            i++;

            while(i<n && check(chars, freq)){
                chars.insert(s[i]);
                freq[s[i] - 'a'] -= 1;
                i++;
            }
            ans.push_back(i - prev);
            prev = i;
            chars.clear();
        }
        return ans;
    }
};