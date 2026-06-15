import java.util.*;

// Time complextiy :- O(n*log(n))
// Space complexity :- O(1)

// Approach :-   
// for every element in the array apply binary search and if we find it then it's binary searchable otherwise not 

//Link :- https://www.geeksforgeeks.org/problems/binary-searchable-elements/1

class Solution {
    private boolean binarySearch(int[] arr, int n, int target){
        int low = 0;
        int high = n-1;
        
        while(low <= high){
            int mid = low + (high - low)/2;
            
            if(arr[mid] == target){
                return true;
            }
            else if(arr[mid] > target){
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return false;
    }
    
    public int binarySearchable(int[] arr) {
        int n = arr.length;
        int res = 0;
        
        for(int i=0; i<n; ++i){
            if(binarySearch(arr, n, arr[i])){
                res += 1;
            }
        }
        return res;
    }
};