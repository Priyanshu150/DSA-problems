#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(n*log(n))  
// Space complexity :- O(1)

// Approach :-
// sort the timing of the array, find the min time which will be min of all the consecutive timings
// to find the timing for round clock, take the addition of (first time - 0) and (24 - last time)


// Link :- https://www.geeksforgeeks.org/problems/difference-check/1

class Solution {
  private:
    int convertToDigit(char d1, char d2){
        return (d1-'0')*10 + (d2-'0');
    }
  
    int diff(string t1, string t2){
        int sec1 = convertToDigit(t1[0], t1[1])*3600 + convertToDigit(t1[3], t1[4])*60 
                + convertToDigit(t1[6], t1[7]);
        int sec2 = convertToDigit(t2[0], t2[1])*3600 + convertToDigit(t2[3], t2[4])*60 
                + convertToDigit(t2[6], t2[7]);;
        return sec2 - sec1;
    }
  
  public:
    int minDifference(vector<string> &arr) {
        // code here
        int n = arr.size(), res = 0;
        sort(arr.begin(), arr.end());
        res = diff("00:00:00", arr[0]) + diff(arr[n-1], "24:00:00");
        
        for(int i=1; i<n; ++i){
            res = min(res, diff(arr[i-1], arr[i]));
        }
        return res;
    }
};
