#include<bits/stdc++.h>
using namespace std;

// Time complexity :- O(n*log(n) + n*n + n)                 
// Space complexity :- O(n+n)              

// Approach :-  
// Try completing each group using characters from the string. 
// If there aren’t enough characters for the last group, use the fill character to complete the group.

// link :- https://leetcode.com/problems/divide-a-string-into-groups-of-size-k/

class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        vector<string> ans;
        int n = s.size(), ind = 0;

        while(ind < n){
            string str = "";
            for(int i=0; i<k; ++i){
                if(ind < n)
                    str += s[ind++];
                else
                    str += fill;
            }
            ans.push_back(str);
        }
        return ans;
    }
};