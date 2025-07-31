#include<bits/stdc++.h>
using namespace std;

//Time complexity :- O(N)
//Space complexity :- O(N)

// Approach :-
// To calculate the contribution of each number in the interval, we'll use counting method in O(1)
// for that we'll use the using map, we'll increment the start by 1 and decrement end+1 by 1
// we'll take the continuous sum starting from the first interval of overall 
// whenever the cnt is greater than k we'll take that interval as answer 
// also whenever the cnt of that interval is -ve, check for interval-1, it can be our potential answer

// link :- https://www.geeksforgeeks.org/problems/powerfull-integer--170647/1

class Solution {
  public:
    int powerfulInteger(vector<vector<int>>& intervals, int k) {
        // code here
        map<int,int> mp;
        
        for(auto interval: intervals){
            mp[interval[0]] += 1;
            mp[interval[1]+1] -= 1;
        }
        int res = -1, sum = 0;
        
        for(auto [num, cnt]: mp){
            sum += cnt;
            if(sum >= k)
                res = num;
            if(cnt < 0 && (sum - cnt) >= k)
                res = num-1;
        }
        return res;
    }
};
