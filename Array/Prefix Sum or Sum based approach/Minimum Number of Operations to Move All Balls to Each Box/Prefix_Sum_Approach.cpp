#include<bits/stdc++.h>
using namespace std;

//Time complexity :- O(N)
//Space complexity :- O(N + N)

//Approach :- 
// Pre-calculate the distance of '1' from right side and left side for a given index
// Calulate the result sum of distance of '1' at left and right side

//Link :- https://leetcode.com/problems/minimum-number-of-operations-to-move-all-balls-to-each-box/description/

class Solution {
private:
    vector<int> prefixSumArrayCalc(int i, int j, int k, string &boxes){
        int cnt = 0, incParam = 0;
        vector<int> prefix;

        while(i != j){
            cnt += incParam;
            prefix.push_back(cnt);
            if(boxes[i] == '1')
                incParam++;
            
            i += k;
        }
        cout<<endl;
        return prefix;
    }

public:
    vector<int> minOperations(string boxes) {
        int n = boxes.size();
        vector<int> res, leftPrefixSum, rightPrefixSum;
        leftPrefixSum = prefixSumArrayCalc(0, n, 1, boxes);
        rightPrefixSum = prefixSumArrayCalc(n-1, -1, -1, boxes);

        for(int i=0; i<n; ++i)
            res.push_back(leftPrefixSum[i] + rightPrefixSum[n-i-1]);

        return res;
    }
};