#include<bits/stdc++.h>
using namespace std;

//Time complexity :- O(N)
//Space complexity :- O(1)

// Approach :-
// For finding the window with exactly k consonant, 
// we can find atLeast k consonant count and then subtract it from atleast k+1 consonant count 
// for find atLeast k consonant we can use sliding window
// we'll add the char in our window until we got all 5 vowels and at least k consonants
// Once we found that we'll try to shring that window and while doing that we can update the result until the window is valid
// the count of number of windows for valid window will be (n - right)


//link :- https://leetcode.com/problems/count-of-substrings-containing-every-vowel-and-k-consonants-ii/

class Solution {
private:
    bool isVowel(char ch){
        return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u');
    }

    bool isAllVowelPresent(vector<int> freq){
        return (freq['a'-'a']>0 && freq['e'-'a']>0 && freq['i'-'a']>0 && freq['o'-'a']>0 && freq['u'-'a']>0);
    }

    long long atLeast(string word, int k){
        long long res = 0;
        int consonant = 0, n = word.size(), left = 0;
        vector<int> freq(26, 0);

        for(int right=0; right<n; ++right){
            if(!isVowel(word[right]))
                consonant++;
            
            freq[word[right] - 'a']++;

            while(consonant >= k && isAllVowelPresent(freq)){
                res += (n - right);
                if(!isVowel(word[left]))
                    consonant--;
                
                freq[word[left] - 'a']--;
                left++;
            }
        }
        return res;
    }

public:
    long long countOfSubstrings(string word, int k) {
        return atLeast(word, k) - atLeast(word, k+1);
    }
};