#include<bits/stdc++.h>
using namespace std;

// Time complexity :- O(n*log(n))                 
// Space complexity :- O(1)              

// Approach :-  
// sort the given number and form a 2 num in string format 
// take alternating number from the sort array to form to numbers
// this way we'll get the 2 minimum numbers 
// after getting those number add them using string operation 

// link :- https://www.geeksforgeeks.org/problems/minimum-sum4058/1

class Solution {
  private:
    string addNumber(string &num1, string &num2){
        string res = "";
        int carry = 0, ind1 = num1.size()-1, ind2 = num2.size()-1;
        
        while(ind1 >= 0 || ind2 >= 0 || carry > 0){
            int sum = carry, ld = 0;
            
            if(ind1 >= 0)
                sum += (num1[ind1] - '0');
            
            if(ind2 >= 0)
                sum += (num2[ind2] - '0');
            
            ld = sum%10;
            if(sum/10 > 0)      carry = 1;
            else    carry = 0;
            
            res += (ld+'0');
            ind1--;
            ind2--;
        }   
        reverse(res.begin(), res.end());
        
        while(res[0] == '0')
            res = res.substr(1);
        
        return res;
    }
  
  public:
    string minSum(vector<int> &arr) {
        // code here
        sort(arr.begin(), arr.end());
        int n = arr.size();
        string num1 = "", num2 = "";
        
        for(int i=0; i<n; ++i){
            if(i%2)     num2 += (arr[i]+'0');
            else        num1 += (arr[i]+'0');
        }
        return addNumber(num1, num2);
    }
};