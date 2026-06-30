#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(n*log(n))
// Space complexity :- O(n)

// Approach :-  


//Link :- https://www.geeksforgeeks.org/problems/minimum-insertions-to-make-two-arrays-equal/1

class Solution {
  public:
    int minInsAndDel(vector<int> &a, vector<int> &b) {
        int n = a.size();
        int m = b.size();
        
        // store index of element in b 
        unordered_map<int,int> mp;
        
        for(int i=0; i<m; ++i){
            mp[b[i]] = i;
        }
        
        // store mapped indices 
        vector<int> v;
        
        // traverse array a 
        for(int x: a){
            // if element is present in b
            if(mp.count(x)){
                v.push_back(mp[x]);
            }
        }
        
        // store lis 
        vector<int> lis;
        
        // find LIS of mapped indices 
        for(int x: v){
            auto it = lower_bound(lis.begin(), lis.end(), x);
            
            // Insert element 
            if(it == lis.end()){
                lis.push_back(x);
            }
            // replace element 
            else{
                *it = x;
            }
        }
        // length of lis
        int len = lis.size();
        int res = (n - len) + (m - len);
        
        return res;
    }
};
