import java.util.*;

// Time complextiy :- O(n)
// Space complexity :- O(1)

// Approach :-   
// we've to make only 1 swap s we can swap the first largest char with later smallest one 
// for a char we'll find if there is any character present on the right side which is smallest among all from current char
// if it does, then we swap all the occurence of both these characters 

//Link :- https://www.geeksforgeeks.org/problems/choose-and-swap0531/1

class Solution {
    public String chooseSwap(String s) {
        int n = s.length();
        int[] freq = new int[26];
        Arrays.fill(freq, -1);
        char ch1 = '#', ch2 = '#';

        for(int i = 0; i < n; ++i){
            // if this is not the first occurrence of char
            if(freq[s.charAt(i) - 'a'] != -1)
                continue;

            // mark the char as visited
            freq[s.charAt(i) - 'a'] = i;
            boolean found = false;

            // find the smaller char on the right side
            for(int j = i+1; j < n; ++j){
                // check if char is valid or not
                if(freq[s.charAt(j) - 'a'] == -1 && s.charAt(j) < s.charAt(i)){
                    // update the char to swap
                    ch1 = s.charAt(i);
                    // find the smallest among all present
                    if(ch2 == '#' || s.charAt(j) < ch2){
                        ch2 = s.charAt(j);
                    }
                    found = true;
                }
            }
            if(found) break;
        }

        StringBuilder res = new StringBuilder();

        // swap the char if any present
        if(ch1 != '#' && ch2 != '#'){
            for(int i = 0; i < n; ++i){
                if(s.charAt(i) == ch1){
                    res.append(ch2);
                }
                else if(s.charAt(i) == ch2){
                    res.append(ch1);
                }
                else{
                    res.append(s.charAt(i));
                }
            }
        }
        // if none present then original string itself is lexicographically smallest
        return (res.length() == 0) ? s : res.toString();
    }
}
