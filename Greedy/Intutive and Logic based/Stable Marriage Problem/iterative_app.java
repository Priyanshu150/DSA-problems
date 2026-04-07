import java.util.*

// Time complexity :- O(n^2)
// Space complexity :- O(1)

// Approach :- 
// for finding the stable match we've to apply iterative method 
// intitally we'll everyone is free, we'll map every men with women or vice-versa can also be done 
// based on the preference of current men map it to the women 
// if women if free map it with the current men 
// otherwise compare the preference of women for previous and current men and map them accordingly 
// use the next index to keep track of each men preferences 
// repret these untill there are no free mens and women


// Links :- https://www.geeksforgeeks.org/problems/stable-marriage-problem/1

class Solution {
    private boolean prefers(int[][] women, int w, int m, int m1, int n){
        // find the first preferencce of wommen among m1 & m
        for(int i=0; i<n; ++i){
            if(women[w][i] == m){
                return true;
            }
            if(women[w][i] == m1){
                return false;
            }
        }
        return false;
    }
    
    public int[] stableMarriage(int[][] men, int[][] women) {
        int n = men.length;
        
        int[] wPartner = new int[n];
        int[] mPartner = new int[n];
        
        // intially none of the men and women have partners 
        for(int i=0; i<n; ++i){
            wPartner[i] = -1;
            mPartner[i] = -1;
        }
        
        // next proposal index 
        int[] next = new int[n];
        boolean[] freeMan = new boolean[n];
        
        // intially every men is free 
        for(int i=0; i<n; ++i)
            freeMan[i] = true;
        
        int freeCount = n;
        
        // untill we have free man 
        while(freeCount > 0){
            int m;
            
            // find the first free man from all 
            for(m=0; m<n; ++m){
                if(freeMan[m])
                    break;
            }
            // find the women based on preference 
            int w = men[m][next[m]];
            next[m]++;
            
            // if w is free
            if(wPartner[w] == -1){
                wPartner[w] = m;
                mPartner[m] = w;
                freeMan[m] = false;
                freeCount--;
            }
            // if w is already engaged 
            else{
                // find the previous partner 
                int m1 = wPartner[w];
                
                // if w prefers m over current partner 
                if(prefers(women, w, m, m1, n)){
                    // make m & w as a new partner 
                    wPartner[w] = m;
                    mPartner[m] = w;
                    
                    // mark m as not free and m1 as free 
                    freeMan[m] = false;
                    freeMan[m1] = true;
                }
            }
        }
        return mPartner;
    }
}