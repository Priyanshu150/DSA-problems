#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(N*log(max_ele))
// Space complexity :- O(1)

// Approach :-  
// use a binary search on answer approach to find the answer
// the lowest banana per hour will 1 and highest will be maximum element of array 
// becasue at minimum the 1 banana can be eaten and maximum banana from a pile can be eaten 
// apply binary search on the range 
// traverse in the pile of bananase and check for the a particular time
// wheather it'll be possible to complete within given hour


// Link :- https://www.geeksforgeeks.org/problems/koko-eating-bananas/1

class Solution {
  private:
    bool isPossible(int s, vector<int> &arr, int &k){
        int n = arr.size(), timeTaken = 0;
        
        // traverse on each banana pile 
        for(int i=0; i<n; ++i){
            // eat atleast k banana from the pile as many times as possible 
            timeTaken += (arr[i] / s);
            // eat all the left bananas 
            timeTaken += (arr[i] % s) > 0 ? 1 : 0;
            
            // current time exceed the k limit then it's not possible 
            if(timeTaken > k)
                return false;
        }
        return true;
    }
  
  public:
    int kokoEat(vector<int>& arr, int k) {
        int low = 1, res = -1;
        // find maximum value of array 
        int high = *max_element(arr.begin(), arr.end());
        
        // standard bs on ans
        while(low <= high){
            int mid = low + (high - low)/2;
            
            // check with current mid value it's possible to eat all bananas under k hours
            if(isPossible(mid, arr, k)){
                res = mid;
                high = mid-1;       // try to decrease the answer more 
            }
            else{
                // otherwise increase the answer to find a valid answer
                low = mid+1;
            }
        }
        return res;
    }
};