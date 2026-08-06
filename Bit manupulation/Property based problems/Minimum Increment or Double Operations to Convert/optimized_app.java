import java.util.*

// Time complextiy :- O(n)
// Space complexity :- O(1)

// Approach :-   
// we'll follow the reverse order, start from the array we'll try to make all the values as 0
// if any of the number is odd then we'll decrement it by 1 
// and in next operation we'll divide the number by 2 until they becomes 1 or 0
// the total number operation in the process will be our answer 
// we can use bit manupulation technique to further optimize this one 
// for all the subtraction operation of 1, we'll count the number of set bits in all the number 
// and for division the maximum number of shift needed for largest number will be operation needed for that 
// summation of both operation wil be our answer 

// Link :- https://www.geeksforgeeks.org/problems/minimum-steps-to-get-desired-array5519/1

class Solution {
    // count the number of set bits in number 
    private int countSetBits(int num){
        int count = 0;
        
        while(num > 0){
            // check if the bit is set or not 
            if((num & 1) == 1)
                count++;
            // half the value 
            num >>= 1;
        }
        return count;
    }
    
    public int countMinOperations(int arr[]) {
        int n = arr.length;
        int maxVal = Integer.MIN_VALUE;
        int totalBits = 0;
        
        for(int i=0; i<n; ++i){
            // count total number of bit present in the array
            totalBits += countSetBits(arr[i]);
            // max value among all in array 
            maxVal = Math.max(maxVal, arr[i]);
        }
        int halfOpn = 0;
        // number of division operation we've to do for largest number 
        while(maxVal > 1){
            halfOpn += 1;
            maxVal >>= 1;
        }
        return totalBits + halfOpn;
    }
}