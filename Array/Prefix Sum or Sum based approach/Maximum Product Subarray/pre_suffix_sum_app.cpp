#include<bits/stdc++.h>
using namespace std;

//Time complexity :- O(n)   
//Space complexity :- O(1)

// Approach :- 
// observation1 :- If all the numbers are +ve then overall product will be maximum
// observation2 :- If even number of -ve element are there then again product of whole array will be maximum
// observation3 :- If odd number of -ve elements are present then check the product befor and after that number  and maximum will be answer , repeat this for all -ve element 
// observation4 :- if there are 0s present, then 0s can be considered as a break point and the arrays before and after it can be considered as seprate 
// hence find the maximum suffix or prefix product value by deleting the current element
// whenever our prod variable becomes 0, then reset the value to 1 

//Link :- https://www.geeksforgeeks.org/problems/maximum-product-subarray3604/1

class Solution {
  public:
    int maxProduct(vector<int> &arr) {
        int n = arr.size(), res = INT_MIN;
        int prefixProd = 1, suffixProd = 1;
        
        
        for(int i=0; i<n; ++i){
            // reset the value of prefix prod to 1 when it becomes 0
            if(prefixProd == 0)
                prefixProd = 1;
            
            // reset the value of suffix prod to 1 when it becomes 0
            if(suffixProd == 0)
                suffixProd = 1;
            
            // find the product of prefix & suffix 
            prefixProd *= arr[i];
            suffixProd *= arr[n-i-1];
            
            // update the maximum answer 
            res = max({res, prefixProd, suffixProd});
        }
        return res;
    }
};