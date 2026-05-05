import java.util.*

// Time complexity :- O(n)
// Space complexity :- O(1)

// Approach :-  
// for each 32 bits, we can count the number of ones and zeros present on each number 
// all the pair will be b/w these 0 & 1 i.e (count of zeros) * (count of ones)
// and final contribution of that bit will be (total_count) * (bit_decimal_value)

// Links :- https://www.geeksforgeeks.org/problems/sum-of-xor-of-all-pairs0723/1

class Solution {
    public long sumXOR(int[] arr) {
        long sum = 0;
        int len = arr.length;
        
        // for each 32 bits 
        for(int bit=0; bit<32; ++bit){
            long cntOnes = 0, cntZeros = 0;
            
            // count the number of zeros and one 
            for(int i=0; i<len; ++i){
                if((arr[i] & (1 << bit)) != 0){
                    cntOnes += 1;
                }else{
                    cntZeros += 1;
                }
            }
            // total pair will be all the ones with all the zeros 
            // i.e. (cntOnes * cntZeros)
            // total pair * contribution of that number will be answer for current bit 
            sum += (cntOnes * cntZeros) * (1 << bit);
        }
        return sum;
    }
}