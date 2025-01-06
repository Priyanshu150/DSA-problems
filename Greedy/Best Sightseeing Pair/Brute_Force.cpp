#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int n = values.size(), res = 0;

        for(int i=0; i<n; ++i){
            for(int j=i+1; j<n; ++j){
                res = max(res, (values[i] + values[j] + i - j));
            }
        }
        return res;
    }
};