#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(26^n)
// Space complexity :- O(26)

// Approach :-  
// make a freq array for every tiles letter and apply backtracking 
// Try every possible combination of char and decrease its freq and call recusion to create other possible combination
// decreasing freq means we're taking that char and decrement it's count means that char doesn't exist anymore
// We're not creating the strings instead we're calculation the count for every valid sequenc
// After generating all sequence from a char we're backtracking and trying other char at the same place

// Link :- https://leetcode.com/problems/letter-tile-possibilities/description/

class Solution {
    private:
    void solve(int &res, vector<int> &freq){
        res += 1;

        for(int i=0; i<26; ++i){
            if(freq[i] == 0)    continue;

            freq[i] -= 1;
            solve(res, freq);
            freq[i] += 1;
        }
    }

public:
    int numTilePossibilities(string tiles) {
        int n = tiles.size(), res = 0;
        vector<int> freq(26, 0);

        for(int i=0; i<n; ++i)
            freq[tiles[i] - 'A'] += 1;
        
        solve(res, freq);
        return res - 1;
    }
};
