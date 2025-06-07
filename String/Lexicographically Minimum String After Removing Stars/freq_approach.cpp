#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(n*26)
// Space complexity :- O(n)

// Approach :- 
// traverse the array and maintain the index of each char in freq_array
// where freq_char denotes for a char what are differenet indexes where this char is present 
// if a '*' char is present find the smallest char and record the last index present in that array 
// mark that index in the string as '*'
// traverse in the string and for the result skipping those which are '*'

// Link :- https://leetcode.com/problems/lexicographically-minimum-string-after-removing-stars/

class Solution {
public:
    string clearStars(string s) {
        int n = s.size();
        string res = "";
        vector<vector<int>> char_pos(26);

        for(int i=0; i<n; ++i){
            if(s[i] == '*'){
                for(int j=0; j<26; ++j){
                    if(char_pos[j].size() > 0){
                        s[char_pos[j].back()] = '*';
                        char_pos[j].pop_back();
                        break;
                    }
                }
            }   
            else{
                char_pos[s[i] - 'a'].push_back(i);
            }
        }

        for(auto ch: s){
            if(ch != '*')
                res += ch;
        }
        return res;
    }
};