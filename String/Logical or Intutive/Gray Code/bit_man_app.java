import java.util.*

// Time complexity :- O(2^(n-1))
// Space complexity :- O(1)

// Approach :- 
// 


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
