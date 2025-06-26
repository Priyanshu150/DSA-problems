#include<bits/stdc++.h>
using namespace std;

//Time complexity :- O(n + t)
//Space complexity :- O(26)

// Approach :-
// store the frequency of each character 
// apply the operation for t times,
// store the count of z and move the count of i to i+1 denoting a char shift 
// for z, we've to move the count to two place i.e. freq[0] & freq[1] denoting the z changes to 'ab'
// at last count the toatal frequency present and that will be our answer


//link :- https://leetcode.com/problems/total-characters-in-string-after-transformations-i/

class Solution {
public:
    int lengthAfterTransformations(string s, int t) {
        int mod = 1e9+7, res = 0, freq[26] = {0};

        for(auto ch: s){
            freq[ch - 'a'] += 1;
            freq[ch - 'a'] %= mod;
        }
        
        while(t--){
            int charCountOfZ = freq[25];
            res = 0;

            for(int i=24; i>=0; --i){
                freq[i+1] = freq[i]%mod;
                res = (res + freq[i+1]) % mod;
            }
            freq[0] = 0;
            if(charCountOfZ > 0){
                freq[0] = (freq[0] + charCountOfZ) % mod;
                freq[1] = (freq[1] + charCountOfZ) % mod;
                res = (res + freq[0]) % mod;
                res = (res + charCountOfZ) % mod;
            }
        }
        return res;
    }
};