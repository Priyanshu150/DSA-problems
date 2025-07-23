#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(N)
// Space complexity :- O(1)

// Approach :- 
// for every number count it's contribution in the overall sum 
// every number will contribute to the number of element on it's right side + 1 (including himself) i.e. (n-i)
// and if there are any number present on the left side of the current number
// then it will repeat the number of times i.e the number of element on left side i.e (i+1)
// every number will contribute (n-i)*(i+1) times 

// Link :- https://www.geeksforgeeks.org/problems/sum-of-subarrays2229/1

class Solution {
  public:
    int subarraySum(vector<int>& arr) {
        int sum = 0, n = arr.size();
        
        for(int i=0; i<n; ++i){
            sum += ((n-i)*(i+1))*arr[i];
        }
        return sum;
    }
};