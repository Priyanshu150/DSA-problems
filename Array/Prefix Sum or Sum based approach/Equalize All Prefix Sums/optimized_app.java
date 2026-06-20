import java.util.*;

// Time complextiy :- O(n)
// Space complexity :- O(1)

// Approach :-   
// for every new number getting add the operation will be (prev_val + number_added - new_mean_value )
// becuase in even number of element the operation will always be equal to both median of array 
// in case of odd the formula stands as the median don't change 

//Link :- https://www.geeksforgeeks.org/problems/optimal-array--170647/1

class Solution {
    public ArrayList<Integer> optimalArray(int[] arr) {
         int n = arr.length;

        ArrayList<Integer> res = new ArrayList<>(n);   
        res.add(0);                                    

        for(int i = 1; i < n; ++i){
            int val = res.get(i-1) + (arr[i] - arr[i/2]);  
            res.add(val);
        }
        return res;
    }
}