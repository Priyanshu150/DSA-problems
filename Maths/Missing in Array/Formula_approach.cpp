#include<bits/stdc++.h>
using namespace std;

// Time complexity :- O(n)          
// Space complexity :- O(1)              

// Approach :- 
// calculate the sum of array and sum of n natural numbers 
// the differnnce b/w both will give our missing number

// Links :- https://www.geeksforgeeks.org/problems/missing-number-in-array1416/1

class Solution {
  public:
    int missingNum(vector<int>& arr) {
        // code here
        int n = arr.size(), arrSum = 0, sum = 0;
        
        for(int i=0; i<n; ++i){
            arrSum += arr[i];
            sum += (i+1);
        }
        sum += (n+1);
        return (sum - arrSum);
    }
};