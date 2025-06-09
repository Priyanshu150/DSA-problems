#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(n^3)
// Space complexity :- O(n - stack_space)

// Approach :-  
// Start by fixing the length of previous 2 substring using 2 loop 
// and call recursion to check wheather it's possible to form a string using these 2 lengths or not 
// In recursion, form the 2 substring and sum them
// if the length of these 3 string is greater than original string then it's not possible
// otherwise check if the sum_string is equal to the next string that has to be formed 
// If it's then explore the next possiblities, 
// if it's the last string after that no string can be formed then return true 
// After try all possibilities it's not possible then return false


// Link :- https://www.geeksforgeeks.org/problems/sum-string3151/1

class Solution {
  private:
    // Add the two string 
    string addString(string num1, string num2) {}
    
    bool checkSequence(string s, int start, int len1, int len2){
        // form the first and second string 
        string part1 = s.substr(start, len1);
        string part2 = s.substr(start + len1, len2);
        // Add both the string 
        string expectedSum = addString(part1, part2);
        
        int sumLen = expectedSum.length();
        // If the length 2 string and sum string is greater than original string
        if(start + len1 + len2 + sumLen > s.length())
            return false;
        
        // Sum string is equal to next strnig
        if(expectedSum == s.substr(start + len1 + len2, sumLen)){
            // if the string is not present after next string that mean we're at end 
            // and this string follows the property
            if(start + len1 + len2 + sumLen == s.length()){
                return true;   
            }
            // check for next sequence
            return checkSequence(s, start + len1, len2, sumLen);
        }
        return false;
    }
  
  public:
    bool isSumString(string &s) {
        // code here
        int n = s.size();
        
        // Fix the length of previous 2 substring 
        //call recursion to check for valid string configuration with fixed length
        for(int len1 = 1; len1 < n; ++len1){
            for(int len2 = 1; len1 + len2 < n; ++len2){
                if(checkSequence(s, 0, len1, len2)){
                    return true;
                }
            }
        }
        return false;
    }
};
