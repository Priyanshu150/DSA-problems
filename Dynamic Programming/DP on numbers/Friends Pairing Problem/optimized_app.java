import java.util.*;

// Time complextiy :- O(n)
// Space complexity :- O(1)

// Approach :-  
// for current person, either we can keep him single or pair it 
// if keep it single there will rest f(n-1) people left
// double => (n-1) ways to pick * f(n-2) people left
// summation of both will be our final ways  

// Link :- https://www.geeksforgeeks.org/problems/friends-pairing-problem5425/1

class Solution {
    public int countFriendsPairings(int n) {
        if(n <= 2)      return n;
        
        int prev1 = 1, prev = 2;
        
        for(int i=3; i<=n; ++i){
            int curr = prev + (i-1) * prev1;
            prev1 = prev;
            prev = curr;
        }
        return prev;
    }
}
