#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(k)
// Space complexity :- O(n)

// Approach :-  
// Use array to store the incoming value
// Traverse the back 'k' elements of the array and find the product

// Link :- https://leetcode.com/problems/product-of-the-last-k-numbers/

class ProductOfNumbers {
    private:
    vector<int> nums;

public:
    ProductOfNumbers() {
        nums.clear();
    }
    
    void add(int num) {
        nums.push_back(num);
    }
    
    int getProduct(int k) {
        int n = nums.size(), ind = n-1, prod = 1;
        for(int i=0; i<k; ++i){
            prod *= nums[ind];
            ind--;
        } 
        return prod;
    }
};