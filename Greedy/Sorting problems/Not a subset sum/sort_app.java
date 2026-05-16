import java.util.*

// Time complexity :- O(n*log(n))
// Space complexity :- O(1)

// Approach :- 
// we'll use greedy approach and sort the array 
// maitain a res variable which will be our sum of element 
// whenever res >= arr[i] then it's valid and all the sum below res can be achieved 
// if it's res < arr[i] then res cannot be formed hence that will our answer 
// otherwise sum of all element + 1 will be the final answer 


// Links :- https://www.geeksforgeeks.org/problems/asteroid-collision/1

class Solution {
    public int findSmallest(int[] arr) {
        int res = 1;
        int n = arr.length; 
        
        // Sort the array 
        Arrays.sort(arr);
        
        // Traverse the array and increment 'res' if arr[i] is
        // smaller than or equal to 'res'
        for(int i=0; i<n && arr[i] <= res; ++i){
            res += arr[i];
        }
        return res;
    }
}