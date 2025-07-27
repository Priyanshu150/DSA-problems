#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(n)  
// Space complexity :- O(n)

// Approach :- 
// remove all the duplicate char and keep all the distinct ones into an array
// traverse on the array for 1 to size-1 index and check if any element satisfies the condition 
// either for hill or valley, count all such cases as answer

// Link :- https://leetcode.com/problems/count-hills-and-valleys-in-an-array/

class Solution {
public:
    int countHillValley(vector<int>& arr) {
        int n = arr.size(), sz = 1, res = 0;
        vector<int> temp;
        temp.push_back(arr[0]);

        for(int i=1; i<n; ++i){
            if(temp.back() != arr[i]){
                sz++;
                temp.push_back(arr[i]);
            }
        }
        
        for(int i=1; i<sz-1; ++i){
            if((temp[i] > temp[i-1] && temp[i] > temp[i+1]) || (temp[i] < temp[i-1] && temp[i] < temp[i+1]))
                res++;
        }
        return res;
    }
};