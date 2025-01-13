#include<bits/stdc++.h>
using namespace std;

//Time complexity :- O(N + N)
//Space complexity :- O(2*N)

//Approach :-
//Take 2 stack one for open bracket and other for unlocked bracket
//Consider unlocked bracket as wild card and push the ind of that into the stack 
// for every "(" push their ind to stack
// for ever ')' check wheather any stack of openBracket has any bracket
// If not check the unlocked bracket stack consider it as a '('
// Otherwise it will not be possible 
// After that check both stack consider unlocked bracket as ')' 
// openBracket ind should be less than unlocked bracket because we're considering it as ')'
// At last check wheather the stack of opneBracket is empty or not & size of unlocked bracket should be even
// (size of unlocked bracket should be even) this condition should will always be even if the string is blanced so we can ommit this condition in last return statement


//link :- https://leetcode.com/problems/check-if-a-parentheses-string-can-be-valid/

class Solution {
public:
    bool canBeValid(string s, string locked) {
        int n = s.size();
        if(n%2)     return false;
        
        stack<int> openBracket, unlockedBracket;

        for(int i=0; i<n; ++i){
            if(locked[i] == '0')
                unlockedBracket.push(i);
            else if(s[i] == '(')
                openBracket.push(i);
            else{
                if(!openBracket.empty())
                    openBracket.pop();
                else if(!unlockedBracket.empty())
                    unlockedBracket.pop();
                else 
                    return false;
            }
        }
        while(!unlockedBracket.empty() && !openBracket.empty() 
                && openBracket.top() < unlockedBracket.top()){
                    unlockedBracket.pop();
                    openBracket.pop();
                }
        // return openBracket.empty() && (unlockedBracket.size()%2==0);
        return openBracket.empty();
    }
};