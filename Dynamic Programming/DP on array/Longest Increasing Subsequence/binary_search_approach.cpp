#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(n*log(n))
// Space complexity :- O(n)

// Approach :- 
// We'll maintain an temp vector that will contain value in increasing order from arr
// We'll traversing from left to right, if the number coming in is greater than number at the end of temp
// then we will push_back that number in temp
// otherwise we'll find the number the ind where the current_number can be using lower_bound and put that number in that ind
// In this way we can get the increasing subsequence and return temp.size() as answer

//Link :- https://www.geeksforgeeks.org/problems/longest-increasing-subsequence-1587115620/1


class Solution {
  public:
    int lis(vector<int>& arr) {
        // code here
        int n = arr.size();
        vector<int> temp;
        temp.push_back(arr[0]);
        
        for(int i=1; i<n; ++i){
            int num = arr[i];
            if(!temp.empty() && temp.back() < num)
                temp.push_back(num);
            else{
                int ind = lower_bound(temp.begin(), temp.end(), num) - temp.begin();
                temp[ind] = num;
            }
        }
        return temp.size();
    }
};