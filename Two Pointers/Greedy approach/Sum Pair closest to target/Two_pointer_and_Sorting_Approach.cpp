#include<bits/stdc++.h>
using namespace std;

//Time complexity :- O(N)
//Space complexity :- O(1)

//Approach :- 
// Sort the array and apply two pointer based on 2-sum approach
// calulate the ans depending on the requirement

//Link :- https://www.geeksforgeeks.org/problems/pair-in-array-whose-sum-is-closest-to-x1124/1

class Solution {
  public:
    vector<int> sumClosest(vector<int>& arr, int target) {
        // code here
        int n = arr.size();
        if(n == 1)      return {};
        
        int i=0, j=n-1, prevDiff = INT_MAX;
        vector<int> ans(2, -1);
        sort(arr.begin(), arr.end());
        
        while(i < j){
            int sum = arr[i] + arr[j], diff = abs(target - sum);
            
            if(diff < prevDiff){
                ans[0] = arr[i], ans[1] = arr[j];
                prevDiff = diff;                
            }
            else if(diff == prevDiff && (arr[j] - arr[i]) > (ans[1] - ans[0]))
                ans[0] = arr[i], ans[1] = arr[j];
            if(sum > target)        j--;
            else        i++;
        }
        return ans;
    }
};