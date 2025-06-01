#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(min(n, limit))
// Space complexity :- O(1)

// Approach :- 
// Assume i, j, k as 3 numbers that we need 
// i can be find via loop
// j & k can be find via an approaximation 
// find the min and max value of j and the number lieing b/w lower and higher range will be valid configuration
// remaining_chocolate(rem) will be n - i
// n - i should not be greater than 2*limit otherwise it'll be not possible arrangement 
// because j and k will be at max limit 
// j & k will be (rem - 1) & 1 or (rem-2) & 2 or .......... or (rem - limit) & limit
// upper limit of number can be min(rem, limit)
// lower limit of number will be max(0, rem - limit)
// total valid possibilities will be upper - lower + 1

//Link :- https://leetcode.com/problems/distribute-candies-among-children-ii/

class Solution {
public:
    long long distributeCandies(int n, int limit) {
        long long ans = 0;

        for(int i=0; i<=min(limit, n); ++i){
            int rem = n - i;
            if(rem > 2*limit)   continue;
            int j = max(0, rem - limit), k = min(rem, limit);
            ans += (k-j+1);
        }
        return ans;
    }
};