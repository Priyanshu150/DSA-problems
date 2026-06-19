import java.util.*;

// Time complextiy :- O(n)
// Space complexity :- O(n)

// Approach :-   
// bring every value to the sorted middle value will be optimal 
// for every subarray, find the mean value index 
// then find the leftSum and rightSum from that point 
// formula will be (rightSum + leftSum) - mean_val(if the count of subarray is odd )
// this formula comes from expanding the given equation 

//Link :- https://www.geeksforgeeks.org/problems/optimal-array--170647/1

class Solution {
    public ArrayList<Integer> optimalArray(int[] arr) {
        int n = arr.length;
        int preSum[] = new int[n+1];
        int sum = 0;
        
        ArrayList<Integer> res = new ArrayList<>();
        
        
        for(int i=0; i<n; ++i){
            // update the prefix sum 
            sum += arr[i];
            preSum[i+1] = sum;
            // skip the first elemetn 
            if(i == 0){
                res.add(0);
                continue;
            }
            // find the mean index 
            int mid = i/2;
            // find the left and right sum 
            int leftSum = preSum[mid];
            int rightSum = preSum[i+1] - preSum[mid+1];
            // value of the array 
            int val = rightSum - leftSum;
            // if the length of the sub-array is odd then subtract mean value 
            if(i % 2 != 0){
                val -= arr[mid];
            }
            // add the result to answer array 
            res.add(val);
        }
        return res;
    }
}