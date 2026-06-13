import java.util.*

// Time complexity :- O(n)
// Space complexity :- O(n)

// Approach :-
// we store the element in the stack, we'll store the element with have same sign
// travesing from left to right, we'll store +ve element 
// whenever a -ve element comes we'll try to pop out the element which are less than that in stack 
// if at last the stack becomes empty, add -ve element into the answer 
// if both having same value destory both as in remove top of stack and don't add -ve eleement into stack 

// Link :- https://leetcode.com/problems/asteroid-collision/description/

class Solution {
    public int[] asteroidCollision(int[] asteroids) {
        int n = asteroids.length;
        Stack<Integer> st = new Stack<>();
        List<Integer> ans = new ArrayList<>();

        // traverse every asteroid from left to right
        for(int i = 0; i < n; ++i){
            // left moving asteroid meets smaller right moving ones → destroy them
            while(!st.isEmpty() && asteroids[i] < 0 && st.peek() < Math.abs(asteroids[i])){
                st.pop();
            }
            // asteroids of equal size moving in opposite directions → both destroyed
            if(!st.isEmpty() && asteroids[i] < 0 && st.peek() == Math.abs(asteroids[i])){
                st.pop();
                continue;
            }
            // left moving asteroid that destroyed all right moving ones
            if(asteroids[i] < 0 && st.isEmpty()){
                ans.add(asteroids[i]);
            }
            // push right moving asteroid onto the stack
            if(asteroids[i] > 0){
                st.push(asteroids[i]);
            }
        }

        int start = ans.size();
        // collect remaining right moving asteroids from stack
        while(!st.isEmpty()){
            ans.add(st.pop());
        }
        // reverse to restore left-to-right order
        Collections.reverse(ans.subList(start, ans.size()));

        // convert ArrayList to int[]
        return ans.stream().mapToInt(Integer::intValue).toArray();
    }
}