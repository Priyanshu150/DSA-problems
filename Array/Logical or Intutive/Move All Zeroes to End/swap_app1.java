import java.util.*;

//Time complexity :- O(n)
//Space complexity :- O(1)

// Approach :-
// find the next index which is pointing to zero 
// whenever we find an element which is not zeros we swap it with previous zeroInd
// repeat the process until we reach the last element 

// Link :- https://www.geeksforgeeks.org/problems/move-all-zeroes-to-end-of-array0751/1

class Solution {
    private void swap(int[] arr, int i, int j){
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
    
    void pushZerosToEnd(int[] arr) {
        int zeroInd = 0, n = arr.length;
        
        // find the first index pointing to zero 
        while(zeroInd < n){
            if(arr[zeroInd] == 0)
                break; 
            
            ++zeroInd;
        }
        // no 0's are present in the array 
        if(zeroInd == n-1)
            return;
        
        for(int i=0; i<n; ++i){
            // swap when 0 is present on the left side of +ve number 
            if(arr[i] > 0 && zeroInd < i){
                swap(arr, i, zeroInd);
                // find next index of 0
                 while(zeroInd < n){
                    if(arr[zeroInd] == 0)
                        break; 
                    
                    ++zeroInd;
                }
                // no 0's are present in the array after that 
                if(zeroInd == n-1)
                    return;
            }
        }
    }
}