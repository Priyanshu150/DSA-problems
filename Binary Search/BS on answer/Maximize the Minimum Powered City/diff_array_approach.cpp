#include<bits/stdc++.h>
using namespace std;

//Time complexity :- O(n*log(1e11))
//Space complexity :- O(n)

// Approach :-
// we can use the concept of binary search on answer for this problem 
// we've to maximize the power and then return minimum among them
// inorder to do that we need to find the power current each city it getting 
// calculate that using difference array and prefix sum approach
// now the answer range will be b/w min_value to max_value + k of array 
// for a vaild mid or the power we need to find wheather it's possible to attain that or not 
// for that we can check on the station_powers array wheather it needed more or not 
// if it does then we'll station on the (curr + r) range so that (curr_ind + 2*r+1) range is covered 
// at last it's possible to give the power under the given new stations 
// then we can decrement the power for answer other we'll increase it 


//link :- https://leetcode.com/problems/maximize-the-minimum-powered-city/

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