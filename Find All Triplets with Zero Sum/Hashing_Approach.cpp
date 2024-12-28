#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<vector<int>> findTriplets(vector<int> &arr) {
        // Code here
        int n = arr.size();
        vector<vector<int>> ans;
        map<int,vector<int>> mp;
        mp[arr[n-1]].push_back(n-1);
        
        for(int i=n-2; i>=0; --i){
            for(int j=i-1; j>=0; --j){
                int target = -1*(arr[i] + arr[j]);
                if(mp.count(target)){
                    for(auto ind: mp[target])
                        ans.push_back({j, i, ind});
                }
            }
            mp[arr[i]].push_back(i);
        }   
        return ans;
    }
};  