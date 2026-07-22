import java.util.*;

// Time complexity :- O(n)
// Space complexity :- O(26)

// Approach :- 
// traverse from right to left in string 
// for every char check if the next char is seen or not, if seen the update the maximum reachable ponit 
// otherwise max reachable point will be current index 
// whenever we're at char 'a' maintain the maximum difference among the (maximum reachble index - current index )


// Links :- https://www.geeksforgeeks.org/problems/maximum-reachable-index-difference/1

class Solution {
    public int maxIndexDifference(String s) {
        int n = s.length();
        int res = -1;
        
        int[] lastInd = new int[26];    // char maintain the maximum reachable index
        Arrays.fill(lastInd, -1);       // intialize the array with -1
        
        // traverse from left to right 
        for(int i=n-1; i>=0; --i){
            int farthest = i;       // current index is farthest for every char
            char ch = s.charAt(i);
            
            // check the maximum reachble index for next char after current 
            if(ch != 'z' && lastInd[ch - 'a' + 1] != -1){
                farthest = lastInd[ch - 'a' + 1];
            }
            // update the maximum reachable index 
            lastInd[ch - 'a'] = Math.max(farthest, lastInd[ch - 'a']);
            
            // maintain the highest difference among all the index
            if(ch == 'a'){
                res = Math.max(res, farthest - i);
            }
        }
        return res;
    }
}