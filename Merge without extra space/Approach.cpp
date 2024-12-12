#include<bits/stdc++.h>
using namespace std;

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