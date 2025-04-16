#include<bits/stdc++.h>
using namespace std;

//Time complexity :- O(N)
//Space complexity :- O(1)

//Approach :- 
//Apply the standard two pointer approach
// For calculating the result, count the ouccrence of pair and mulitply the count
// If both are same number then apply the formula of sum of first N natural numbers

//Link :- https://www.geeksforgeeks.org/problems/pair-with-given-sum-in-a-sorted-array4940/1

class Solution {
  public:
    int countPairs(vector<int> &arr, int target) {
        // Complete the function
        int n = arr.size(), lt(0), rt(n-1), res(0);
        
        while(lt < rt){
            int sum = arr[lt] + arr[rt];
            if(sum == target){
                int c1=0, c2=0, ele1=arr[lt], ele2=arr[rt];
                
                while(lt <= rt && arr[lt] == ele1){
                    c1++;
                    lt++;
                }
                while(lt <= rt && arr[rt] == ele2){
                    c2++;
                    rt--;
                }
                res += (ele1 == ele2) ? (c1*(c1-1))/2 : (c1*c2);
            }
            else if(sum < target)       lt++;
            else    rt--;
        }
        return res;
    }
};