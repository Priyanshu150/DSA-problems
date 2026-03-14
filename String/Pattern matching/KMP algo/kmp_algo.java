import java.util.*

// Time complexity :- O(n + m)
// Space complexity :- O(m)

// approach :- 

// Code :- 

class Solution {
private:
    void computeLPS(string &s, vector<int> &lps, int &m){
        // lps of 1 length will be 0 
        lps[0] = 0;
        int len = 0, i=1;

        while(i<m){
            // the lenght and curr char matches then 
            if(s[i] == s[len]){
                // update len, i and lps array 
                len++;
                lps[i] = len;
                i++;
            }else{
                if(len != 0){
                    // point to previous lps array 
                    len = lps[len-1];
                }else{
                    // otherwise not matching then move i and lps will be 0
                    lps[i] = 0;
                    i += 1;
                }
            }
        }
    }

public:
    int strStr(string haystack, string needle) {
        int n = haystack.size(), m = needle.size();

        vector<int> lps(m, 0); 
        computeLPS(needle, lps, m);

        // apply KMP algo 
        int j = 0, i=0;
        while(i<n){
            // if both string match 
            if(haystack[i] == needle[j]){
                // move both ptr by 1 
                j++;
                i++;
            }else{  // not matching then 
                // using lps array point to previous lps length 
                if(j > 0)
                    j = lps[j-1];
                else    // othwise move to the next ptr of haystack 
                    i++;
            }
            // needle is found 
            if(j == m){
                return (i-m);
            }
        }
        return -1;
    }
};