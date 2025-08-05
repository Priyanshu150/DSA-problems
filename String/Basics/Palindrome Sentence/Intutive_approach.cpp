#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(n)  
// Space complexity :- O(1)

// Approach :-
// From original string create a temporary string which satisfy the requirement 
// and then check wheather that one is valid palindrome or not 


// Link :- https://www.geeksforgeeks.org/problems/string-palindromic-ignoring-spaces4723/1

class Solution {
  public:
    bool isPalinSent(string &s) {
        // code here
        string temp = "";
        
        for(auto ch: s){
            // checks for alphabet or not 
            if(isalpha(ch)){
                temp += tolower(ch);
            }
            else if(isdigit(ch)){
                temp += ch;
            }
        }
        int i=0, j=temp.size()-1;
        
        // Two pointer to detect palindorme stirng 
        while(i < j){
            if(temp[i] != temp[j])
                return false;
            
            i++;
            j--;
        }
        return true;
    }
};