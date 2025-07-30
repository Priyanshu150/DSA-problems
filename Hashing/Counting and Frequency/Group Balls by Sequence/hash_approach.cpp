#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(n*log(n))
// Space complexity :- O(n)

// Approach :- 
// sort the array and count the frequency of each element 
// Traverse on the sorted array 
// if the frequency of that element is greater that 0, then find the next k consecutive after current element 
// if it's doesn't exist then it can be divided return false
// if we find the consecutive element then decrease the contribution of that element in the map

// Link :- https://www.geeksforgeeks.org/problems/group-balls-by-sequence/1


class Solution {
  public:
    bool validgroup(vector<int> &arr, int k) {
        // code here
        int n = arr.size();
        sort(arr.begin(), arr.end());
        unordered_map<int, int> mp;
        
        for(int i=0; i<n; ++i)
            mp[arr[i]]++;
        
        for(int i=0; i<n; ++i){
            int val = arr[i];
            while(mp[val] > 0){
                mp[val]--;
                for(int j=1; j<k; ++j){
                    if(mp[val + j] == 0)
                        return false;
                    else
                        mp[val+j]--;
                }
            }
        }
        return true;
    }
};