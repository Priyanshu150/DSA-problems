#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    bool twoSum(vector<int>& arr, int target) {
        // code here
        sort(arr.begin(), arr.end());
        int st = 0, end = arr.size()-1;
        
        while(st < end){
            int sum = arr[st] + arr[end];
            if(sum == target)
                return true;
            else if(sum < target)
                st++;
            else
                end--;
        }
        return false;
    }
};