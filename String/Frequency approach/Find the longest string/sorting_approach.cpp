#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(N*log(N)*L)
// Space complexity :- O(N*log(N)*L)

// Approach :-  
// sort the array based on the size of the string and if equal then based on lexiographically smallest 
// traverse on the each word in the sting if it's single char then update in the map as {ch, true}
// for every other word, check wheather after removing last char from word if that exist or not 
// if it and does and is marked as true then update the answer 
// mark only those string as true in hash map whose prefix exists 

// links :- https://www.geeksforgeeks.org/problems/find-the-longest-string--170645/1

class Solution {
  public:
    string longestString(vector<string> &words) {
        // code here
        string res = "";
        unordered_map<string, int> mp;
        sort(words.begin(), words.end(), [&](string &s1, string &s2){
            if(s1.size() == s2.size())
                return s1 < s2;
            return s1.size() < s2.size();
        });
        
        for(auto word: words){
            if(word.size() == 1){
                mp[word] = true;
                if(res == "")  
                    res = word;
            }
            else{
                string temp = word;
                temp.pop_back();
                
                if(mp.count(temp) && mp[temp]){
                    mp[word] = true;
                    if(res.size() < word.size())
                        res = word;
                }
                else        mp[word] = false;
            }
        }
        return res;
    }
};