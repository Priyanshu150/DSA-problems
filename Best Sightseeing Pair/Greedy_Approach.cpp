#include<bits/stdc++.h>
using namespace std;

//Formula :- (values[i] + i) + (values[j] - j);
//Approach 1 :- Traverse from right to left and find the maximum value of (values[j] - j) 
//              and add with current element i.e (values[i] + i);

//Approach 2 :- Traverse from left to right and find the maximum value of(values[i] + i)
//              and add with current element i.e (values[j] - j);


//Finding maximum element on right side

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

//Other Approach
//Find maximum element of left side

class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int n = values.size(), res = 0, maxValue = values[0];

        for(int j=1; j<n; ++j){
            res = max(res, maxValue+values[j]-j);
            maxValue = max(maxValue, values[j]+j);
        }
        return res;
    }
};