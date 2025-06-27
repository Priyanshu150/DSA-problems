#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(n)  
// Space complexity :- O(1)

// Approach :-  
// since k is 10^9, it will not exceed 32 bits 
// keep all the 0 because it'll not affect the number & try removing 1 
// remove 1 from left side i.e. MSB which will have more contribution 
// and cnt the number of 1s removed and subtract it from the len it'll be our result
// while removing traverse till min(31, n) since set bit more than that has to be removed 


// Link :- https://leetcode.com/problems/longest-binary-subsequence-less-than-or-equal-to-k/

class Solution {
public:
    int longestSubsequence(string s, int k) {
        int n = s.size(), i = 0;
        long long val = 0;

        //Step 1 :- Keep all set bits until the value exceeds k
        while(i < min(n, 32)){
            if(s[n-1-i] == '1'){
                long long power = pow(2, i);
                if(val + power > k)
                    break;
                
                val += power;
            }
            ++i;
        }
        //Step 2 :- Count the removed bits
        int removed_count = 0;
        while(i < n){
            if(s[n-i-1] == '1')
                removed_count++;
            
            i++;
        }
        return n - removed_count;
    }
};