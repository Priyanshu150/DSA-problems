#include<bits/stdc++.h>
using namespace std;

//Time complexity :- O(n)
//Space complexity :- O(1)

// Approach :-
// for getting the element, we'll use moore voting algorithm
// maintain 2 variable ele and cnt, denoting element and their count a partiuclar instance of traversal
// while traversing the array, if cnt equals to 0, then assign ele to curr_num and cnt to 1
// else if ele is equal to curr_ele then increase the cnt by 1
// otherwise decrement the count by 1
// at last whatevery element we got after traversal cnt that element occurence in array 
// verify if that answer else if not then return -1


//link :- https://www.geeksforgeeks.org/problems/majority-element-1587115620/1

class Solution {
  public:
    int majorityElement(vector<int>& arr) {
        // code here
        int n = arr.size(), ele = -1, cnt = 0;
        
        for(int i=0; i<n; ++i){
            if(cnt == 0){
                ele = arr[i];
                cnt = 1;
            }
            else if(arr[i] == ele)
                cnt++;
            else
                cnt--;
        }
        cnt = 0;
        
        for(int i=0; i<n; ++i){
            if(arr[i] == ele)
                cnt++;
        }
        return (cnt > n/2) ? ele : -1;
    }
};