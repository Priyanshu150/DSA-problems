// Space complexity :- O(n)

// Approach :-     
// if we observe the last digit of power of all 9 number we'll find that they form a cycle of length 4 
// and they keep on rotating among these found value 
// we'll find the b mod 4 value and then find the value using a's last digit 
// b mod 4 turns out to be 0 update it to 4, that way we can handle the 0 as a^0 will always be 1 

//Link :- https://www.geeksforgeeks.org/problems/optimal-array--170647/1

class Solution {
    public int getLastDigit(String a, String b) {
        int n = a.length();
        int ld  = a.charAt(n-1) - '0';
        
        // a^0 = 1, regardless of any value of a 
        if(isZero(b))   return 1;
        // find the value of b mod 4
        int modValue = mod4(b);
        // make mod value to 4 if it's complete divisible by 4 
        int exponent = (modValue == 0) ?  4 : modValue;
        
        int result = 1;
        // find the last digit value for the mod value 
        for(int cnt=0; cnt<exponent; ++cnt){
            result = (result * ld) % 10;
        }
        return result;
    }
    
    private boolean isZero(String s){
        // check if all the char are 0 or not
        for(char ch: s.toCharArray()){
            if(ch != '0')
                return false;
        }
        return true;
    }
    
    private int mod4(String s){
        int modValue = 0;
        
        for(char ch: s.toCharArray()){
            // convert the number into into integer
            modValue = (modValue*10) + (ch - '0');
            // modulo it with 4 to avoid overflow 
            modValue %= 4;
        }
        return modValue;
    }
};