#include<bits/stdc++.h>
using namespace std;

//Time complexity :- O(log(n))
//Space complexity :- O(n)

// Approach :-  
// Form a array which is in the format {element, index} and sort them
// traverse on this array (left to right) and form the answer array
// also maintain a index all the previous values 
// for a given index if the maxIndex was on the right of that index then that's our answer 
// otherwise there is no one answer for this element hence -1
// since the array is sorted all the number occuring before current index will already be less than curr_number



//link :- https://www.geeksforgeeks.org/problems/farthest-smaller-right/1

class Solution {
  public:
    vector<int> farMin(vector<int>& arr) {
        // code here
        int n = arr.size();
        vector<pair<int,int>> temp;
        
        for(int i=0; i<n; ++i)
            temp.push_back({arr[i], i});
        
        sort(temp.begin(), temp.end());
        int max_ind = -1;
        vector<int> ans(n, -1);
        
        for(int i=0; i<n; ++i){
            int ele = temp[i].first, ind = temp[i].second;
            
            if(max_ind > ind)
                ans[ind] = max_ind;
            
            max_ind = max(max_ind, ind);
        }
        return ans;
    }
};