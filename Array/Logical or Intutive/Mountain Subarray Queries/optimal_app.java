import java.util.*;

// Time complextiy :- O(n+q)
// Space complexity :- O(q)

// Approach :-


// Link :- https://www.geeksforgeeks.org/problems/mountain-subarray-problem/1

class Solution {
    public ArrayList<Boolean> processQueries(int[] arr, int[][] queries) {
        int n = arr.length;
        
        int[] dec = new int[n];
        dec[n-1] = n-1;
        
        for(int i=n-2; i>=0; --i){
            if(arr[i] <= arr[i+1]){
                dec[i] = dec[i+1];
            }else{
                dec[i] = i;
            }
        }
        
        int[] inc = new int[n];
        inc[0] = 0;
        
        for(int i=1; i<n; ++i){
            if(arr[i] <= arr[i-1]){
                inc[i] = inc[i-1];
            }else{
                inc[i] = i;
            }
        }
        
        ArrayList<Boolean> ans = new ArrayList<>();
        
        for(int[] query: queries){
            int l = query[0];
            int r = query[1];
            ans.add(dec[l] >= inc[r]);
        }
        return ans;
    }
}