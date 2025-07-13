#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(n)
// Space complexity :- O(n)

// Approach :-  
// Put every value of the array in the min heap
// Take out the lowest two values which will be and calucluate the new value 
// Put it into the heap and repeat this process until the top value of the heap is greater k
// Count each step which will be our answer

// Link :- https://leetcode.com/problems/minimum-operations-to-exceed-threshold-value-ii/

class Solution {
    private:
    #define ll long long

public:
    int minOperations(vector<int>& nums, int k) {
        int res = 0, n = nums.size();
        priority_queue<ll, vector<ll>, greater<ll>> pq;

        for(int i=0; i<n; ++i)
            pq.push(nums[i]);
        
        while(pq.size()>1 && pq.top() < k){
            ll first = pq.top();
            pq.pop();

            ll second = pq.top();
            pq.pop();

            res++;
            ll newValue = 2*min<ll>(first, second) + max<ll>(first, second);
            pq.push(newValue);
        }
        return res;
    }
};