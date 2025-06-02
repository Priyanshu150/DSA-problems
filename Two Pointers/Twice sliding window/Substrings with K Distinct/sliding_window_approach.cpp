#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(n)
// Space complexity :- O(26)

// Approach :- 
// If we find the all the substring which has distinct char less than k & k-1
// the the difference b/w those will give us substring which has distinct element exactly equals to k
// for sovle less than k we'll use sliding window
// mainatain a left an right pointer, freq array to track freq of each char in a window
// move the right ptr and if a char is apprear first time it will give us a ditinct char
// if distinct count becomes greater than k move left ptr and remove char untill it becomes less than k
// for any valid window the total number of substring will be (right - left + 1) 
// accumulate the valid window as our answer

// Link :- https://www.geeksforgeeks.org/problems/count-number-of-substrings4528/1

class Solution {
  private:
    int atLeastK(string &s, int k){
        int freq[26] = {0};
        int left = 0, distinct = 0, n = s.size(), res = 0;
        
        for(int right=0; right<n; right++){
            freq[s[right] - 'a'] += 1;
            
            if(freq[s[right] - 'a'] == 1)
                distinct++;
            
            while(distinct > k){
                freq[s[left] - 'a'] -= 1;
                
                if(freq[s[left] - 'a'] == 0)
                    distinct--;
                
                ++left;
            }
            res += (right - left + 1);
        }
        return res;
    }
  
  public:
    int countSubstr(string& s, int k) {
        // code here.
        return atLeastK(s, k) - atLeastK(s, k-1);
    }
};