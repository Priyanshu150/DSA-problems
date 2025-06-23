#include<bits/stdc++.h>
using namespace std;

//Time complexity :- O(min(N,M) + N*log(N) + M*log(M) )
//Space complexity :- O(1)

//Approach :- 
// Point index at last ele1 of arr1 and first ele2 of arr2 
// swap if (ele1 < ele2)
// finally sort both the array

//Links :- https://www.interviewbit.com/problems/merge-two-sorted-lists-ii/

class Solution {
  public:
    void mergeArrays(vector<int>& a, vector<int>& b) {
        // code here
        int n = a.size(), m = b.size(), ind1 = n-1, ind2 = 0;
        
        while(ind1 >=0 && ind2<m){
            if(b[ind2] < a[ind1]){
                int temp = a[ind1];
                a[ind1] = b[ind2];
                b[ind2] = temp;
            }
            else    break;
            ind1--;
            ind2++;
        }
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
    }
};