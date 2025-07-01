#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(n)
// Space complexity :- O(26)

// Approach :-  
// Use sliding window approach, maintain a fixed window of size k 
// for fixed window calucalte the distinct element in that window
// if the cnt is equal to k-1 that means it'll contribute to our answer increment ans cnt by 1
// maintain a freq array to count the number of char and their frequency
// using that freq array calculate the number of distinct element in the window


// links :- https://www.geeksforgeeks.org/problems/substrings-of-length-k-with-k-1-distinct-elements/1

class Solution {
  public:
    int substrCount(string &s, int k) {
        // code here
        vector<int> freq(26, 0);
        int left = 0, n = s.size(), distinct = 0, res = 0;
        
        for(int right = 0; right < n; ++right){
            freq[s[right] - 'a'] += 1;
            if(freq[s[right] - 'a'] == 1)
                distinct++;
            
            if(right >= k-1){
                if(distinct == k-1)
                    res += 1;
                
                freq[s[left] - 'a'] -= 1;
                if(freq[s[left] - 'a'] == 0)
                    distinct--;
                ++left;
            }
        }
        return res;
    }
};