#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int n = values.size(), res = 0, maxValue = values[n-1] - (n-1);

        for(int i=n-2; i>=0; --i){
            res = max(res, values[i]+i+maxValue);
            maxValue = max(maxValue, values[i]-i);
        }
        return res;
    }
};