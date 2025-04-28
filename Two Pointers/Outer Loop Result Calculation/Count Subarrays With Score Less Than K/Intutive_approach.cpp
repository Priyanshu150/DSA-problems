#include<bits/stdc++.h>
using namespace std;

//Time complexity :- O(n)
//Space complexity :- O(1)

// Approach :-
// we can create a sliding window, the logic we'll take our left & right pointer which will denote our window
// move right(j) ptr and calculate the sum
// check the condition if the score if greater than increment the left(i) ptr and decrement the sum until we get valid score
// add the number of element in valid window to our answer and increment the right ptr


//link :- https://leetcode.com/problems/count-subarrays-with-score-less-than-k/

class Solution {
    typedef long long ll;

    ll score(ll sum, ll len){
        return (sum * (ll)len);
    }

public:
    long long countSubarrays(vector<int>& nums, long long k) {
        ll res = 0, sum = 0;
        int i = 0, j = 0, n = nums.size();

        while(j < n){
            sum += nums[j];

            while(score(sum, j-i+1) >= k){
                sum -= nums[i];
                i++;
            }
            res += (j-i+1);
            j++;
        }
        return res;
    }
};