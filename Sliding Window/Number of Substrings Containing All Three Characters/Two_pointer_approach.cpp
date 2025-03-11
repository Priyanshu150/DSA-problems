#include<bits/stdc++.h>
using namespace std;

//Time complexity :- O(N)
//Space complexity :- O(1)

// Approach :-
// we'll try to find a valid window which contains all the value of 'a', 'b' and 'c'
// window can be represented as (left - right) index included 
// once we got the window all the char which are on the right side of the window will also be valid
// so we can add (n - right_ptr) to our ans because that number of sub string will be valid 
// Now, we will move the pointer until we got an invalid window
// at the same time we'll update our answer until we didn't find a invalid window 
// because all the window will be valid and we can consider the substring cnt in our answer
// Once we find the invalid window we'll again move right pointer and try to find the new valid window

//link :- https://leetcode.com/problems/number-of-substrings-containing-all-three-characters/

class Solution {
private:
    bool isPresent(vector<int> &freq){
        return (freq[0] && freq[1] && freq[2]);
    }

public:
    int numberOfSubstrings(string s) {
        vector<int> freq(3, 0);
        int n = s.size(), left = 0, res = 0;

        for(int right=0; right<n; ++right){
            freq[s[right] - 'a'] += 1;

            while(isPresent(freq)){
                res += (n - right);
                freq[s[left] - 'a'] -= 1;
                ++left;
            }
        }
        return res;
    }
};