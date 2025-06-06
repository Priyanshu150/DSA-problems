#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(2*n*26)
// Space complexity :- O(26)

// Approach :- 
// maintain a freq array for the char
// traverse from left to right and push the curr_char in strng t and decrement the frequency of that char
// find the smallest char on the right side of curr_char using frequency array
// until the last char of string t is smaller than smallest char till then push them into result string
// after traversing all the char at last push all the char of string t into res 

// Link :- https://www.geeksforgeeks.org/problems/search-pattern-rabin-karp-algorithm--141631/1

class Solution {
private:
    inline char smallest(vector<int> &freq){
        for(int i=0; i<26; ++i){
            if(freq[i] > 0)
                return char(97+i);
        }
        return 'z';
    }

public:
    string robotWithString(string s) {
        int n = s.size(), ind = 0;
        vector<int> freq(26, 0);

        for(int i=0; i<n; ++i){
            freq[s[i] - 'a']  += 1;
        }
        string t, res;

        while(ind < n){
            t.push_back(s[ind]);
            freq[s[ind] - 'a'] -= 1;

            while(!t.empty() && t.back() <= smallest(freq)){
                res.push_back(t.back());
                t.pop_back();
            }
            ++ind;
        }
        return res;
    }
};