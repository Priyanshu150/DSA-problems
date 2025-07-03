#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(k)
// Space complexity :- O(k)

// Approach :-  
// take a origianl string, traverse on it until size of it is less than k 
// for every char in original string move it to the next char and for a temp string
// append temp string in original string 
// at last return the kth char from the original string 

// links :- https://leetcode.com/problems/find-the-k-th-character-in-string-game-i/

class Solution {
private:
    char nextChar(char ch){
        int currCharVal = ch - 'a';
        int nextCharVal = (currCharVal + 1) % 26;
        return ('a' + nextCharVal);
    }

public:
    char kthCharacter(int k) {
        string original = "a";

        while(original.size() < k){
            string temp = "";
            for(auto ch: original){
                temp += nextChar(ch);
            }
            original += temp;
        }
        return original[k-1];
    }
};
