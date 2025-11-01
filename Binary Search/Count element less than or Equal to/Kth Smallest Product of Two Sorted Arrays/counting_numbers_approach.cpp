#include<bits/stdc++.h>
using namespace std;

//Time complexity :- O(log(diff)*N*log(M))
//Space complexity :- O(1)

// Approach :-
// we can use bs on answer for this problem 
// for every number, we can check how many number are smaller or equal to that in the prod
// if (cnt >= k)    increase low, otherwide decrease high 
// for finding the count on number of product for each element we can again use binary search
// we'll fix the one element from any array and apply bs on other array 
// and count the number of element less than given mid value 
// if (curr_val >= 0), then that means product of them will be sorted in left to right 
// otherwise it will be sorted in right to left order 


// link :- https://leetcode.com/problems/maximize-the-minimum-powered-city/

class Solution {
private:
    typedef long long ll;

    bool isPossible(ll min_power, vector<ll> &total_power, int &n, int k, int &r){
        vector<ll> extra_power(n+1, 0);

        for(int i=0; i<n; ++i){
            // extra power of curr station if any based on prev new power station
            extra_power[i] += (i>0 ? extra_power[i-1] : 0);
            // current power of the station 
            ll curr_power = total_power[i] + extra_power[i];
            // power required at current station 
            ll required = max(0LL, min_power - curr_power);
            if(required == 0)
                continue;

            // required power demand is more than k
            if(required > k)
                return false;
            
            // adding required power stations at current station
            k -= required;
            // considering current station as the end of range on left side 
            extra_power[i] += required;
            extra_power[min(n, i+2*r+1)] -= required;
        }
        return true;
    }

public:
    long long maxPower(vector<int>& stations, int r, int k) {
        int n = stations.size();
        vector<ll> total_power(n+1, 0);

        for(int i=0; i<n; ++i){
            // the current tower will contribute it's power from range {i-r, i+r+1}
            total_power[max(0, i-r)] += stations[i];
            total_power[min(n, i+r+1)] -= stations[i];
        }
        ll low = total_power[0], high = total_power[0]+k, res = 0;

        // using difference array method calculate the total power 
        for(int i=1; i<n; ++i){
            total_power[i] += total_power[i-1];
            low = min<ll>(low, total_power[i]);
            high = max<ll>(high, total_power[i]+k);
        }

        // standard bs on answer 
        while(low <= high){
            ll mid = low + (high - low)/2;
            if(isPossible(mid, total_power, n, k, r)){
                res = mid;
                low = mid+1;
            }
            else 
                high = mid-1;
        }
        return res;
    }
};