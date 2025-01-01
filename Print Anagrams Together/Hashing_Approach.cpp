#include<bits/stdc++.h>
using namespace std;

//Assumption :- 
// Size of Array -> N
// Size of each word -> M


//Time Complexity :- O[N*(M*log(M) + O(1)) + O(N) + O(N*log(N))]
//Space Complexity :- O(N*N)

class Solution {
  public:
    vector<vector<string>> anagrams(vector<string>& arr) {
        // code here
        vector<vector<string>> ans;
        unordered_map<string, vector<string>> mp;
        
        for(auto word: arr){
            string dup = word;
            sort(dup.begin(), dup.end());
            mp[dup].push_back(word);
        }
        for(auto it: mp)
            ans.push_back(it.second);
            
        sort(ans.begin(), ans.end());
        return ans;
    }
};