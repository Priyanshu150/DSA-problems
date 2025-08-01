#include<bits/stdc++.h>
using namespace std;

//Time complexity :- O(n*log(1e11))
//Space complexity :- O(n)

// Approach :-
// we can use the concept of binary search on answer for this problem 
// we've to maximize the power and then return minimum among them
// inorder to do that we need to find the power current each city it getting 
// calculate that using prefix sum approach
// now the answer range will be b/w 0 to 1e11
// for a vaild mid or the power we need to find wheather it's possible to attain that or not 
// for that we can check on the station_powers array wheather it needed more or not 
// if it does then we'll station on the (curr + r) range so that (curr_ind + 2*r+1) range is covered 
// at last it's possible to give the power under the given new stations 
// then we can decrement the power for answer other we'll increase it 


//link :- https://leetcode.com/problems/maximize-the-minimum-powered-city/

class Solution {
private:
    #define ll long long 

    bool isPossible(ll min_power, vector<ll> &default_power, int k, int r, int n){
        vector<ll> extra_powers(n+1);

        for(int i=0; i<n; ++i){
            extra_powers[i] += (i>0 ? extra_powers[i-1] : 0);

            ll curr_power = default_power[i] + extra_powers[i];
            ll required = max(0LL, min_power - curr_power);
            if(required == 0)       continue;
            if(required > k)  return false;
            k -= required;

            extra_powers[i] += required;
            extra_powers[min(n, i+2*r+1)] -= required;
        }
        return true;
    }

public:
    long long maxPower(vector<int>& stations, int r, int k) {
        int n = stations.size();
        vector<ll> station_powers(n+1);

        for(int i=0; i<n; ++i){
            station_powers[max(0, i-r)] += stations[i];
            station_powers[min(n, i+r+1)]  -= stations[i];
        }
        for(int i=1; i<=n; ++i){
            station_powers[i] += station_powers[i-1];
        }
        ll low = 0, high = 1e11;
        while(low <= high){
            ll mid = low + (high - low)/2;
            if(isPossible(mid+1, station_powers, k, r, n))
                low = mid+1;
            else 
                high = mid-1;
        }
        return low;
    }
};