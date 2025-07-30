#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    // Function to find the minimum number of swaps required to sort the array.
    int minSwaps(vector<int>& values) {
        // Code here
        int n = values.size(), cnt = 0;
        vector<int> sorted = values;
        //sorting the array
        sort(sorted.begin(), sorted.end());

        unordered_map<int,int> mp;
        //mapping the values
        for(int i=0; i<n; ++i)
            mp[values[i]] = i;

        for(int i=0; i<n; ++i){
            //Checking for the values 
            if(values[i] != sorted[i]){
                // If not same check for the which should be at originial pos and swap
                int pos = mp[sorted[i]];
                swap(values[i], values[pos]);
                mp[values[i]] = i;
                mp[values[pos]] = pos;
                cnt++;
            }
        }
        return cnt;
    }
};