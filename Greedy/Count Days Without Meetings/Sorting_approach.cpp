#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(n*log(n))
// Space complexity :- O(n)

// Approach :-  
// sort the timing based on start time 
// check if the starting timing is not 1 then add the spare days in the res
// Traverse through the sorted array and find add the spare day in the result if present
// if current starting time is greater than previous ending time then there must be spare days
// at every index update the ending time i.e max of current ending time and previous ending time
// atlast check if the ending timing is not n then add the spare days in the res

//Link :- https://leetcode.com/problems/count-days-without-meetings/

class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end());

        int res = 0, n = meetings.size(), end = meetings[0][1];
        if(meetings[0][0] != 1)
            res += (meetings[0][0] - 1);
        
        for(int i=1; i<n; ++i){
            if(end < meetings[i][0])
                res += (meetings[i][0] - end - 1);
            
            end = max(meetings[i][1], end);
        }
        res += (days - end);
        return res;
    }
};