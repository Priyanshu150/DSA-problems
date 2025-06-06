#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(n*m)
// Space complexity :- O(1)

// Approach :- 
// Hash the pattern (m length) to form a value 
// traverse the text string and calculate the hash value for next m length
// if the hash value is same as previously computed hash value of pattern string 
// then match the char to confirm wheather that string is correct or not
// if it is then push the index+1 to the result array 

// Link :- https://www.geeksforgeeks.org/problems/search-pattern-rabin-karp-algorithm--141631/1

class Solution{
    public:
        vector <int> search(string pattern, string text){
            //code here.
            int sum = 0, n = text.size(), m = pattern.size();
            
            for(auto ch: pattern)
                sum += (ch-'a');
            
            int i=0, j = 0, subSum = 0;
            
            while(j<m){
                subSum += (text[j]-'a');
                j++;
            }
            vector<int> ans;
            if(subSum == sum && text.substr(0, m) == pattern)
                ans.push_back(1);
            
            while(j<n){
                subSum -= (text[i++]-'a');
                subSum += (text[j++]-'a');
                if(subSum == sum && text.substr(i, m) == pattern)
                    ans.push_back(i+1);
            }
            return ans;
        }
     
};