import java.util.*

// Time complexity :- O(n)
// Space complexity :- O(1)

// Approach :- 
// Intially we'll assume that, [0, low] will be 0, [low - high] will be unknown and [high+1 - n] will be 1 
// we'll traverse in unkown region and sort it out accordingly in 0 and 1 region


// Links :- https://www.geeksforgeeks.org/problems/segregate-0s-and-1s5106/1

class Solution {
    void segregate0and1(int[] arr) {
        int n = arr.length;
        int low = 0, high = n-1;
        
        while(low <= high){
            if(arr[low] == 0){
                low++;
            }
            else{
                // swap low and high index numbers 
                int temp = arr[low];
                arr[low] = arr[high];
                arr[high] = temp;
                
                high--;
            }
        }
    }
}
