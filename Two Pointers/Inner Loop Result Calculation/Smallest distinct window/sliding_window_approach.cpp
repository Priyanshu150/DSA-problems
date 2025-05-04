#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(n)
// Space complexity :- O(26)

// Approach :-
// count the unique number of char in the string 
// using sliding window approach, for every window calculate the number of unique char
// while moving right poniter move add the char in freq arr 
// while removing char from left pointer remove the char in freq arr 
// and calculate the ans during that phase because that will be our valid window


// Link :- https://www.geeksforgeeks.org/problems/smallest-distant-window3132/1

class Solution {
  public:
    int findSubString(string& str) {
        // code here
        int n = str.size(), unique = 0, freq[26] = {0};
        
        for(int i=0; i<n; ++i){
            freq[str[i]-'a'] += 1;
            if(freq[str[i]-'a'] == 1)
                unique++;
        }
        
        for(int i=0; i<26; ++i)
            freq[i] = 0;
        
        int left = 0, unique_in_window = 0, res = n;
        
        for(int right=0; right<n; ++right){
            freq[str[right] - 'a'] += 1;
            if(freq[str[right] - 'a'] == 1)
                unique_in_window += 1;
            
            while(unique_in_window >= unique){
                res = min(res, right - left + 1);
                
                freq[str[left] - 'a'] -= 1;
                if(freq[str[left] - 'a'] == 0)
                    unique_in_window -= 1;
                    
                ++left;
            }
        }
        return res;
    }
};