#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int kthMissing(vector<int> &arr, int k) {
        // Your code goes here
        int num = 1, missing = 0, ind = 0, n = arr.size();
        
        while(true){
            if(ind < n && num == arr[ind])
                ind++;
            else    missing++;
            
            if(missing == k)
                return num;
            
            ++num;
        }
        return -1;
    }
};