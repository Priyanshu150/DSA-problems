#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(k)
// Space complexity :- O(n)

// Approach :-  
// Calculate the prefix product array using the number coming into the stream 

// Add operation approach :- 
// Find the last number in the stream and multiply it with current number and put it into the stream
// If the last number in the stream is 0 then put the current number in the stream which means rest the product
// If the current number is 0 put prod 0 into the stream
// maintain an index where last time zero occured 

// get product approach (int k) :- 
// (concept) product b/w index i to j is equal to (product till index j / product till index i ) 
// i = size-1, j = size-1-k will be the current window for us according to the sitution
// if last_index_of_zero > j then the product will be 0
// if prod at index j is 0 then ans will be product at index i
// else use the concept to calculate the answer


// Link :- https://leetcode.com/problems/product-of-the-last-k-numbers/

class ProductOfNumbers {
    private:
    int size, last_zero_ind;
    vector<int> prodArr;

public:
    ProductOfNumbers() {
        size = 1;
        last_zero_ind = -1;
        prodArr.push_back(1);
    }
    
    void add(int num) {
        int prevNum = prodArr[size-1];
        if(num == 0){
            prodArr.push_back(0);
            last_zero_ind = size;
        }
        else if(prevNum == 0)
            prodArr.push_back(num);
        else
            prodArr.push_back(prevNum * num);
        
        ++size;
    }
    
    int getProduct(int k) {
        int i = size-1, j = size - k - 1;
        if(last_zero_ind > j)
            return 0;
        else if(prodArr[j] == 0)
            return prodArr[i];
        
        return prodArr[i] / prodArr[j];
    }
};