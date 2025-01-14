#include<bits/stdc++.h>
using namespace std;

//Time complexity :- O(N)
//Space complexity :- O(1)    

//Approach :-
// Caluclate the rightSum of the array
// At every ind sub the num contribution from rightSum
// Check if rightSum == leftSum
// calculate the leftSum parallely

//link :- https://www.geeksforgeeks.org/problems/equilibrium-point-1587115620/1

class Solution {
  public:
    // Function to find equilibrium point in the array.
    int findEquilibrium(vector<int> &arr) {
        // code here
        int n = arr.size(), rightSum = 0, leftSum = 0;
        rightSum = accumulate(arr.begin(), arr.end(), rightSum);
        
        for(int i=0; i<n; ++i){
            rightSum -= arr[i];
            
            if(leftSum == rightSum)
                return i;
                
            leftSum += arr[i];
        }
        return -1;
    }
};