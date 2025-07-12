#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(n)
// Space complexity :- O(1)

// Approach :-  
// for k meeting we can adjust the meeting such a way that if we shift all the meeting to left or right
// the space between them will merge so we will k+1 space, 1 extra becaue it was already present
// use sliding window approach and take the max sum of k+1 space 
// also include 0 and eventTime because they'll also contribute if no meeting start or end at that time

// links :- https://leetcode.com/problems/reschedule-meetings-for-maximum-free-time-i/

class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {
        int res = 0, left = 0, n = startTime.size(), sum = 0;

        for(int right=0; right<=n; ++right){  
            int prev = 0, curr = eventTime;
            if(right > 0)   prev = endTime[right-1];
            if(right < n)   curr = startTime[right];

            sum += (curr - prev);
            res = max(sum, res);

            if((right - left) == k){
                prev = 0;
                if(left > 0)   prev = endTime[left-1];
                sum -= (startTime[left] - prev);
                ++left;
            }
        }
        return res;
    }
};
