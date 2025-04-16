#include<bits/stdc++.h>
using namespace std;

//Time complexity :- O(N)
//Space complexity :- O(1)

//Approach :-
// Consider each window of size K, we can find the minimum number of white clored blocks in the window
// we can use a sliding window to solve this problem and the min white colored window will be our answer

//link :- https://leetcode.com/problems/minimum-recolors-to-get-k-consecutive-black-blocks/

class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int n = blocks.size(), j=0, whiteCnt = 0, res = k;

        while(j<k){
            if(blocks[j] == 'W')
                whiteCnt++;
            
            ++j;
        }
        res = whiteCnt;

        for(int i=0; i<(n-k); ++i){
            if(blocks[i] == 'W')
                whiteCnt--;
            
            if(blocks[j] == 'W')
                whiteCnt++;
            
            ++j;
            res = min(res, whiteCnt);
        }
        return res;
    }
};