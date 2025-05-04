#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(n)
// Space complexity :- O(n)

// Approach :-
// we'll count the occurence of each sequence, for storing it we can use hashing
// if there are n numbers of pair for a sequence, then total pair count will be sum of n natural numbers 


// Link :- https://leetcode.com/problems/number-of-equivalent-domino-pairs/

class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        unordered_map<string, int> mp;
        int res = 0;

        for(auto domino: dominoes){
            int a = domino[0], b = domino[1];
            string str = "";

            if(a < b)   str = to_string(a) + "-" + to_string(b);
            else        str = to_string(b) + "-" + to_string(a);

            res += mp[str];
            mp[str] += 1;
        }
        return res;
    }
};