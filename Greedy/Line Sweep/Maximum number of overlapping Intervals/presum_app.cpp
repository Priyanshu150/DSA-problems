#include<bits/stdc++.h>
using namespace std;

//Time complexity :- O(n)
//Space complexity :- O(n) 

// Approach :-
// count the contribution of each element using prefix sum 
// instead of implement it on whole range [l,r] just update the range 
// i.e. mp[l] += 1 and mp[r+1] -= 1
// use prefix sum find the sum of each element contribution 
// maintain the maximum contribution which will be our answer 

//link :- https://www.geeksforgeeks.org/problems/intersecting-intervals/1

class Solution {
  public:
    int overlapInt(vector<vector<int>> &arr) {
        // sort the intervals 
        sort(arr.begin(), arr.end());
        
        map<int,int> freq;
        
        for(auto interval: arr){
            // using prefix sum technique update the interval contribution 
            int st = interval[0], end = interval[1];
            
            freq[st] += 1;
            freq[end+1]  -= 1;
        }
        int sum = 0, res = 0;
        
        for(auto it: freq){
            // find the num and contribution 
            int num = it.first, contri = it.second;
            
            // calculate each number contribution 
            sum += contri;
            // upate the maximum contribution 
            res = max(res, sum);
        }
        return res;
    }
};
