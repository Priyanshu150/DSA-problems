#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(n*log(n))
// Space complexity :- O(n)

// Approach :-  
// use a sliding window with left & right pointer 
// use hash map to track the freq of each digit 
// add the contribution of right ptr into the hash map
// once the count of distinct digit i.e. mp size increase by 2 
// then start removing the digit from left side until the size is less than 2 
// after that calculate the result for all the valid window having size less than 2 
// the length of the substring will be (right - left + 1), maintain a maximum length for the same 

// links :- https://www.geeksforgeeks.org/problems/fruit-into-baskets-1663137462/1

class Solution {
  public:
    int totalElements(vector<int> &arr) {
        // code here
        unordered_map<int,int> mp;
        int left = 0, n = arr.size(), res = 0;
        
        for(int right = 0; right<n; ++right){
            mp[arr[right]] += 1;
            
            while(mp.size() > 2){
                mp[arr[left]] -= 1;
                if(mp[arr[left]] == 0)
                    mp.erase(arr[left]);
                
                ++left;
            }
            res = max(res, right - left + 1);
        }
        return res;
    }
};