#include<bits/stdc++.h>
using namespace std;

//Time complexity :- O(N)       
//Space complexity :- O(1)    

//Approach :-
//Use sliding window to check which window for valid window
//calculate the freq of each character 

class Solution {
  public:
    int longestUniqueSubstr(string &s) {
        // code here
        int n = s.size(), res = 1, j(0);
        int freq[26] = {0};
        
        for(int i=0; i<n; ++i){
            freq[s[i] - 'a'] += 1;
            
            while(j<i && freq[s[i] - 'a'] > 1){
                freq[s[j] - 'a'] -= 1;
                j++;
            }
            res = max(res, i-j+1);
        }
        return res;
    }
};