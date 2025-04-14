#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int kthElement(vector<int>& a, vector<int>& b, int k) {
        // code here
        int ind1 = 0, ind2 = 0, n = a.size(), m = b.size(), ind = 0;
        //Traversing the both the array simultaneously 
        while(ind1 < n && ind2 < m){
            ind++;
            if(a[ind1] <= b[ind2]){
                if(ind == k)        return a[ind1];
                ind1++;
            }
            else{
                if(ind == k)        return b[ind2];
                ind2++;   
            }
        }
        //Second array traversal is completed and Travesing the rest from first
        while(ind1 < n){
            ind++;
            if(ind == k)        return a[ind1];
            ind1++;
        }
        //Traversing the rest element from second once completion of first array
        while(ind2 < m){
            ind++;
            if(ind == k)        return b[ind2];
            ind2++;
        }
        return -1;
    }
};