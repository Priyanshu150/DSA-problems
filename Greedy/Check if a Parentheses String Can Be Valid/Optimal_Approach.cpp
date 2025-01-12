#include<bits/stdc++.h>
using namespace std;

//Time complexity :- O(N + N)
//Space complexity :- O(1)    

//Approach :-
// If the size of string is odd then it's not possible
// Consider unlocked bracket as a wild character where anything can be fitted
// At any point traversing from left to right the count of openBraket + wildChar >= closeBraket
// Vice versa is true from right to left where count of closeBraket + wildChar >= openBraket

//link :- https://leetcode.com/problems/check-if-a-parentheses-string-can-be-valid/description/

class Solution {
public:
    bool canBeValid(string s, string locked) {
        int n = s.size(), openBracket = 0, closeBracket = 0, wildcard = 0;
        if(n%2 == 1)        return false;

        for(int i=0; i<n; ++i){
            if(locked[i] == '0')    wildcard++;
            else if(s[i] == '(')    openBracket++;
            else       closeBracket++;

            if(openBracket - closeBracket <  wildcard)
                return false;
        }
        openBracket = closeBracket = wildcard = 0;

        for(int i=n-1; i>=0; --i){
            if(locked[i] == '0')    wildcard++;
            else if(s[i] == '(')    openBracket++;
            else       closeBracket++;

            if(closeBracket - openBracket < wildcard)
                return false;
        }
        return true;
    }
};