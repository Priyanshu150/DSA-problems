#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(16)
// Space complexity :- O(16)

//Approach :- 
// Generate all the power of 3 and store it
// In this case, the maximum value can be 16 only because n will be less than or equal to 10^7
// traversing from the maximum value to minimum value we keep on subtract that number from n
// only if num <= n, if n becomes 0 then we return true
// other wise if we came out of loop that means it can't be possible we'll return false

//Link :- https://leetcode.com/problems/check-if-number-is-a-sum-of-powers-of-three/description/

class Solution {
public:
    bool checkPowersOfThree(int n) {
        int prod = 1;
        vector<int> arr;

        for(int i=0; i<15; ++i){
            arr.push_back(prod);
            prod *= 3;
        }

        for(int i=14; i>=0; --i){
            if(arr[i] <= n)
                n -= arr[i];
            
            if(n == 0)
                return true;
        }
        return false;
    }
};