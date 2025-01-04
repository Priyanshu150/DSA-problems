#include<bits/stdc++.h>
using namespace std;

//Time complexity :- O(N^2)       
//Space complexity :- O(1)    

//Approach :-
// Fix a point 'i' and apply two pointer 
// if sum of 3 index is equal to target then find ocuurence of left and right index 
// if left != right then (c1 * (c1-1))/2
// else (c1*c2)

class Solution {
  public:
    int countTriplets(vector<int> &arr, int target) {
        // Code Here
        int n = arr.size(), res = 0;
        
        for(int i=0; i<n-2; ++i){
            int j = i+1, k = n-1;
            
            while(j < k){
                int sum = arr[i] + arr[j] + arr[k];
                
                if(sum == target){
                    //store the value of left and right and make cnt ptr
                    int ele1 = arr[j], c1 = 0, ele2 = arr[k], c2 = 0;
                    
                    //cnt same ele from left
                    while(j<=k && arr[j] == ele1){
                        c1++;
                        j++;
                    }
                    //similarly for right
                    while(j<=k && arr[k] == ele2){
                        c2++;
                        k--;
                    }
                    //cal final res
                    res += (ele1 == ele2) ? (c1*(c1-1))/2 : (c1 * c2);
                }
                else if(sum < target)  j++;
                else    k--;
            }
        }
        return res;
    }
};