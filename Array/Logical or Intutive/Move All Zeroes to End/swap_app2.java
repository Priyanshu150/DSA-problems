import java.util.*;

//Time complexity :- O(n)
//Space complexity :- O(1)

// Approach :-
// keep count variable to pointing to the +ve number should be 
// whenever we find the +ve number we swap it with count index 
// and increment count to point to next index of valid +ve number 
// repeat this for all the element in the array and skip the zeros 

// Link :- https://www.geeksforgeeks.org/problems/move-all-zeroes-to-end-of-array0751/1

class Solution {
    void pushZerosToEnd(int[] arr) {
        // Pointer to track the position 
        // for next non-zero element
        int count = 0;
        
        for(int i=0; i<arr.length; ++i){
            // If the current element is non-zero
            if(arr[i] != 0){
                // Swap the current element with
                // the 0 at index 'count'
                int temp = arr[i];
                arr[i] = arr[count];
                arr[count] = temp;
                
                // Move 'count' pointer to 
                // the next position
                count++;
            }
        }
    }
}