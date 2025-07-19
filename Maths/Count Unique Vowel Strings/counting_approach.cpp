#include<bits/stdc++.h>
using namespace std;

//Time complexity :- O(n)
//Space complexity :- O(5)

// Approach :-
// count the frequency of each vowels present in the string 
// Also count the distinct vowels in the string and find the factorial of that number 
// traverse on the every frequency of vowel if it's greater than 2 then multiply freq with answer 


//Link :- https://www.geeksforgeeks.org/problems/count-unique-vowel-strings/1

class Solution {
  private:
    int factorial(int num){
        int fact = 1;
        
        for(int i=1; i<=num; ++i)
            fact *= i;
        
        return fact;
    }
  
  public:
    int vowelCount(string& s) {
        // code here
        unordered_map<char,int> mp;
        
        for(auto ch: s){
            if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u'){
                mp[ch] += 1;
            }
        }
        int ans = 0, totalVowels = mp.size();
        if(totalVowels == 0)    return 0;
        
        ans = factorial(totalVowels);
        for(auto it: mp){
            if(it.second > 1){
                ans = ans*it.second;
            }
        }
        return ans;
    }
};