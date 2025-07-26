#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(n)  
// Space complexity :- O(1)

// Approach :-  
// using majority element concept, use the counter system to count the votes for each candidate
// we'll have only two candidate that will have count greater than 1/3 of the array
// so we'll take two candidate only and start counting there votes
// As soon as other candidate comes in we'll decrement the vote of both candidate 
// at last we'll get two candidate which we'll cross verify again by checking wheather they are satsifying the crieteria or not 
// and put the one who is satisfing the need into an array 


// Link(gfg) :- https://www.geeksforgeeks.org/problems/majority-vote/1

class Solution {
  public:
    vector<int> findMajority(vector<int>& arr) {
        // Code here
        int n = arr.size(), cnt1 = 0, cnt2 = 0, num1 = -1, num2 = -1;
        
        for(int i=0; i<n; ++i){
            if(cnt1 == 0 && num2 != arr[i]){
                num1 = arr[i];
                cnt1 = 1;
            }
            else if(cnt2 == 0 && num1 != arr[i]){
                num2 = arr[i];
                cnt2 = 1;
            }
            else if(arr[i] == num1)
                cnt1++;
            else if(arr[i] == num2)
                cnt2++;
            else{
                cnt1--;
                cnt2--;
            }
        }
        if(num1 > num2){
            int temp = num1;
            num1 = num2;
            num2 = temp;
        }
        cnt1 = 0, cnt2 = 0;
        for(int i=0; i<n; ++i){
            if(arr[i] == num1)
                cnt1++;
            else if(arr[i] == num2)
                cnt2++;
        }
        vector<int> ans;
        if(cnt1 > n/3)      ans.push_back(num1);
        if(cnt2 > n/3)      ans.push_back(num2);
        return ans;
    }
};