import java.util.*;

// Time complextiy :- O(n * log(max(arr)))
// Space complexity :- O(1)

// Approach :-  

// Link :- https://www.geeksforgeeks.org/problems/maximum-subset-xor/1

class Solution {
    public int maxSubsetXOR(int[] arr) {
        int n = arr.length;
        int index = 0;
        
        // process bits from MSB to LSB
        for(int bit=31; bit>=0 && index<n; bit--){
            int maxIndex = index;
            
            // find an element having the current bit set
            for(int i=index; i<n; ++i){
                if((arr[i] & (1 << bit)) != 0 && arr[i] > arr[maxIndex]){
                    maxIndex = i; 
                }
            }
            
            // no pivot found for this bit 
            if((arr[maxIndex]  & (1 << bit)) == 0){
                continue;
            }
            
            // place the pivot at the current index 
            int temp = arr[index];
            arr[index] = arr[maxIndex];
            arr[maxIndex] = temp;
            
            // eliminate the current bit from all other elements 
            for(int i=0; i<n; ++i){
                if(i != index && (arr[i] & (1 << bit)) != 0){
                    arr[i] ^= arr[index];
                }
            }
            index++;
        }
        
        int ans = 0;
        for(int num: arr){
            ans ^= num;
        }
        return ans;
    }
}