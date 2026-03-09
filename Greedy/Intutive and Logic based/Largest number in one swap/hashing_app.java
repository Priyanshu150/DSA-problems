import java.util.*

//Time complexity :- O(n)
//Space complexity :- O(1)

// Approach :- 
// for every number store the last index at which it's appearing 
// travese from left to right, find the first number whose greater number is present on left side 
// if the condition satisfies swap it one time

//Link :- https://www.geeksforgeeks.org/problems/largest-number-in-one-swap1520/1

class Solution {
    public String largestSwap(String s) {
        int n = s.length();
        int[] lastInd = new int[10];
        Arrays.fill(lastInd, -1);  // Initialize
        
        // Track LAST occurrence of each digit 
        for (int i = 0; i < n; i++) {
            lastInd[s.charAt(i) - '0'] = i;
        }
        
        for (int i = 0; i < n; i++) {
            if (s.charAt(i) == '9') continue;
            
            int curr = s.charAt(i) - '0';
            
            for (int j = 9; j > curr; j--) {
                // Swap with later position
                if (lastInd[j] != -1 && i < lastInd[j]) {  
                    // Convert to char array for mutation
                    char[] chars = s.toCharArray();
                    char temp = chars[lastInd[j]];
                    chars[lastInd[j]] = chars[i];
                    chars[i] = temp;
                    return new String(chars);
                }
            }
            // Early break if swapped
            if ((curr + '0') != s.charAt(i)) {
                break;
            }
        }
        return s;  // No swap needed
    }
}