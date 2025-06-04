#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(n^2)
// Space complexity :- O(26)

// Approach :- 
// for finding the the lexigraphically largest string we need to make char at any position and length as largest as possible
// for length we'll alloate 1 char to each friend expcept last one which we'll give the all remaining char
// for char check which the largest char occuring in the string
// try to form a string of largest length from that char and find the answer respectively

// Link :- https://leetcode.com/problems/find-the-lexicographically-largest-string-from-the-box-i/

class Solution {
public:
    string answerString(string word, int numFriends) {
        if(numFriends == 1)
            return word;
        
        int n = word.size(), m = n - numFriends + 1;
        string res = "";

        for(int i=0; i<n; ++i){
            res = max(res, word.substr(i, m));
        }
        return res;
    }
};

class Solution {
private:
    bool lexicographicallyLargest(string s1, string s2){
        int n1 = s1.size(), n2 = s2.size();
        if(n1 < n2)         return true;

        for(int i=0; i<n2; ++i){
            if(s1[i] < s2[i]){
                return true;
            }
            else if(s1[i] > s2[i])
                break;
        }
        return false;
    }

public:
    string answerString(string word, int numFriends) {
        if(numFriends == 1)     return word;

        int n = word.size(), len = (n - numFriends + 1);
        int last_char = 1, freq[26] = {0};
        string res = "";

        for(int i=0; i<n; ++i){
            freq[word[i] - 'a'] = 1;
        }

        for(int i=0; i<26; ++i){
            if(freq[i] == 1)
                last_char = i;
        }

        for(int i=0; i<n; ++i){
            if((word[i] - 'a') == last_char){
                string temp = word.substr(i, min(len, n-i));
                if(lexicographicallyLargest(res, temp))
                    res = temp;
            }
        }
        return res;
    }
};