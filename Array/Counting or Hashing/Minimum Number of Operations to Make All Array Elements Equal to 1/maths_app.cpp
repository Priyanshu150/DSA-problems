#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(n*n*log(maxNum))
// Space complexity :- O(1)

// Approach :-  
// if 1 is present in the array the answer will be n - number of 1, where n is no of elements in array
// otherwise from current find till what index the gcd value will turn out ot 1 
// opn number will be (j - i) to convert the number to 1, and n-1 operation to convert rest 
// If we're not able to convert to 1 then it's not possible 


// Link :- https://leetcode.com/problems/parallel-courses-iii/

class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size(), res = INT_MAX, ones = 0;
        bool isPossible = false;

        for(int i=0; i<n; ++i){
            if(nums[i] == 1)
                ones++;

            int gcdVal = nums[i];

            for(int j=i+1; j<n; ++j){
                gcdVal = __gcd(gcdVal, nums[j]);

                if(gcdVal == 1){
                    res = min(res, j-i);
                }
            }
        }
        if(ones > 0)        return n - ones;
        if(res == INT_MAX)  return -1;
        return res+n-1;
    }
};
