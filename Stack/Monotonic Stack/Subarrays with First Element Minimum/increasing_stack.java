import java.util.*

//Time complexity :- O(n)
//Space complexity :- O(n)

// Approach :- 
// we'll use stack and maintain a monotonic stack in this case 
// with the help of monotonic stack we can track the minimum element 
// and the size of stack will tell us all the element in the stack will contribute to how many arrays 


//Link :- https://www.geeksforgeeks.org/problems/subarrays-with-first-element-minimum/1

class Solution {
    public int countSubarrays(int[] arr) {
        int res = 0;
        Stack<Integer> st = new Stack<>();
        
        for(int num: arr){
            // maintain a monotonic stack
            while(!st.isEmpty() && st.peek() > num){
                st.pop();
            }
            // add current element into the stack
            st.push(num);
            // add length of stack into answer 
            res += st.size();
        }
        return res;
    }
}
