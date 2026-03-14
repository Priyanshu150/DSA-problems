import java.util.*

// Time complexity :- O(n*m)
// Space complexity :- O(1)

// approach :- 

// Code :- 

class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = haystack.size(), m = needle.size();
        // haystack is smaller than needle 
        if(n < m)
            return -1;

        // traverse on each char of haystack 
        for(int i=0; i<n; ++i){
            // first char of needle is matched with haystack current char 
            if(haystack[i] == needle[0]){
                int j=1;
                // match the rest of char of needle 
                for(; j<m; ++j){
                    // char are not matching or we don't have enough char to match
                    if(i+j >= n || haystack[i+j] != needle[j])
                        break;
                }
                // needle is present in the haystack 
                if(j==m)
                    return i;
            }
        }
        return -1;
    }
};