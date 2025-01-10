#include<bits/stdc++.h>
using namespace std;

//Time complexity :- O(M*words1.size + N*word2_size)       
//Space complexity :- O(26)    

//Approach :-
//Hash all the char value from word2 and take the max frequency of char which observed from each string
// Compare it with freq of each word in word1 and evalute the word is universal or not 

//link :- https://leetcode.com/problems/word-subsets/description/

class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<string> ans;
        int freq2[26] = {0};

        for(auto word: words2){
            int freq[26] = {0};
            for(auto ch: word)
                freq[ch - 'a'] += 1;
            
            for(int i=0; i<26; ++i)
                freq2[i] = max(freq2[i], freq[i]);
        }
        for(auto word: words1){
            int freq1[26] = {0};
            for(auto ch: word)
                freq1[ch - 'a'] += 1;
            
            bool flag = true;
            for(int i=0; i<26; ++i){
                if(freq2[i] > 0 && freq2[i] > freq1[i]){
                    flag = false;
                    break;
                }
            }
            if(flag)        ans.push_back(word);
        }
        return ans;
    }
};