#include <bits/stdc++.h>
using namespace std;

// Time Complexity :- O(n*log(n))
// Space Complexity :- O(1)

// Approach :- 
// 

// Code : - 

class Solution {
  private:
    int countBits(int n){
        int cnt = 0;
        
        while(n > 0){
            cnt += (n & 1);
            n = n >> 1;
        }
        return cnt;
    }
  
  public:
    vector<int> sortBySetBitCount(vector<int>& arr) {
        // custom comparator sorting 
        auto comp = [&](int a, int b){
            int cnt1 = countBits(a);
            int cnt2 = countBits(b);
            
            return cnt1 > cnt2;
        };
        // stable sort preserves order 
        stable_sort(arr.begin(), arr.end(), comp);
        return arr;
    }
};