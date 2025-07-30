#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    bool twoSum(vector<int>& arr, int target) {
        // code here
        int n = arr.size();
        unordered_map<int,int> mp;
        
        for(int i=0; i<n; ++i)
            mp[arr[i]] = i;
        
        for(int i=0; i<n; ++i){
            int toFind = target - arr[i];
            if(mp.count(toFind) && mp[toFind] != i)
                return true;
        }
        return false;
    }
};