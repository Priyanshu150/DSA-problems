#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(n)  
// Space complexity :- O(7)

// Approach :-
// store the mapping of all the basic roman number to integer in the map
// traverse on the give string and form the number 
// if s[i-1] < s[i], then add mp[s[i-1]] - mp[s[i]] to answer 
// otherwise mp[s[i]] 


// Link :- https://www.geeksforgeeks.org/problems/roman-number-to-integer3201/1

class Solution {
  public:
    int romanToDecimal(string &str) {
        // code here
        map<char,int> mp;
        int n = str.size(), sum = 0, i=0;
        
        mp.insert({'I',1});
        mp.insert({'V',5});
        mp.insert({'X',10});
        mp.insert({'L',50});
        mp.insert({'C',100});
        mp.insert({'D',500});
        mp.insert({'M',1000});
        
        while(i<n){
            if(i+1<n && mp[str[i]] < mp[str[i+1]]){
                sum += (mp[str[i+1]] - mp[str[i]]);
                i+=2;
            }
            else{
                sum += mp[str[i]];
                i++;
            }
        }
        return sum;
    }
};