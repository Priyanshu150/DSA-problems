import java.util.*

// Time complextiy :- O(log(N))
// Space complexity :- O(1)


//Link :- https://www.geeksforgeeks.org/problems/count-total-set-bits-1587115620/1

class Solution {
    private int findMSB(int num){
        int count = 0;
        
        // count the total number of bits 
        while(num > 0){
            count++;
            num >>= 1;
        }
        return (count - 1);
    }
    
    
    public int countSetBits(int n) {
        if(n == 0 || n == 1)
            return n;
        
        // find the most significant bit 
        int msb = findMSB(n);
        // find the value associated using msb
        int val = (1 << msb);
        
        // count the number of set bit before val 
        int x = msb * (1 << (msb - 1));
        // count the set bit b/w val to n 
        int y = countSetBits(n - val);
        // msb bit in all the number count 
        int z = n-val+1;
        
        return x+y+z;
    }
}