#include<bits/stdc++.h>
using namespace std;

//Time complexity :- O(N)       //where n is the size of array of numbers
//Space complexity :- O(N)      // using map to store every combination of sum

//Note:- unordered_map take O(1) in searching 

// Approach :-
// For finding a subarray with sum k we can use hashing approach
// sliding window will not work because the array doesn't represents increasing or decreasing nature
// two subbarray can contribute to have sum equal to subbarray sum till current index
// i.e. sub_array_till_ind_i(a) + sub_array_till_ind_j(b) = sub_array_till_curr_ind
// i.e. a + k = curr_sum   => a = curr_sum - k, where a repsents any valid subarray sum till prev index
// hence we'll use a map to store the sum and their respective count 
// traversing on the array we'll calucalte the sum and target needed to complete the subbarray sum eqaul to k
// if we find such target in our map we'll include that count and add current sum to map

// link :- https://www.geeksforgeeks.org/problems/subarrays-with-sum-k/1

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