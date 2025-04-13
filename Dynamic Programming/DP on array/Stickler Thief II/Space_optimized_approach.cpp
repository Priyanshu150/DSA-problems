#include<bits/stdc++.h>
using namespace std;

//Time complexity :- O(n)
//Space complexity :- O(n)

// Approach :-
// since the array is circular the last element is adjacent to the first one 
// The answer will either have the last element or the first one in it configuration
// So we'll make two array where removing 1st element from one and last element from other
// we can use the same logic that we used in Stickler Thief I


//link :- https://www.geeksforgeeks.org/problems/house-robber-ii/1

class Solution {
  private:
    int findMaxSum(vector<int> arr) {
        // code here
        int n = arr.size(), ahead = 0, ahead1 = 0, curr;
        
        for(int ind=n-1; ind>=0; --ind){
            curr = max(ahead, arr[ind]+ahead1);
            ahead1 = ahead;
            ahead = curr;
        }
        return curr;
    }
  
  public:
    int maxValue(vector<int>& arr) {
        // your code here
        int n = arr.size();
        if(n == 1)      return arr[0];
        
        vector<int> temp1, temp2;
        for(int i=0; i<n; ++i){
            if(i != 0)      temp1.push_back(arr[i]);
            if(i != n-1)    temp2.push_back(arr[i]);
        }
        return max(findMaxSum(temp1), findMaxSum(temp2));
    }
};