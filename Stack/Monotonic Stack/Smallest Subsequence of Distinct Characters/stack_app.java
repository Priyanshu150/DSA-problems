import java.util.*;

// Time complextiy :- O(n)
// Space complexity :- O(n)

// Approach :-
// use stack to maintain a montonic stack of char which will give us lexiographically smallest string 
// we'll remove the char from the stack based on monotonicity and 
// if more occurence of curr char which we're removing from stack is present in later part of string 
// at last build the answer from the char present in the stack 


// Links :- 
// https://leetcode.com/problems/remove-duplicate-letters/description/
// https://leetcode.com/problems/smallest-subsequence-of-distinct-characters/description/

class Solution {
    public String smallestSubsequence(String s) {
        int[] freq = new int[26];

        // count the frequency of each char 
        for(char ch: s.toCharArray()){
            freq[ch-'a'] += 1;
        }

        boolean[] check = new boolean[26];
        Stack<Character> st = new Stack<>();

        // traverse on every char of string 
        for(char ch: s.toCharArray()){
            // maitain a monotonic stack while maintain the distinct char 
            while(!st.empty() && check[ch - 'a'] == false && ch < st.peek() && freq[st.peek() - 'a'] >= 1){
                check[st.peek() - 'a'] = false;
                st.pop();
            }
            // add the char into the stack only if it's not present 
            if(check[ch - 'a'] == false){
                st.push(ch);
                check[ch - 'a'] = true;
            }
            // decreament the frequency of the char which are processed 
            freq[ch - 'a'] -= 1;
        }

        StringBuilder res = new StringBuilder();

        // form the lexiographically smallest string from the char present in stack
        while(!st.empty()){
            res.append(st.peek());
            st.pop();
        }
        // reverse the string to get the right order 
        res.reverse();
        return res.toString();
    }
}