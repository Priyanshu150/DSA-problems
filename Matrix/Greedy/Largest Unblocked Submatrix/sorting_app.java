import java.util.*;

//Time complextiy :- O(k + k*log(k))
// Space complexity :- O(k)

// Approach :-  
// store the each row, col value in an array which are block
// find the length and breadth b/w those block rows,cols, start and end 
// maintain max width and length among all the value 
// product of both will be our answer 

//Link :- https://www.geeksforgeeks.org/problems/largest-unblocked-submatrix/1


class Solution {
    public int largestArea(int n, int m, int[][] arr) {
        List<Integer> rows = new ArrayList<>();
        List<Integer> cols = new ArrayList<>();
        
        rows.add(0);
        cols.add(0);
        rows.add(n+1);
        cols.add(m+1);
        
        int k = arr.length;
        
        for(int i=0; i<k; ++i){
            rows.add(arr[i][0]);
            cols.add(arr[i][1]);
        }
        
        Collections.sort(rows);
        Collections.sort(cols);
        
        
        int maxLength = 0;
        int maxBreadth = 0;
        
        for(int i=1; i<rows.size(); ++i){
            int length = rows.get(i) - rows.get(i-1) - 1;
            maxLength = Math.max(maxLength, length);
        }
        
        for(int i=1; i<cols.size(); ++i){
            int breadth = cols.get(i) - cols.get(i-1) - 1;
            maxBreadth = Math.max(maxBreadth, breadth);
        }
        
        return maxLength * maxBreadth;
    }
}