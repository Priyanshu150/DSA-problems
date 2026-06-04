#include<bits/stdc++.h>
using namespace std;

// Time complexity :- O(n*log(n) + m*log(m) + n + m)
// Space complexity :- O(n + m)

// Approach :- 
// sort both the ride according to the time of ride which finishes first 
// Either we can take first land ride then water ride or vice versa 
// take the first ride of the land ride as it's sorted which will be fastest to complete 
// and check for all the water ride which can give us the minimum time 
// same can be done if we take water rider 
// min result of both the options will be our answer 

// Link :- https://leetcode.com/problems/earliest-finish-time-for-land-and-water-rides-ii/description/

class Solution {
private:
    int findMinTime(int st, int dur, vector<pair<int,int>> rides, int sz){
        int res = INT_MAX;

        // among all ride 
        for(int i=0; i<sz; ++i){
            int rideSt = rides[i].first;
            int rideDur = rides[i].second;
            // total time take to complete the current ride  
            int timeTaken = max(st + dur, rideSt) + rideDur;
            res = min(res, timeTaken);
        }
        return res;
    }

public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        // custom comparator which sort based on fastest ride finishing time 
        auto comparePairs = [](pair<int,int> &ride1, pair<int,int> &ride2) {
            return (ride1.first + ride1.second) < (ride2.first + ride2.second);
        };
        
        int n = landStartTime.size();
        vector<pair<int,int>> landRides;

        // maintain all the land rider in one array 
        for(int i=0; i<n; ++i){
            int st = landStartTime[i];
            int dur = landDuration[i];

            landRides.push_back({st, dur});
        }
        // sort all the land rides according to the ending time 
        sort(landRides.begin(), landRides.end(), comparePairs);

        int m = waterStartTime.size();
        vector<pair<int,int>> waterRides;

        // maintain all the water rider in one array 
        for(int i=0; i<m; ++i){
            int st = waterStartTime[i];
            int dur = waterDuration[i];

            waterRides.push_back({st, dur});
        }
        // sort all the land rides according to the ending time 
        sort(waterRides.begin(), waterRides.end(), comparePairs);

        // first take the land ride and then water ride with first land rider being fasterst
        int opn1 = findMinTime(landRides[0].first, landRides[0].second, waterRides, m);
        // first take the water ride and then land ride with first water rider being fasterst
        int opn2 = findMinTime(waterRides[0].first, waterRides[0].second, landRides, n);
        // min of both options will be our answer 
        return min(opn1, opn2);
    }
};

