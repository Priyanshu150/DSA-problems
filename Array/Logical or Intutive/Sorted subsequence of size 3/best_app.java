import java.util.*

// Time complexity :- O(n)
// Space complexity :- O(1)

// Approach :- 
// we'll maintain the first two element in variable and as soon we find the third element greater than those 2 
// then it's possible, using these 3 element 
// we've to maintain 3 variables =>  first, prevFirst and second element 
// maitain only first min will not satify our condition and fail for some test case 
// example - [12, 11, 10, 5, 6, 2, 30]


// Links :- https://www.geeksforgeeks.org/problems/sorted-subsequence-of-size-3/1

class Solution {
    public ArrayList<Integer> find3Numbers(int[] arr) {
        int n = arr.length;
        
        // Base case: Triplet impossible with fewer than 3 elements
        if (n < 3) {
            return new ArrayList<>();
        }
        
        int first = Integer.MAX_VALUE;
        int second = Integer.MAX_VALUE;
        int prevFirst = Integer.MAX_VALUE; // This will store the 'first' that belongs to 'second'
        
        for (int i = 0; i < n; ++i) {
            int ele = arr[i];
            
            if (ele <= first) {
                // Update the global smallest element
                first = ele;
            } else if (ele <= second) {
                // ele is greater than 'first', so it's a potential 'second'
                second = ele;
                // We must lock in the 'first' that was valid at the time we found this 'second'
                prevFirst = first; 
            } else {
                // ele is greater than 'second', which is greater than 'prevFirst'
                // We wrap Arrays.asList in a new ArrayList to match your return type
                return new ArrayList<>(Arrays.asList(prevFirst, second, ele));
            }
        }
        
        return new ArrayList<>();
    }
}