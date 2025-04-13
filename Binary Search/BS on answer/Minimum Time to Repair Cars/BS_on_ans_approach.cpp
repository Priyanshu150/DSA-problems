#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(n*log(cars*cars*highest_num))  
// Space complexity :- O(1)

// Approach :- 
// we can apply binary search on answer
// the answer range can min_element in array to max_element
// For a predefined fixed time, we've to check if it's possible or not to fixed all cars

// Link :- https://leetcode.com/problems/minimum-time-to-repair-cars/

class Solution {
private:
    #define ll long long 

    bool isPossible(ll time, vector<int>& ranks, int &cars){
        int carsRepaired = 0;

        for(auto rank: ranks){
            carsRepaired += sqrt(time / (ll)rank);

            if(carsRepaired >= cars)
                return true;
        }
        return false;
    }

public:
    long long repairCars(vector<int>& ranks, int cars) {
        int n = ranks.size(), highest = *max_element(ranks.begin(), ranks.end());
        ll low = 1, high = ((ll)cars * (ll)cars * (ll)highest);

        while(low <= high){
            ll mid = low + (high - low)/2;
            if(isPossible(mid, ranks, cars))
                high = mid-1;
            else        low = mid+1;
        }
        return low;
    }
};

