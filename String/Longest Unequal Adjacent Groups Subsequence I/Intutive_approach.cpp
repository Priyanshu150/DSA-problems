#include<bits/stdc++.h>
using namespace std;

//Time complexity :- O(n)   
//Space complexity :- O(1)

// Approach :- 
// starting with a any sequence value(-1), traverse the array from left to right
// once you find a differenct bit value consider the string in answer and change the bit 

//Link :- https://leetcode.com/problems/longest-unequal-adjacent-groups-subsequence-i/

class Solution {
public:
    vector<string> getLongestSubsequence(vector<string>& words, vector<int>& groups) {
        vector<string> res;
        int prev = -1, n = groups.size();
        
        for(int i=0; i<n; ++i){
            if(prev != groups[i]){
                res.push_back(words[i]);
                prev = groups[i];
            }
        }
        return res;
    }
};

class Solution {
private:
    void createSequence(int n, int seq, vector<string>& words, vector<int>& groups, vector<string> &ans){

        for(int i=0; i<n; ++i){
            if(seq == groups[i]){
                seq = !seq;
                ans.push_back(words[i]);
            }
        }
    }

public:
    vector<string> getLongestSubsequence(vector<string>& words, vector<int>& groups) {
        vector<string> ans1, ans2;
        int n = words.size(), seq = 0;
        createSequence(n, 0, words, groups, ans1);
        createSequence(n, 1, words, groups, ans2);
        return (ans1.size() > ans2.size()) ? ans1 : ans2;
    }
};

