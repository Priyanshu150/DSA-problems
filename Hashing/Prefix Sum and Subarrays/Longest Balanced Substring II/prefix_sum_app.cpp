#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(n)
// Space complexity :- O(n)

// Approach :-   
// only 3 case will give us maximum length 
// case 1 :- all-equal char has max length 
// using counting method to find the longest subarray length 
// case 2 :- combination of 2 form the max length 
// use prefix sum to find the maximum length of 2 char 
// count the frequency of both char as long as they are conintuous 
// store the difference b/w them as a key, if the key is found again that mean a valid subarray exists 
// if a third char comes, reset the value and clear the map as it's break the sub-array 
// case 3 :- all 3 forms the max length 
// use the same technique use for 2 char length with the key as 
// key = (count1 - count2) + "_" + (count2 - count3)
// and use the same concept to find the subarray length 
// 

// Link :- https://leetcode.com/problems/longest-balanced-substring-ii/

class Solution {
private:
    int maxLength2Char(char ch1, char ch2, string &s, int &n){
        unordered_map<int,int> mp;
        int maxLen = 0, count1 = 0, count2 = 0;
        
        for(int i=0; i<n; ++i){
            // increment the count if ch1 or ch2 if present 
            if(s[i] == ch1){
                count1++;
            }
            else if(s[i] == ch2){
                count2++;
            }
            // otherwise reset the count and map if 3rd char is found which break the subarray 
            else{
                mp.clear();
                count1 = 0;
                count2 = 0;
                continue;
            }
            // both ch1 and ch2 equal till now 
            if(count1 == count2){
                maxLen = max(maxLen, count1 + count2);
            }
            // use prefix sum technique to calculate the maximum subarray
            // difference two char count can be considered as unique key 
            int diff = count1 - count2;

            // if key is present, find the length of subarray 
            if(mp.count(diff)){
                maxLen = max(maxLen, i - mp[diff]);
            }
            // otherwise store the key in map
            else{
                mp[diff] = i;
            }
        }
        return maxLen;
    }

public:
    int longestBalanced(string s) {
        int maxLen = 0, n = s.size();

        // case 1 :- all-equal char has max length 
        int count = 0;
        char prev = '#';

        for(int i=0; i<n; ++i){
            // count the continuous equal char 
            if(s[i] == prev){
                count++;
            }
            // reset the count if different char found 
            else{
                prev = s[i];
                count = 1;
            }
            // maximize the count for single char 
            maxLen = max(maxLen, count);
        }

        // case 2 :- combination of 2 form the max length 
        maxLen = max(maxLen, maxLength2Char('a', 'b', s, n));
        maxLen = max(maxLen, maxLength2Char('b', 'c', s, n));
        maxLen = max(maxLen, maxLength2Char('a', 'c', s, n));

        // case 3 :- all 3 forms the max length 
        unordered_map<string, int> mp;
        int count1 = 0, count2 = 0, count3 = 0;

        for(int i=0; i<n; ++i){
            // count the char's count till curr index 
            if(s[i] == 'a'){
                count1++;
            }
            else if(s[i] == 'b'){
                count2++;
            }
            else{
                count3++;
            }
            // count of all 3 char are equal till current index
            if(count1 == count2 && count2 == count3){
                maxLen = max(maxLen, count1 + count2 + count3);
            }
            // use prefix sum technique to calculate the maximum subarray
            // difference two char count can be considered as unique key 
            // find 2 diff b/w 3 char and make a key based on that 
            int diff1 = count1 - count2;
            int diff2 = count2 - count3;
            string key = to_string(diff1) + "_" + to_string(diff2);
            
            // if key is present then find the array length and maximize it 
            if(mp.count(key)){
                maxLen = max(maxLen, i - mp[key]);
            }
            // otherwise save the key and index 
            else{
                mp[key] = i;
            }
        }
        return maxLen;
    }
};