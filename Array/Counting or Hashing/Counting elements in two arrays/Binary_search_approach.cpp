#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(n + m*log(m))  
// Space complexity :- O(1)

// Approach :-  
// sort the element of array 2 
// for every element in array1 find the count of the element less than
// and equal to current element using binary search 


// Link :- https://www.geeksforgeeks.org/problems/counting-elements-in-two-arrays/1

class Solution{
  public:
    int binary_search(int arr2[], int n, int key){
        int l = 0, h = n-1;
        
        while(l <= h){
            int mid = (l+h) >> 1;
            if(arr2[mid] <= key)    l = mid+1;
            else                    h = mid-1;
        }
        
        return l;
    }
  
    vector<int> countEleLessThanOrEqual(int arr1[], int arr2[],int m, int n)
    {
        vector<int> ans;
        sort(arr2, arr2+n);
        
        for(int i=0; i<m; i++){
            ans.push_back(binary_search(arr2,n,arr1[i]));
        }
        
        return ans;
    }
};


class Solution{
  public:
    vector<int> countEleLessThanOrEqual(int arr1[], int arr2[],int m, int n){
        vector<int> ans;
        sort(arr2, arr2+n);
        
        for(int i=0; i<m; i++){
            int num = upper_bound(arr2, arr2+n, arr1[i]) - arr2;
            ans.push_back(num);
        }
        
        return ans;
    }
};
