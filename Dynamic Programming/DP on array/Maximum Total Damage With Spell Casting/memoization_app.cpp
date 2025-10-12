#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(n*log(n))
// Space complexity :- O(n)

// Approach :-  
// We can count freq of equal spell and keep it into hash map
// Maintain an array in sorted order with unique elements only 
// we can use binary search for finding next spell having value curr_val + 3 
// Explore all the possibilites of take and not take cases 
// whever we're taking the spell take all the frequency of that spell
// and move to next index having value curr_val+3 using binary search 
// since only 1 parameter is changing the we can memoize it using 1-d dp

// Link :- https://leetcode.com/problems/maximum-total-damage-with-spell-casting/

class Solution {
private:
    int n;
    typedef long long ll;

    ll solve(int ind, unordered_map<ll, ll> &mp, vector<ll> &nums, vector<ll> &dp){
        if(ind >= n)
            return 0;
        if(dp[ind] != -1)
            return dp[ind];
        
        int j = lower_bound(begin(nums)+ind+1, end(nums), nums[ind]+3) - begin(nums);
        ll notTake = solve(ind+1, mp, nums, dp);
        ll take = mp[nums[ind]]*nums[ind] + solve(j, mp, nums, dp);

        return dp[ind] = max(notTake, take);
    }

public:
    long long maximumTotalDamage(vector<int>& power) {
        unordered_map<ll, ll> mp;
        // counting each number
        for(auto p: power)
            mp[p] += 1;
        
        vector<ll> nums;
        n = mp.size();
        // creating an array of all the unique numbers
        for(auto it: mp){
            nums.push_back(it.first);
        }
        // sorting the array to apply binary search for searching 
        sort(nums.begin(), nums.end());
        // using 1-d dp to store the calculated state values 
        vector<ll> dp(n, -1);
        return solve(0, mp, nums, dp);
    }
};