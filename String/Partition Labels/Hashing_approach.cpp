#include<bits/stdc++.h>
using namespace std;

// Time complexity :- O(n)            // Where n is length of string s
// Space complexity :- O(n)          // for array 

// Approach :-
// Capture the last index of each char in array
// traverse on the string again and keep the last of the currnt_char (last)
// In inner loop, keep updating the last index depending on the incoming chars 
// once inner loop traversal is completed store the lenght in the ans

// Links :- 
// (leetcode) https://leetcode.com/problems/partition-labels/
// (gfg) https://www.geeksforgeeks.org/problems/maximize-partitions-in-a-string/1


class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> ans, lastInd(26, -1);
        int n = s.size(), ind = 0, prevInd = 0;

        for(int i=0; i<n; ++i)
            lastInd[s[i]-'a'] = i;
        
        while(ind < n){
            int last = lastInd[s[ind]-'a'];
            ind++;

            while(ind <= last){
                last = max(last, lastInd[s[ind]-'a']);
                ind++;
            }
            ans.push_back(ind - prevInd);
            prevInd = ind;
        }
        return ans;
    }
};