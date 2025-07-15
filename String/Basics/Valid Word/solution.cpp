#include<bits/stdc++.h>
using namespace std;

//Time complexity :- O(n)   
//Space complexity :- O(1)

// Approach :-
// traverse on each char and check for the wheather it satisfy all the condition for being a word or not 
// check wheater it's digit or letter or not, if it's letter then either it'll be vowel or consonant
// maintain to variable to track wheather a vowel or consonant is observed or not 
// at last check wheather we've vowel or consonant found or not depending on that return true or false


//Link :- https://leetcode.com/problems/string-matching-in-an-array/description/

class Solution {
private:
    int isValidChar(char ch){
        if(ch >= 48 && ch <= 57)        return 2;
        if(ch >= 65 && ch <= 90)        return 1;
        if(ch >= 97 && ch <= 122)       return 1;
        return 0;
    }

    bool isVowel(char ch){
        return (ch == 'a' || ch == 'A' || ch == 'e' || ch == 'E' || ch == 'i' || ch == 'I' || ch == 'o' || ch == 'O' || ch == 'u' || ch == 'U');
    }

public:
    bool isValid(string word) {
        if(word.size() < 3)     return false;
        bool vowel = false, consonant = false;

        for(auto ch: word){
            int val = isValidChar(ch);
            if(val){
                if(val == 1){
                    if(isVowel(ch))
                        vowel = true;
                    else 
                        consonant = true;
                }
            }
            else    return false;
        }
        return vowel && consonant;
    }
};