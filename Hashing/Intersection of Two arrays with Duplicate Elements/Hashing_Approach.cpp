#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> intersectionWithDuplicates(vector<int>& a, vector<int>& b) {
        // code here
        vector<int> ans;
        unordered_set<int> st(a.begin(), a.end());
        
        for(auto num: b){
            if(st.count(num)){
                ans.push_back(num);
                st.erase(num);
            }
        }
        return ans;
    }
};