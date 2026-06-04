#include<bits/stdc++.h>
using namespace std;

// Time complexity :- O(n + m)
// Space complexity :- O(1)

// Approach :- 
// Either we can take first land ride then water ride or vice versa 
// so find the sortest time to take a land ride and then for each water rider check which can be finish faster 
// same can we done in case we take water rider first 
// min of both the options can be our answer 

// Link :- https://leetcode.com/problems/earliest-finish-time-for-land-and-water-rides-ii/description/

class Solution {
private:
    int solve(vector<int> &ride1StartTime, vector<int> &ride1Duration, vector<int> &ride2StartTime, vector<int> &ride2Duration){

        int finish1 = INT_MAX;
        int n = ride1StartTime.size();
        // find the fastest time we can finish the ride1 
        for(int i=0; i<n; ++i){
            int timetaken = ride1StartTime[i] + ride1Duration[i];
            finish1 = min(finish1, timetaken);
        }

        int finish2 = INT_MAX;
        int m = ride2StartTime.size();
        // find the fastest time to complete ride2 after completing ride1 
        for(int i=0; i<m; ++i){
            // take the starting time of ride2 after ending of ride1 
            int timetaken = max(ride2StartTime[i], finish1) + ride2Duration[i];
            finish2 = min(finish2, timetaken);
        }
        return finish2;
    }

public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        // first take land ride and then water rider 
        int opn1 = solve(landStartTime, landDuration, waterStartTime, waterDuration);
        // first take water ride and then land rider 
        int opn2 = solve(waterStartTime, waterDuration, landStartTime, landDuration);

        return min(opn1, opn2);
    }
};