#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(n)
// Space complexity :- O(26)

// Approach :-  
// use sliding window to generate all the valid windows
// use freq array to track the count of each char 
// traverse in the string from 0 to n-1 taking distinct count of char 
// if distinc count increase by k, decrease the length of window
// by removing contribution of char in sub-array from the left pointer(initially 0)
// whenver distinct char in the string equal k, take that subarry into consideration 
// and maintain a max length sub-array in the ans 


// links :- https://www.geeksforgeeks.org/problems/longest-k-unique-characters-substring0853/1

class Solution {
  public:
    int longestKSubstr(string &s, int k) {
        // code here
        vector<int> freq(26, 0);
        int left = 0, n = s.size(), distinct = 0, res = -1;
        
        for(int right=0; right<n; ++right){
            freq[s[right] - 'a'] += 1;
            if(freq[s[right] - 'a'] == 1)
                ++distinct;
            
            while(distinct > k){
                freq[s[left] - 'a'] -= 1;
                if(freq[s[left] - 'a'] == 0)
                    --distinct;
                
                ++left;
            }
            if(distinct == k)
                res = max(res, right - left + 1);
        }
        return res;
    }
};