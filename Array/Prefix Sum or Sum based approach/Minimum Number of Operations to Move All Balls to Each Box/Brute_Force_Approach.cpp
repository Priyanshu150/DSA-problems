#include<bits/stdc++.h>
using namespace std;

//Time complexity :- O(N^2)
//Space complexity :- O(1)

//Approach :- 
// For every index traverse to the left and right of the array and find the distance of '1'  from that ind
// Dist is given by abs(j - i), where j is the index either on left or right of curr Index i

//Link :- https://leetcode.com/problems/minimum-number-of-operations-to-move-all-balls-to-each-box/description/

class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n = boxes.size();
        vector<int> res(n, 0);

        for(int i=0; i<n; ++i){
            int lt = i-1, rt = i+1, cnt = 0;
            while(lt >= 0){
                if(boxes[lt] == '1')
                    cnt += (i - lt);
                
                lt--;
            }
            while(rt < n){
                if(boxes[rt] == '1')
                    cnt += (rt - i);
                
                rt++;
            }
            res[i] = cnt;
        }
        return res;
    }
};