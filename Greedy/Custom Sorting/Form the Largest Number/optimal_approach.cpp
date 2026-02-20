#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(n*log(n))
// Space complexity :- O(n)

// Approach :-  
// use custom sorting technique to sort the string from higher to lower 
// while sorting two number for them into string and combine both in all the manner
// s1+s2 and s2+s1, after that check which is larger 
// and form the answer from those numbers 



//Link :- https://www.geeksforgeeks.org/problems/largest-number-formed-from-an-array1117/1

class Solution {
  public:
    string findLargest(vector<int> &arr) {
        // sort the array based on string comparision 
        sort(arr.begin(), arr.end(), [&](int &num1, int &num2){
            string s1 = to_string(num1);
            string s2 = to_string(num2);
            
            // combine both the string in differenct formation and check which is largest 
            return (s1+s2) > (s2+s1);
        });

        string res = "";
        
        // add each number to the res string by converting each number to string
        for(auto num: arr){
            res += to_string(num);
        }
        
        // result string is all zeros then reduce it and make it '0' only 
        while(res.size() > 1 && res[0] == '0'){
            res = res.substr(1);
        }
        return res;
    }
};