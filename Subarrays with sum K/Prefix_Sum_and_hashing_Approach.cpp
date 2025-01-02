#include<bits/stdc++.h>
using namespace std;

//Time complexity :- O(N)
//Space complexity :- O(N)

//Note:- unordered_map take O(1) in searching 

class Solution {
  public:
    int countSubarrays(vector<int> &arr, int k) {
        // code here
        int n = arr.size(), res = 0, sum = 0;
        unordered_map<int,int> mp;
        mp[0] = 1;
        
        for(int i=0; i<n; ++i){
            sum += arr[i];                  //sum calculation
            int target = sum - k;           //find the subarray which will satisfy (a - b) = k, 
                                            //where a & b represend subarray sum until certian element

            if(mp.count(target))            //Finding the subarray b in the map and adding the previous
                res += mp[target];          // contibution of b in the array
            
            mp[sum] += 1;                   // updating the map with the sum
        }
        return res;
    }
};