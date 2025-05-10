#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(n)  
// Space complexity :- O(n)

// Approach :-
// maintain a prefix sum based on array, if the number is greater than k then add +1 otherwise -1
// if any point prefix sum if greater than 0 than mean the current subbarry has majority element greater that k
// maintain every prefix sum first occurence in the map with their indexes
// At any index if the prefix sum increases that means a number greater than k value exist in that window
// so we can find the index of prefix sum -1 in map and calulate the max length with (curr_ind - mp[prefixSum - 1])


// Link :- https://www.geeksforgeeks.org/problems/longest-subarray-with-majority-greater-than-k/1

class Solution {
  public:
    int longestSubarray(vector<int> &arr, int k) {
        // Code here
        int n = arr.size(), prefixSum = 0, res = 0;
        unordered_map<int,int> mp;
        mp[0] = -1;
        
        for(int i=0; i<n; ++i){
            prefixSum += (arr[i] > k) ? 1 : -1;
            if(prefixSum > 0)
                res = i+1;
            
            if(mp.count(prefixSum - 1))
                res = max(res, i - mp[prefixSum - 1]);
            
            if(!mp.count(prefixSum))
                mp[prefixSum] = i;
        }
        return res;
    }
};