#include<bits/stdc++.h>
using namespace std;

//Time complexity :- O(N)       
//Space complexity :- O(1)    

// Approach :-
// If a subarray has odd numbers of odd number then it will odd sum
// For solving this problem we can use the prefix sum concept where we'll calculate the sum left to right
// if sum till current ind is even, then we'll check how many odd_sum_cnt previously existed and add that number in out cnt
// becuase even_sum - odd_sum will  odd_sum and vice-versa


//link :- https://leetcode.com/problems/number-of-sub-arrays-with-odd-sum/

class Solution {
    public:
    int numOfSubarrays(vector<int>& arr) {
        int n = arr.size(), res = 0, mod = 1e9+7;
        int oddSumCnt = 0, evenSumCnt = 1, sum = 0;

        for(int i=0; i<n; ++i){
            sum += arr[i];
            if(sum % 2){
                res = (res+evenSumCnt)%mod;
                oddSumCnt += 1;
            }
            else{
                res = (res+oddSumCnt)%mod;
                evenSumCnt += 1;
            }
        }
        return res;
    }
};