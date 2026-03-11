import java.util.*

//Time complexity :- O(n)
//Space complexity :- O(n)

// Approach :- 
// each element will contribute to the sum depends how many times they're occuring in subarray as min element 
// using nse concept we can calculate the nse from both side 
// the number of subarray will be, left subarray count * right subbarry count 
// and if we multiply the subarray count with value that much times it will contribute to final sum 
// using single we'll calculate the solution 
// the number which is poping the stack element will be the right minimum for that element 
// and the left minimum for that element will be the top of the stack 
// For rest of the element which are left in stack last element will be the boundary for them 


//Link :- https://www.geeksforgeeks.org/problems/sum-of-subarray-minimum/1

class Solution {
    public int sumSubMins(int[] arr) {
        int res = 0, n = arr.length;
        Stack<Integer> st = new Stack<>();
        
        // traverse from left to right
        for(int i=0; i<n; ++i){
            // maintain a monotonic increasing stack 
            while(!st.isEmpty() && arr[st.peek()] > arr[i]){
                // save the top of stack index 
                int prev = st.peek();
                st.pop();
                
                // find the count using nge concept 
                int rtSubArrCnt = i - prev;
                int ltSubArrCnt = prev - (st.isEmpty() ? -1 : st.peek());
                
                // left subarray count * right subarray count * value of ind
                res += (rtSubArrCnt * ltSubArrCnt * arr[prev]);
            }
            // push the index into the stack 
            st.push(i);
        }
        // process the rest of element from the stack 
        while(!st.isEmpty()){
             // save the top of stack index 
            int prev = st.peek();
            st.pop();
                
            // find the count using nge concept 
            int rtSubArrCnt = n - prev;
            int ltSubArrCnt = prev - (st.isEmpty() ? -1 : st.peek());
                
            // left subarray count * right subarray count * value of ind
            res += (rtSubArrCnt * ltSubArrCnt * arr[prev]);
        }
        return res;
    }
}
