#include<bits/stdc++.h>
using namespace std;

//Time complexity :- O(n*log(n))
//Space complexity :- O(1)

// why n*log(n) is better than n*32 ??
// because the size of array is 1e5, and at 2^20 will suffice stroing that many number 
// log(n) for 2^20 will be 20 and the tc will be (n*20)

// Approach :-
// sort the array, and start traversing from index 1 and move 3 place every time
// if ind and ind-1 doesn't match that means arr[ind-1]  is number appering once
// the logic is that if the number doesn't follow the order then it is guaranted that someone appear in middle
// our logic will work if every case except when the number we're finding is present at the last index
// for handling that if we didn't find a violation while traversing we'll return last element of array


//link :- https://www.geeksforgeeks.org/problems/find-element-occuring-once-when-all-other-are-present-thrice/1

class Solution {
  public:
    int getSingle(vector<int> &arr) {
        // code here
        int n = arr.size();
        sort(arr.begin(), arr.end());
        
        for(int i=1; i<n; i+=3){
            if(arr[i] != arr[i-1])
                return arr[i-1];
        }
        return arr[n-1];
    }
};