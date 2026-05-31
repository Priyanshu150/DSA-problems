#include <bits/stdc++.h>
using namespace std;

//Time complextiy :- O(n)
// Space complexity :- O(1)

// Approach :- 
// for every number,  check if continuous number can form the sum 
// if it exceeds the target then not possible 
// if continous number form the target then it's possible 


// Link :-  https://www.geeksforgeeks.org/problems/consecutive-numbers-for-sum3132/1

class Solution {
  public:
    bool isSumOfConsecutive(int n) {
        
        for(int i=1; i<=(n/2); ++i){
            int num = i;
            int sum = i;
            
            while(sum <= n){
                if(sum == n)
                    return true;
                
                num += 1;
                sum += num;
            }
        }
        
        return false;
    }
};