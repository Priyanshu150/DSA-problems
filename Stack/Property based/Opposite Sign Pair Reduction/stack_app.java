import java.util.*

// Time complexity :- O(n)
// Space complexity :- O(n)

// Approach :-
// we can use stack to store element into it
// if stack is empty add the element directly
// check if they have opposite polarity and remove all the smaller element from stack
// remove both element if they has different sign and having same value 
// add element if adjacent have same value or stack is empty


// Link :- https://www.geeksforgeeks.org/problems/asteroid-collision/1
// Lnik2 :- https://www.geeksforgeeks.org/problems/opposite-sign-pair-reduction/1


class Solution {
    // check if both the number has same polarity or not 
    private boolean isSame(int num1, int num2){
        // same sign
        if(num1 > 0 && num2 > 0)
            return true;
        // same sign
        if(num1 < 0 && num2 < 0)
            return true;
        // opposite sign
        return false;
    }
    
    public ArrayList<Integer> reducePairs(int[] arr) {
        int n = arr.length;
        
        Stack<Integer> st = new Stack<>();
        ArrayList<Integer> res = new ArrayList<>();
        
        for(int i=0; i<n; ++i){
            // check if they have opposite polarity and stack has smaller value 
            while(!st.empty() && !isSame(st.peek(), arr[i]) && Math.abs(st.peek()) < Math.abs(arr[i])){
                st.pop();
            }
            // both has different sign and having same value 
            if(!st.empty() && !isSame(st.peek(), arr[i]) && Math.abs(st.peek()) == Math.abs(arr[i])){
                st.pop();
                continue;
            }
            // same sign then add into the stack 
            if(!st.empty() && isSame(st.peek(), arr[i])){
                st.push(arr[i]);
            }
            // stack is empty then add it 
            if(st.empty()){
                st.push(arr[i]);
            }
        }
        // add the remaning element into answer 
        while(!st.empty()){
            res.add(st.peek());
            st.pop();
        }
        // reverse the answer 
        Collections.reverse(res);
        return res;
    }
}