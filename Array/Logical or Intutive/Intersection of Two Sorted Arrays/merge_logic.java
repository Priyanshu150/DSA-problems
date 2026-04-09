import java.util.*

// Time complexity :- O(n + m)
// Space complexity :- O(1)

// Approach :- 
// we'll use the merge logic of merge sort, where we'll traverse both array parallely 
// skip the duplicate elements from the first array 
// and then skip the smaller element of both the arrays 
// add the one which are equal in a ds and move to the next pointer
// we'll not skip duplicate in arr2 as it'll automatically be skipped 


// Links :- https://www.geeksforgeeks.org/problems/intersection-of-two-sorted-arrays-with-duplicate-elements/1

class Solution {
    ArrayList<Integer> intersection(int[] a, int[] b) {
        ArrayList<Integer> res = new ArrayList<Integer> ();
        
        int n = a.length;
        int m = b.length;
        int i = 0, j = 0;
        
        // similar to merge of merge sort 
        while(i<n && j<m){
            // skip the duplicate elements in the first array 
            if(i > 0 && a[i-1] == a[i]){
                i++;
                continue;
            }
            
            // skip the smaller 
            if(a[i] < b[j]){
                i++;
            }
            else if(a[i] > b[j]){
                j++;
            }
            // if equal, add to result and move both 
            else{
                res.add(a[i]);
                i++;
                j++;
            }
        }
        return res;
    }
}