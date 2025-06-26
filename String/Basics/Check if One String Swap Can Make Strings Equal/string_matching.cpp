#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(n)
// Space complexity :- O(1)

// Approach :-  
// If both string are same no need to swap
// Match each string char by char in both string and count the number of times they differ 
// If count is apart from 2 then it's not possible 
// Otherwise track those two index where they differ (ind1 & ind2)
// The swapping will be possible if and only is s1[ind] == s2[ind2] && s2[ind1] == s1[ind2]
//otherwise it's not possible in any case


// Link :- https://leetcode.com/problems/check-if-one-string-swap-can-make-strings-equal/

class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        if(s1 == s2)        return true;

        int n = s1.size(), cnt = 0, ind1 = -1, ind2 = -1;

        for(int i=0; i<n; ++i){
            if(s1[i] != s2[i]){
                cnt++;
                if(ind1 == -1)      ind1 = i;
                else    ind2 = i;
            }
        }
        if(cnt != 2)        return false;
        if(s1[ind1] == s2[ind2] && s1[ind2] == s2[ind1])        return true;
        return false;
    }
};

