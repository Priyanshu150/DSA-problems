import java.util.*

//Time complexity :- O(n*k)
//Space complexity :- O(1)

// Approach :- 
// check if the current number is 0, the flip the next k bit 
// flip until there are k bit on the right side of the current bit 
// and if rest all are 1 after flipping then it's possible, count the steps 


//Link :- https://www.geeksforgeeks.org/problems/minimum-number-of-k-consecutive-bit-flips--171650/1

class Solution {
    public int kBitFlips(int[] arr, int k) {
        int n = arr.length, res = 0;
        
        for(int i=0; i<n-k+1; ++i){
            if(arr[i] == 0){
                for(int j=i; j<(i+k); ++j){
                    arr[j] = 1^arr[j];
                }
                res += 1;
            }
        }
        
        for(int i=n-k+1; i<n; ++i){
            if(arr[i] == 0){
                return -1;
            }
        }
        return res;
    }
}