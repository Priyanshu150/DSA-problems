#include<bits/stdc++.h>
using namespace std;

//Time complexity :- O(n*log(n))
//Space complexity :- O(n) 

// Approach :-
// we'll use the line sweep algo to solve this problem 
// sort the array after build line_sweep_array 
// whenever we find the interval having end date, we'll update max_val seen till now
// whenever we see an interval having start date, we'll find new val using current_val + max_val seen previously
// for any interval the maximum answer will be previously_maximum_seen + current_value 

//link :- https://leetcode.com/problems/two-best-non-overlapping-events/description/

class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        vector<vector<int>> line_sweep;
        // apply line sweep logic and create a new array 
        for(auto &event:events){
            int start = event[0], end = event[1], val = event[2];
            line_sweep.push_back({start, 1, val});
            line_sweep.push_back({end+1, -1, val});
        }
        // sort the array 
        sort(line_sweep.begin(), line_sweep.end());

        int maxVal = 0, maxSeen = 0;

        for(auto &event: line_sweep){
            int point = event[0], status = event[1], val = event[2];
            
            // new event start 
            if(status == 1)
                // maximize the answer by checking curr val and max seen previouisly 
                maxVal = max(maxVal, maxSeen+val);
            else    // event end 
                // update maximum value seen till now 
                maxSeen = max(maxSeen, val);
        }
        return maxVal;
    }
};