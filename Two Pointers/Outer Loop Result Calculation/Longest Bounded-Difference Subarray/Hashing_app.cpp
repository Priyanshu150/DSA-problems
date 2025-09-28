#include<bits/stdc++.h>
using namespace std;

//Time complexity :- O(N*log(N))
//Space complexity :- O(N)

// Approach :-
// Use sliding window approach, maximum window size at any point will be our answer 
// For storing element we can use multiset or ordered map
// Valid window will be different b/w largest element and smallest element is less than target given
// in set/map it will sorted in the increasing order hence we can directly access it with iterator (begin and rbegin)
// keep pushing the element until window is valid 
// elinate the element from left side until window is valid 
// calculate the result in out of the the loop

//link :- 
// gfg :- https://leetcode.com/problems/strange-printer/
// leetcode :- https://leetcode.com/problems/longest-continuous-subarray-with-absolute-diff-less-than-or-equal-to-limit/

class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int i = 0, j = 0, n = nums.size(), maxLen = 0;
        multiset<int> st;

        while(j<n){
            st.insert(nums[j]);
            int diff = *st.rbegin() - *st.begin();
            while(i<=j && diff > limit){
                auto it = st.find(nums[i]);
                st.erase(it);
                i++;
                diff = *st.rbegin() - *st.begin();
            }
            maxLen = max(maxLen, j-i+1);
            j++;
        }
        return maxLen;
    }
};


class Solution {
  private:
    bool isValid(map<int,int> &mp, int &target){
        int smallest = mp.begin() -> first;
        int largest = mp.rbegin() -> first;
        return (largest - smallest) <= target;
    }
  
  public:
    vector<int> longestSubarray(vector<int>& arr, int x) {
        // code here
        int n = arr.size(), left = 0;
        int len = 0, i = 0, j = 0;
        map<int,int> mp;
        
        for(int right=0; right<n; ++right){
            mp[arr[right]] += 1;
            
            while(!isValid(mp, x)){
                mp[arr[left]] -= 1;
                if(mp[arr[left]] == 0)
                    mp.erase(arr[left]);
                
                ++left;
            }
            if(len < (right - left + 1)){
                len = right - left + 1;
                i = left;
                j = right;
            }
        }
        vector<int> ans;
        
        for(int ind=i; ind<=j; ++ind)
            ans.push_back(arr[ind]);
        
        return ans;
    }
};