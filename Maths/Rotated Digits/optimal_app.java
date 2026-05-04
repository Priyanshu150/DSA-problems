import java.util.*

// Time complexity :- O(n * len(digit))
// Space complexity :- O(1)

// Approach :- 
// try to rotate each digit and check which one is valid 
// if we're getting 3,4 and 7 in the digit then it'll never be possible to rotate 
// apart from those 3, if we're have 2,5,6 and 9 then it's always possible 
// and if valid 4 digit are also not present then it'll will be never possible 

// Links :- https://leetcode.com/problems/rotated-digits/

class Solution {
    private boolean isValid(int num) {
        boolean hasChanged = false;
        
        while (num > 0) {
            int digit = num % 10;
            
            // 1. If it contains 3, 4, or 7, it can't be rotated at all
            if (digit == 3 || digit == 4 || digit == 7) {
                return false;
            }
            
            // 2. If it contains 2, 5, 6, or 9, the number WILL change 
            // after rotation (making it a "good" number)
            if (digit == 2 || digit == 5 || digit == 6 || digit == 9) {
                hasChanged = true;
            }
            
            num /= 10;
        }
        
        // The number is good only if all digits were valid 
        // AND at least one digit caused the value to change.
        return hasChanged;
    }

    public int rotatedDigits(int n) {
        int res = 0;

        // check for each number 
        for(int num=0; num<=n; ++num){
            if(isValid(num)){
                res += 1;
            }
        }
        return res;
    }
}