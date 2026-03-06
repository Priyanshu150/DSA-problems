import java.util.*

//Time complextiy :- O(sizeof(s) + sizeof(p))
// Space complexity :- O(26)


class Solution {
    private boolean matchFreq(int[] freq1, int[] freq2) {
        for (int i = 0; i < 26; i++) {
            if (freq2[i] > freq1[i]) {  // freqs >= freqp
                return false;
            }
        }
        return true;
    }
    
    public String minWindow(String s, String p) {
        int[] freqs = new int[26];
        int[] freqp = new int[26];
        
        // count the freq of char in string p 
        for(char ch: p.toCharArray()){
            freqp[ch - 'a'] += 1;
        }
        
        int m = s.length(), left = 0;
        int start = -1, end = -1, minLen = m+1;
        
        // maintain a sliding window from [left, right]
        for(int right=0; right < m; ++right){
            // update the freq of string s 
            freqs[s.charAt(right) - 'a'] += 1;
            
            // util we've string p in substring of s try to decrease the size of window
            while(left <= right && matchFreq(freqs, freqp)){
                // update the size if minimum window is found 
                if(minLen > (right - left + 1)){
                    minLen = right - left + 1;
                    start = left;
                    end = right;
                }
                // decrement the repesective char freq 
                freqs[s.charAt(left) - 'a'] -= 1;
                ++left;
            }
        }
        // no substring found 
        if(minLen == m+1){
            return "";
        }
        // othewise the substring will be from start to end 
        return s.substring(start, end + 1);
    }
}