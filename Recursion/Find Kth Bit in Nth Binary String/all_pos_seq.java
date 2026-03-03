//Space complexity :- O(n)

// Approach :-
// generate all sequence of the string and find the kth char of that string 


// Link :- https://leetcode.com/problems/find-kth-bit-in-nth-binary-string/

class Solution {
    private String helper(int n) {
        if (n == 1) return "0";
        
        String res = helper(n - 1);
        StringBuilder temp = new StringBuilder();
        
        // Flip 0→1, 1→0
        for (char ch : res.toCharArray()) {
            if (ch == '0') temp.append('1');
            else temp.append('0');
        }
        
        // Reverse temp
        return res + "1" + temp.reverse().toString();
    }
    
    public char findKthBit(int n, int k) {
        String res = helper(n);
        return res.charAt(k - 1);
    }
}
