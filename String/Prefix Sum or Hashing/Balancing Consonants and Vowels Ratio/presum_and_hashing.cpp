#include<bits/stdc++.h>
using namespace std;

//Time complexity :- O(n)
//Space complexity :- O(n)

// Approach :-
// For find the balance b/w consonants and vowels we can use the sum 
// if the sum of the subbarray of consonants and vowels are same then we can say that it's balanced
// for finding the sum we'll add +1 for vowels and -1 for consonants respectively
// we can use hashing to store the sum inorder to find the subarray sum using prefix-sum approach


//link :- https://www.geeksforgeeks.org/problems/balancing-consonants-and-vowels-ratio/1

class Solution {
  public:
    int countBalanced(vector<string>& arr) {
        // code here
        int sum = 0, res = 0;
        unordered_map<int,int> mp;
        mp[sum] = 1;
        
        for(auto word: arr){
            for(auto ch: word){
                if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
                    sum += 1;
                else 
                    sum -= 1;
            }
            if(mp.count(sum))
                res += mp[sum];
            
            mp[sum] += 1;
        }
        return res;
    }
};