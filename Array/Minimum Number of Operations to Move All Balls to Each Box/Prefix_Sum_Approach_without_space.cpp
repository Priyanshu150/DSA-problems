#include<bits/stdc++.h>
using namespace std;

//Time complexity :- O(N + N)
//Space complexity :- O(1)

//Approach :- 
// Calculate the sum and no of '1' from right side 
// move from left to right, the contribution of '1' decrease by no of ones on right side 
// and the contribution of '1' increases by no of ones on left side
// At every index the number of '1' is sum of '1' on left and right side

//Link :- https://leetcode.com/problems/minimum-number-of-operations-to-move-all-balls-to-each-box/description/

class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n = boxes.size(), ltSum = 0, rtSum = 0, lt = 0, rt = 0;

        for(int i=n-1; i>=0; --i){
            if(boxes[i] == '1'){
                rt++;
                rtSum += i;  // dist = abs(j - i), here i = 0 so dist = j
            }
        }
        vector<int> res;

        for(int i=0; i<n; ++i){
            res.push_back(ltSum + rtSum);
            if(boxes[i] == '1'){
                lt += 1;
                rt -= 1;
            }
            ltSum += lt;
            rtSum -= rt;
        }
        return res;
    }
};