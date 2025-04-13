#include<bits/stdc++.h>
using namespace std;

class Solution {
  private:
    int countStudents(vector<int> &arr, int page, int &n){
        int students = 1, pageAllocated = 0;
        
        for(int i=0; i<n; ++i){
            if(arr[i] + pageAllocated <= page)
                pageAllocated += arr[i];
            else{
                students++;
                pageAllocated = arr[i];
            }
        }
        return students;
    }
  
  public:
    int findPages(vector<int> &arr, int k) {
        // code here
        int n = arr.size();
        if(k > n)       return -1;
        
        int low = *max_element(arr.begin(), arr.end());
        int high = accumulate(arr.begin(), arr.end(), 0);
        
        while(low <= high){
            int mid = low + (high - low)/2;
            int students = countStudents(arr, mid, n);
            if(students > k)    low = mid+1;
            else        high = mid-1;
        }
        return low;
    }
};