#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(N*log(N))  
// Space complexity :- O(1)

// Approach :- 
// the brute force can be further optimize by applying binary search on the search space
// the seach space for answer is 1 to max_element 
// low = 1, high = max_element, and if we find the valid grp we'll save the answer
// at the same time we'll try to increase our answer by doing low = mid+1
// otherwise we will increase high = mid-1

// Link :- https://www.geeksforgeeks.org/problems/coin-change2448/1

class Solution {
private:
    int isPossible(int maxCandy, vector<int>& candies, long long k){
        long long cnt = 0;

        for(auto candy: candies){
            cnt += (candy/maxCandy);
            if(cnt >= k)
                return true;
        }
        return false;
    }

public:
    int maximumCandies(vector<int>& candies, long long k) {
        int n = candies.size();

        int highest = *max_element(candies.begin(), candies.end());

        for(int ind=highest; ind>=1; --ind){
            if(isPossible(ind, candies, k))
                return ind;
        }
        return 0;
    }
};