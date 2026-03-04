import java.util.*

// Time complexity :- O(n)
// Space complexity :- O(32)

// Approach :-
// generate all sequence of the string and find the kth char of that string 


// Link :- https://www.geeksforgeeks.org/problems/max-xor-subarray-of-size-k/1

class Solution {
    private void updateContri(int[] bits, int num, int contri) {
        // For every 32 bits
        for (int bit = 0; bit < 32; ++bit) {
            // Check if the bit is set
            if ((num & (1 << bit)) != 0) {
                // Update contribution of current bit
                bits[bit] += contri;
            }
        }
    }
    
    private int findValue(int[] bits) {
        int num = 0;
        
        // For every 32 bits
        for (int bit = 0; bit < 32; ++bit) {
            // Current bit has odd contribution
            if (bits[bit] % 2 != 0) {
                // XOR result will have that bit set
                num |= (1 << bit);
            }
        }
        return num;
    }
    
    public int maxSubarrayXOR(int[] arr, int k) {
        int n = arr.length, left = 0, res = 0;
        int[] bits = new int[32];  // ✅ int[] instead of vector
        
        // Sliding window of length k
        for (int right = 0; right < n; ++right) {
            // Add current number's contribution
            updateContri(bits, arr[right], 1);
            
            if ((right - left + 1) == k) {
                // Find XOR of current window, update max
                res = Math.max(res, findValue(bits));
                // Remove left element's contribution
                updateContri(bits, arr[left], -1);
                left++;
            }
        }
        return res;
    }
}
