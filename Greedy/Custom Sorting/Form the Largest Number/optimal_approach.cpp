#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(n*log(n))
// Space complexity :- O(n)

// Approach :-  
// use custom sorting technique to sort the string from higher to lower 
// and form the answer from those numbers 


//Link :- https://www.geeksforgeeks.org/problems/largest-number-formed-from-an-array1117/1

class Solution {
  private:
    static bool comp(string &s1, string &s2){
        return (s1 + s2) > (s2  + s1);
    }
  
  public:
    string findLargest(vector<int> &arr) {
        // code here
        vector<string> temp;
        
        for(auto num: arr)
            temp.push_back(to_string(num));
        
        sort(begin(temp), end(temp), comp);
        
        string res = "";
        for(auto str: temp)
            res += str;
       
        if(res.size()>1 && res[0] == '0')
            return "0";
        
        return res;
    }
};