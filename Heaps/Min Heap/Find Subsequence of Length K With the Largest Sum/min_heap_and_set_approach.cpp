#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(n + k)  
// Space complexity :- O(k)

// Approach :-  
// find the k largest element using min heap 
// store those element into a map
// traverse the array and check if that element is present in the map or not 
// if it is then put it into result array and remove it's contribution from map


// Link :- https://leetcode.com/problems/find-subsequence-of-length-k-with-the-largest-sum/

class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> pq;

        for(auto num: nums){
            pq.push(num);
            if(pq.size() > k)
                pq.pop();
        }
        unordered_map<int,int> mp;

        while(!pq.empty()){
            mp[pq.top()] += 1;
            pq.pop();
        }
        vector<int> ans;

        for(auto num: nums){
            if(mp.count(num) && mp[num]>0){
                ans.push_back(num);
                mp[num] -= 1;
            }
        }
        return ans;
    }
};