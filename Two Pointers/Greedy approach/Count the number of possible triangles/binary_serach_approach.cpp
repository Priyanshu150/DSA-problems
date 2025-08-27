#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(n*log(n) + n*n*log(n))
// Space complexity :- O(1)

// Approach :-  
// If we fix two side of triangle we only need to find the third one 
// which can be done using binary search 
// hence we'll find the sum of 2 sides and find all the side which have value less than sum 
// simarly repeating for every other sides 
// sort the array to apply binary search on it 


// Link :- https://www.geeksforgeeks.org/problems/count-possible-triangles-1587115620/1

class Solution {
  private:
    int bs(int ind, int target, int &n, vector<int> &arr){
        int low = ind, high = n-1, res = n;
        
        while(low <= high){
            int mid = low + (high - low)/2;
            if(arr[mid] >= target){
                res = mid;
                high = mid-1;
            }
            else    low = mid+1;
        }
        return res;
    }
    
  public:
    int countTriangles(vector<int>& arr) {
        // code here
        int res = 0, n = arr.size();
        sort(arr.begin(), arr.end());
        
        for(int a=0; a<n-2; ++a){
            for(int b=a+1; b<n-1; ++b){
                int sum = arr[a] + arr[b];
                int ind = bs(b+1, sum, n, arr);
                res += (ind - b - 1);
            }
        }
        return res;
    }
};