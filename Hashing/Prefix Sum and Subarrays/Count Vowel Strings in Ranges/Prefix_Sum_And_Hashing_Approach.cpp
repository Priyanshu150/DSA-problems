#include<bits/stdc++.h>
using namespace std;

//Time complexity :- O(N)       //where n is the size of words array
//Space complexity :- O(N)      //using map to store every index of words

//Approach :- 
//Precompute the prefix sum of strings that start and end with vowels.
//Use unordered_set to store vowels.
//Check if the first and last characters of the string are present in the vowels set.
//Subtract prefix sum for range [l-1, r] to find the number of strings starting and ending with vowels.

class Solution {
private:
    bool isVowel(char ch){
        return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u');
    }

public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        unordered_map<int, int> mp;
        int n = words.size(), sum = 0;
        mp[-1] = 0;     //or we can write -> mp[-1] = sum;

        for(int ind=0; ind<n; ++ind){
            int sz = words[ind].size();
            if(isVowel(words[ind][0]) && isVowel(words[ind][sz-1]))
                sum += 1;
            
            mp[ind] = sum;
        }
        vector<int> ans;

        for(auto query: queries){
            int l = query[0], r = query[1];
            ans.push_back(mp[r] - mp[l-1]);
        }
        return ans;
    }
};