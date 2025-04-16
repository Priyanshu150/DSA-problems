#include<bits/stdc++.h>
using namespace std;

//Time complexity :- O(N)       
//Space complexity :- O(N)    

//Approach :-
// Create a sliding window and count the distinct element within them

class Solution {
  public:
    vector<int> countDistinct(vector<int> &arr, int k) {
        // code here.
        int n = arr.size(), i(0), j(0), sz(0);
        vector<int> ans;
        unordered_map<int,int> mp;
        
        for(; i<k; ++i){
            mp[arr[i]] += 1;
            if(mp[arr[i]] == 1)         sz++;
        }   
        while(i < n){
            ans.push_back(sz);
            
            mp[arr[i]] += 1;
            if(mp[arr[i]] == 1)         sz++;
            
            mp[arr[j]] -= 1;
            if(mp[arr[j]] == 0)         sz--;
            
            i++;
            j++;
        }
        ans.push_back(sz);
        return ans;
    }
};