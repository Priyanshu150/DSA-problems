#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(n*log(max(arr)))
// Space complexity :- O(1)

// Approach :- 
// the answer will always lie b/w min element and max element of the array 
// hence we can apply binary search on the range 
// for a particular day i.e mid we've check wheather it's possible to create m boquet or not 
// if it's possible then we've to decrease over answer i.e low = mid+1 
// otherwise increase our answer i.e. high = mid-1
// to check wehather it's possible or not to make m bouquets with given days 
// we've to count the number of adjacent flower and using that we can make m bouquets or not 
// if we're able to make more than m bouquets then it's possible otherwise it's not 

// Link :- https://leetcode.com/problems/minimize-the-maximum-difference-of-pairs/

class Solution {
  private:
    bool isPossible(int days, vector<int> &arr, int &k, int &m, int &n){
        int flowers = 0, bouquet = 0;
        
        for(int i=0; i<n; ++i){
            if(arr[i] <= days){
                flowers++;
            }
            else    flowers = 0;
            
            if(flowers == k){
                bouquet++;
                flowers = 0;
            }
        }
        return (m <= bouquet);
    }
  
  public:
    int minDaysBloom(vector<int>& arr, int k, int m) {
        // Code here
        int n = arr.size(), res = -1;
        if(k*m > n)     return res;
        
        int low = *min_element(arr.begin(), arr.end());
        int high = *max_element(arr.begin(), arr.end());
        
        while(low <= high){
            int mid = low + (high - low)/2;
            if(isPossible(mid, arr, k, m, n)){
                res = mid; 
                high = mid-1;
            }
            else    low =  mid+1;
        }
        return res;
    }
};
