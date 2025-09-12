#include<bits/stdc++.h>
using namespace std;

// Time Complexity: O(n)
// Space Complexity: O(1)

// Approach :- 
// whenever a vowel is present in string then only alice will win otherwise bob will

// Link :- https://leetcode.com/problems/vowels-game-in-a-string/

class Solution {
public:
    bool doesAliceWin(string s) {
        for(auto ch: s){
            if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
                return true;
        }
        return false;
    }
};