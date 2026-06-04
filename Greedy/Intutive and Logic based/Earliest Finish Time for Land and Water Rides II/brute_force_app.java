import java.util.*

// Time complexity :- O(N*M)
// Space complexity :- O(1)

// Approach :- 
// try all possible combination of taking rides using 2 for loops 

// Link :- https://leetcode.com/problems/earliest-finish-time-for-land-and-water-rides-ii/description/

class Solution {
    public int earliestFinishTime(int[] landStartTime, int[] landDuration, int[] waterStartTime, int[] waterDuration) {
        
        int n = landStartTime.length;
        int m = waterStartTime.length;
        int result = Integer.MAX_VALUE;

        // check all the land riders 
        for(int i=0; i<n; ++i){
            int landSt = landStartTime[i], dur1 = landDuration[i];

            // check all the water rides 
            for(int j=0; j<m; ++j){
                int waterSt = waterStartTime[j];
                int dur2 = waterDuration[j];
                
                // first take the land ride and then water rider
                int time = landSt + dur1;
                if(waterSt > time){
                    time += (waterSt - time);
                }
                time += dur2;
                // update the min time take for the current configuration 
                result = Math.min(result, time);
                
                // first take the water rider and then land ride 
                time = waterSt + dur2;
                if(landSt > time){
                    time += (landSt - time);
                }
                time += dur1;
                // update the min time take for the current configuration 
                result = Math.min(result, time);
            }
        }
        return result;
    }
}