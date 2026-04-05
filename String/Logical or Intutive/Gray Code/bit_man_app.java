import java.util.*

// Time complexity :- O(2^(n-1))
// Space complexity :- O(1)

// Approach :- 
// convert the binary code to gray code, b1 b2 b3 b4 => g1 g2 g3 g4
// g1 = b1, g2 = b1^b2, g3 = b2^b3, g4 = b3^b4


// Links :- https://www.geeksforgeeks.org/problems/gray-code-1611215248/1

class Solution {
    public ArrayList<String> graycode(int n) {
        ArrayList<String> res = new ArrayList<String> ();
        
        for(int i=0; i<(1 << n); ++i){
            int val = (i^ (i>>1));
            
            StringBuilder s = new StringBuilder();
            
            for(int j=n-1; j>=0; --j){
                if((val & (1<<j)) != 0){
                    s.append("1");
                }
                else{
                    s.append("0");
                }
            }
            res.add(s.toString());
        }
        return res;
    }
}
