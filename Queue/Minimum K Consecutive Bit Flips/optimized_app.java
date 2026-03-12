import java.util.*

//Time complexity :- O(n)
//Space complexity :- O(n)

// Approach :- 
// we can keep track of number of time bit flip 
// if the current flip count is odd then the value should be 1 
// or if it's even then the current value should be 0
// we'll maintain a bool array to check where we flipped the bit  
// that help us to the track the validity of each flip till which index it's should bit flip
// i-k bit is flip then remove decrement the flip count 


//Link :- https://www.geeksforgeeks.org/problems/minimum-number-of-k-consecutive-bit-flips--171650/1

class Solution {
    public int kBitFlips(int[] arr, int k) {
        int n = arr.length;
        int flipped = 0, res = 0;
        boolean[] isFlipped = new boolean[n];
        
        for(int i=0; i<n; ++i){
            // validity of previous flip is expired 
            if(i-k >=0 && isFlipped[i-k] == true){
                flipped--;
            }
            // flip is needed 
            if(arr[i] == (flipped % 2)){
                // if index does not have sufficient next bit then it's not possible 
                if(i+k > n){
                    return -1;
                }
                // add the condition to flips 
                res += 1;
                flipped++;
                isFlipped[i] = true;
            }
        }
        return res;
    }
}
