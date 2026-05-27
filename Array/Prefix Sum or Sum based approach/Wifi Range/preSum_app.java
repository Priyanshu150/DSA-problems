import java.util.*

//Time complextiy :- O(n)
// Space complexity :- O(n)

// Approach :-  
// maintain a presum array for the wifi range given values and range provided
// if the value is greater or equal to 1 then that room has access otherwise not 

// Link :-  https://www.geeksforgeeks.org/problems/wifi-range--170647/1


class Solution {
    public boolean wifiRange(String s, int x) {
        int n = s.length();
        int[] preSum = new int[n+1];
        
        // standard presum 
        for(int i=0; i<n; ++i){
            if(s.charAt(i) == '1'){
                // find the valid left and right range 
                int left = Math.max(0, i-x);
                int right = Math.min(n-1, i+x);
                
                preSum[left] += 1;
                preSum[right+1] -= 1;   
            }
        }
        int sum = 0;
        
        for(int i=0; i<n; ++i){
            sum += preSum[i];
            
            if(sum <= 0)
                return false;
        }
        return true;
    }
}