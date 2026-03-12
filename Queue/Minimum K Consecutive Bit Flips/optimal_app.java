import java.util.*

//Time complexity :- O(n)
//Space complexity :- O(k)

// Approach :- 
// instead of storing all the n index information 
// we can store only k bit info as that is only what we need 
// we'll use deque to store that info 
// we'll add 1 if we flip the bit otherwise 0 always 


//Link :- https://www.geeksforgeeks.org/problems/minimum-number-of-k-consecutive-bit-flips--171650/1

class Solution {
    public int kBitFlips(int[] arr, int k) {
        int n = arr.length;
        int flipped = 0, res = 0;
        Deque<Integer> dq = new LinkedList<>();
        
        for(int i=0; i<n; ++i){
            // validity of previous flip is expired 
            if(i >= k){
                flipped -= dq.peekFirst();
                dq.pollFirst();
            }
            // flip is needed 
            if(arr[i] == (flipped % 2)){
                // if index does not have sufficient next bit then it's not possible 
                if(i+k > n){
                    return -1;
                }
                // add the condition to flips 
                res += 1;
                flipped++;
                dq.offerLast(1);
            }else{
                dq.offerLast(0);
            }
        }
        return res;
    }
}
