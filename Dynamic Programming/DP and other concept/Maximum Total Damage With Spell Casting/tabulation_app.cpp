#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(n*log(n))
// Space complexity :- O(n)

// Approach :-  
// For base case, intially every value should be 0
// ind is only changing, traverse from n-1 to 0
// copy and paste the same possibilites case from recursion 
// at last answer will be store at dp[0]

// Link :- https://leetcode.com/problems/maximum-total-damage-with-spell-casting/

class Solution {
private:
    typedef long long ll;

public:
    long long maximumTotalDamage(vector<int>& power) {
        unordered_map<ll, ll> mp;
        // counting each number
        for(auto p: power)
            mp[p] += 1;
        
        vector<ll> nums;
        int n = mp.size();
        // creating an array of all the unique numbers
        for(auto it: mp){
            nums.push_back(it.first);
        }
        // sorting the array to apply binary search for searching 
        sort(nums.begin(), nums.end());
        // using 1-d dp to store the calculated state values 
        vector<ll> dp(n+1, 0);

        for(int ind=n-1; ind>=0; --ind){
            int j = lower_bound(begin(nums)+ind+1, end(nums), nums[ind]+3) - begin(nums);
            // skip the current index and move  next 
            ll notTake = dp[ind+1];
            // take the current index with it's values 
            ll take = mp[nums[ind]]*nums[ind] + dp[j];

            dp[ind] = max(notTake, take);
        }
        return dp[0];
    }
};