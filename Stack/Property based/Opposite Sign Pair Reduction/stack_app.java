import java.util.*

// Time complexity :- O(n)
// Space complexity :- O(n)

// Approach :- 


// Links :- https://www.geeksforgeeks.org/problems/asteroid-collision/1

class Solution {
    public ArrayList<Integer> reducePairs(int[] arr) {
        ArrayList<Integer> s = new ArrayList<>();

        // Traverse each element
        for (int element : arr) {

            // Process while there is a collision (opposite signs)
            while (!s.isEmpty() && s.get(s.size() - 1) * element < 0) {
                int top = s.get(s.size() - 1);

                // Top has larger absolute value, keep top
                if (Math.abs(top) > Math.abs(element)) {
                    element = top;
                    s.remove(s.size() - 1);
                }

                // Current element has larger absolute value
                // keep current element
                else if (Math.abs(top) < Math.abs(element)) {
                    s.remove(s.size() - 1);
                }

                // Both have same absolute value, both removed
                else {
                    s.remove(s.size() - 1);
                    element = 0;
                    break;
                }
            }

            // If current element still exists, push into stack
            if (element != 0)
                s.add(element);
        }

        return s;
    }
}