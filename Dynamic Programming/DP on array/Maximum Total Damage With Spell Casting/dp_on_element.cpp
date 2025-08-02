#include<bits/stdc++.h>
using namespace std;

//Time complexity :- O(N*log(N))
//Space complexity :- O(N)    

//Approach :-
// Instead of donig DP on index we'll do DP on the number because the question demand about that 
// we'll store the frequency of each elemnet in the map and use binary serach to find the el-2 number in it
// if we find the previous element we'll calculate the result based on the formula provided 
// And for all the combination we'll maintain a maximum value which will be our answer
// Also we'll store the dp for the previous state and used for them in later calculatons


//link :- https://leetcode.com/problems/maximum-total-damage-with-spell-casting/

class Solution {
  #define ll long long 

public:
    long long maximumTotalDamage(vector<int>& power) {
       map<ll, ll> freq;
       unordered_map<int, ll> dp;

        for(auto el: power) 
            freq[el] += 1;
        
        ll ans = 0, prevEl, backEl = 0;
        for(auto [el, fr]: freq){
            auto backIt = freq.lower_bound(el-2);
            if(backIt != freq.begin())
                backEl = (*(--backIt)).first;
            
            dp[el] = max(dp[prevEl], el*fr + dp[backEl]);
            ans = max(ans, dp[el]);
            prevEl = el;
        }
        return ans;
    }
};