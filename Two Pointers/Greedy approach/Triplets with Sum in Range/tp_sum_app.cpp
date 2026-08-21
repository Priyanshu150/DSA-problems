#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(n*log(n))
// Space complexity :- O(1)

// Approach :-  
// For a target find the number of triplet sum less or equal to it.
// then subtract two triplet sum which has target as r and l-1
// for find the triplet sum fix one of the point
// and for rest of the two use meet in the middle technique to count total subarray



// links :- https://www.geeksforgeeks.org/problems/triplets-with-sum-with-given-range/1

class Solution {
  private:
    int countSumLessOrEqual(vector<int> arr, int target, int &n){
        int res = 0;
        sort(arr.begin(), arr.end());       // sort the array
        
        for(int i=0; i<n-2; ++i){
            // Initialize other two elements as
            // corner elements of subarray arr[j+1..k]
            int st = i+1;
            int end = n-1;
            
            // Use Meet in the Middle concept.
            while(st < end){
                int sum = arr[i] + arr[st] + arr[end];  // sum of the triplet 
                
                // If sum of current triplet
                // is greater, then to reduce it
                // decrease k.
                if(sum > target){
                    end--;
                }
                // If sum is less than or equal
                // to given value, then add
                // possible triplets (k-j) to result.
                else{
                    res += (end - st);
                    st++;
                }
            }
        }
        return res;
    }
  
  public:
    int countTriplets(vector<int> &arr, int l, int r) {
        int n = arr.size();
        // Find count of triplets having sum less than or equal to r 
        // and subtract 
        // count of triplets having sum less than orequal to l-1.
        return countSumLessOrEqual(arr, r, n) - countSumLessOrEqual(arr, l-1, n);
    }
};