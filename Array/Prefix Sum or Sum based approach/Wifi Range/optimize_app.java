import java.util.*

//Time complextiy :- O(n)
// Space complexity :- O(1)

// Approach :-  
// maintain a maxReach wifi index which update the range for every wifi i.e. max value of (x + i)
// and check if there is a gap left for the previous reachable room 
// if gap exist then it's not possible i.e. (maxReach < i-x-1)

// Link :-  https://www.geeksforgeeks.org/problems/wifi-range--170647/1

class Solution {
    public boolean wifiRange(String s, int x) {
        // code here
        int maxReach = -1;
        int n = s.length();
        
        for(int i=0; i<n; ++i){
            if(s.charAt(i) == '1'){
                if(maxReach < i-x-1)
                    return false;
                
                maxReach = Math.max(maxReach, i+x);
            }
        }
        return maxReach >= n-1;
    }
}