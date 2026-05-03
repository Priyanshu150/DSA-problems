#include <bits/stdc++.h>
using namespace std;

// Time Complexity :- O(n*log(n))
// Space Complexity :- O(1)

// Approach :- 
// 

// Code : - 

class Solution {
  public:
    vector<int> sortBySetBitCount(vector<int>& arr) {
        stable_sort(arr.begin(), arr.end(), [](const int &num1, const int &num2) -> bool {
            // count the number of bits in each numbers 
            int bitCnt1 = __builtin_popcount(num1);
            int bitCnt2 = __builtin_popcount(num2);
            
            // sort the array based decreasing bits count 
            return bitCnt1 > bitCnt2;
        });
        return arr;
    }
};