#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(n^2 + n*log(n))
// Space complexity :- O(1)

// Approach :-  
// sort the array, and fixed one side of triangle 
// using 2 point start from extreme left and right end find the valid sum which is greater that fixed side
// if any valid sum found then that means all the number in b/w those are valid to form a triangle 
// add the contribution (right - left + 1) to our answer 
// and move to find next by decrementing the pointer pointing to the largest side 
// otherwise until valid sum is not found then increase the other pointer 


// Link :- https://www.geeksforgeeks.org/problems/count-possible-triangles-1587115620/1

class Solution {
  public:
    int countTriangles(vector<int>& arr) {
        // code here
        int n = arr.size(), res = 0;
        sort(arr.begin(), arr.end());
        
        for(int c=n-1; c>=2; --c){
            int a = 0, b = c-1;
            while(a < b){
                int sum = arr[a] + arr[b];
                if(sum > arr[c]){
                    res += (b - a);
                    b--;
                }
                else    a++;
            }
        }
        return res;
    }
};
