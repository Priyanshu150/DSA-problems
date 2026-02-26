import java.util.HashMap;

//Time complexity :- O(n)
//Space complexity :- O(n)

//Approach :-
// store both char map in seprate hash set 
// and if the number repeats then check if the mapping is consistent or not 
// if not then it's not possible 

// Link :- https://www.geeksforgeeks.org/problems/isomorphic-strings-1587115620/1

class Solution {
    public boolean areIsomorphic(String s1, String s2) {
        // code here
        int n = s1.length(), m = s2.length();
        if (n != m) return false;
        
        HashMap<Character, Character> m1 = new HashMap<>();
        HashMap<Character, Character> m2 = new HashMap<>();
        
        for (int i = 0; i < n; ++i) {
            // Check s1[i] mapping consistency
            if (m1.containsKey(s1.charAt(i)) && m1.get(s1.charAt(i)) != s2.charAt(i)) {
                return false;
            }
            // Check s2[i] mapping consistency  
            if (m2.containsKey(s2.charAt(i)) && m2.get(s2.charAt(i)) != s1.charAt(i)) {
                return false;
            }
            m1.put(s1.charAt(i), s2.charAt(i));
            m2.put(s2.charAt(i), s1.charAt(i));
        }
        return true;
    }
}