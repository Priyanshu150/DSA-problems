#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(n)
// Space complexity :- O(n)

// Approach :-  
// use a sliding window to track a valid subarray 
// for counting distinct element in the windown we can use hashing 
// start moving the right pointer to the end of the array and add the contribution of that number 
// if the number is occuring first time then it will be a distinct integer maintain it in a variable
// until the distinct count is greater than k, then remove contribution from left_ptr 
// if the number count in hashing decrease to 0 that means that number doesn't exist in window
// find add the length of the valid window to the result
// length of window because if a new number comes in then the number of valid subarray it will form
// will be equal to length of the valid string i.e. add current number to last of all subarray 
// and the number itself, ex [1, 2] adding 1 to it will gives us 3 more sub-array [1,2,1]


// links :- https://www.geeksforgeeks.org/problems/subarrays-with-at-most-k-distinct-integers/1

class Solution {
  public:
    int countAtMostK(vector<int> &arr, int k) {
        // code here
        unordered_map<int,int> mp;
        int n = arr.size(), distinct = 0, res = 0, left = 0;
        
        for(int right=0; right<n; ++right){
            mp[arr[right]] += 1;
            if(mp[arr[right]] == 1)
                distinct++;
            
            while(distinct > k){
                mp[arr[left]] -= 1;
                if(mp[arr[left]] == 0) 
                    --distinct;
                
                ++left;
            }
            res += (right - left + 1);
        }
        return res;
    }
};