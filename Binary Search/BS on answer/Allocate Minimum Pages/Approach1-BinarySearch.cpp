#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(n*log(n))
// Space complexity :- O(1)

// Approach :-  
// In whichever way we allocate the page of book to the students
//  the answer will always lie in b/w max(arr) to sum(arr)
// hence we can apply binary search on the range 
// We can use custom function to decide wheather we've to increase low or decrease high
// for any limited number of pages, initailly we start allocating pages to 1 student 
// moving left to right, we'll allocate the pages untill limit is reached for that student 
// and then allocated next set of pages to other students and repeat the process 
// if at any point the number of students > k then it's not possible return false 
// otherwise after allocating all the pages return true, stating it's possible 


//Link :- https://www.geeksforgeeks.org/problems/allocate-minimum-number-of-pages0937/1

class Solution {
  private:
    bool isPossible(int limit, vector<int> &arr, int &k, int &n){
        int pages = 0, students = 1;
        
        for(int i=0; i<n; ++i){
            if(pages + arr[i] <= limit){
                pages += arr[i];
            }
            else{
                students++;
                pages = arr[i];
            }
            
            if(students > k)
                return false;
        }
        return true;
    }
  
  public:
    int findPages(vector<int> &arr, int k) {
        // code here
        int n = arr.size();
        if(k > n)       return -1;
        
        int low = 0, high = 0, res = 0;
        for(int i=0; i<n; ++i){
            low = max(low, arr[i]);
            high += arr[i];
        }
        if(k == n)      return low;
        
        while(low <= high){
            int mid = low + (high - low)/2;
            if(isPossible(mid, arr, k, n)){
                res = mid;
                high = mid-1;
            }
            else    low = mid+1;
        }
        return res;
    }
};