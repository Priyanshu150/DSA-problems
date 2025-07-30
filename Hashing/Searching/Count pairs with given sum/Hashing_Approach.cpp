#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int countPairs(vector<int> &arr, int target) {
        // Code here
        unordered_map<int,int> mp;
        
        for(auto num: arr)
            mp[num] += 1;
        
        int res = 0;
        for(auto num: arr){
            int toFind = target - num;
            if(mp.count(toFind)){
                if(toFind == num)
                    res += (mp[toFind] -1);
                else
                    res += mp[toFind];
            }
            mp[num] -= 1;
            if(mp[num] == 0)
                mp.erase(num);
        }
        return res;
    }
};