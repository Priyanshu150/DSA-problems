import java.util.*

// Time complextiy :- O(n*x*m)
// Space complexity :- O(x)


//Link :- https://www.geeksforgeeks.org/problems/dice-throw5349/1

class Solution {
    static int noOfWays(int m, int n, int x) {
        // initalize a 1d array 
        int[] ahead = new int[x + 1];
        // base case, when sum=0 the there will be 1
        ahead[0] = 1;
        
        for (int diceCnt = n - 1; diceCnt >= 0; diceCnt--) {
            // create new array of same size to store current value 
            int[] curr = new int[x + 1];  
            
            // try out all possible ways 
            for (int sum = 1; sum <= x; sum++) {
                for (int faceVal = 1; faceVal <= m; faceVal++) {
                    if (sum - faceVal >= 0) {
                        curr[sum] += ahead[sum - faceVal];
                    }
                }
            }
            // update the ahead 1d array with current value 
            ahead = curr;
        }
        return ahead[x];
    }
};