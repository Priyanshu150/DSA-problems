#include<bits/stdc++.h>
using namespace std;

//Time complexity :- O(N), where n is the size of array
//Space complexity :- O(1)    

//Approach :- 
// Apply sliding window approach and collect the indexes when sum is equal to target

//Links :- https://www.geeksforgeeks.org/problems/subarray-with-given-sum-1587115621/1

class Solution {
  public:
    vector<int> subarraySum(vector<int> &arr, int target) {
        // code here
        int n = arr.size(), i(0), j(0), sum(0);
        int minInd = -1, maxInd = -1;
        
        while(j < n){
            sum += arr[j];
            
            while(i<=j && sum > target){
                sum -= arr[i];
                i++;
            }
            if(sum == target){
                minInd = i+1;
                maxInd = j+1;
                break;
            }
            j++;
        }
        if(minInd == -1)        return {-1};
        return {minInd, maxInd};
    }
};