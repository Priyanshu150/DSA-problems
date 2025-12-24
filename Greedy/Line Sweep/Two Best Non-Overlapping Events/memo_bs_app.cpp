#include<bits/stdc++.h>
using namespace std;

//Time complexity :- O(n*log(n))
//Space complexity :- O(n*3) 

// Approach :-
// sort the interval that way the closest one will appear closer 
// we can explore take and not take case and try all possibilities 
// state will be index and count 
// for picking the next index we can use binary search 
// memoize this solution with 2d dp(n*3)

//link :- https://leetcode.com/problems/two-best-non-overlapping-events/description/

class Solution {
private:
    int n;
    vector<vector<int>> dp;

    int binarySearch(int ind, vector<vector<int>> &events, int target){
        int low = ind+1, high = n-1, res = n;

        while(low <= high){
            int mid = low + (high - low)/2;

            if(events[mid][0] > target){
                res = mid;
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return res;
    }

    int solve(int ind, int count, vector<vector<int>> &events){
        // base case 
        if(count == 2 || ind >= n){
            return 0;
        }
        if(dp[ind][count] != -1)
            return dp[ind][count];

        // find the next greater index using binary search 
        int nextValidInd = binarySearch(ind, events, events[ind][1]);
        // explore take and not take possibility of cases 
        int take = events[ind][2] + solve(nextValidInd, count+1, events);
        int notTake = solve(ind+1, count, events);

        return dp[ind][count] = max(notTake, take);
    }

public:
    int maxTwoEvents(vector<vector<int>>& events) {
        n = events.size();
        // sort the intervals based on starting index 
        sort(events.begin(), events.end());
        // intialize 2d dp array of size n*3 with -1
        dp = vector<vector<int>> (n, vector<int> (3, -1));

        int  count = 0;
        return solve(0, count, events);
    }
};