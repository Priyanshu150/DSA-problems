#include<bits/stdc++.h>
using namespace std;

//Time complexity :- O( (N+M)log(N+M) )
//Space complexity :- O(1)

//Approach :- 
// Gap method describes a way to created gap b/w left and right index and swapping them
// if right element is smaller than left one 
// Initaially the gap is defined as ceil value of (n+m)/2, where n & m are length of 2 array
// And diving gap by 2 and take ceil value after every iteration 

//Links :- https://www.interviewbit.com/problems/merge-two-sorted-lists-ii/

class Solution {
  private:
    void check(vector<int>&a, vector<int>&b, int ind1, int ind2){
        if(a[ind1] > b[ind2])
            swap(a[ind1], b[ind2]);
    }
  
  public:
    void mergeArrays(vector<int>& a, vector<int>& b) {
        // code here
        int n = a.size(), m = b.size(), len = n+m;
        int gap = (len)/2 + len%2;
        
        while(gap > 0){
            int left = 0, right = left + gap;
            while(right < len){
                if(left < n && right >=n)
                    check(a, b, left, right-n);
                else if(left >= n)
                    check(b, b, left-n, right-n);
                else
                    check(a, a, left, right);
                
                left++;
                right++;
            }
            if(gap == 1)    break;
            gap = (gap/2) + (gap%2);
        }
    }
};