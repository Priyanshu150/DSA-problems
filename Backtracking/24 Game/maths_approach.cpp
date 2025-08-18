#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(1)
// Space complexity :- O(1)

// Approach :-  
// pick any two number and apply operation on those 
// there can be 8 possibilities {a+b, a-b, b-a, a/b, b/a, a*b}
// since division is not integer divison instead actual one so we've to take double to handle the cases
// take one of the possiblities result and move from 4 -> 3 -> 2 -> 1 numbers 
// when 1 number left that will be bases check the abs(24 - arr[0]) <= epsilon value then it's possible
// epsilon is a value use to compare the use to compare smallest diffference b/w two number 
// to determin wheather they are equal or not 
// example, 7.99 will be equal to 8 approx, if we find the diff and if it's less than epsilon 
// then we can say that they are approx equal
// we're handling this because of the fact that we're handling double numbers 
// use backtracking to explore all the possibilites 



//Link :- https://leetcode.com/problems/24-game/

class Solution {
private:
    double e = 1e-2;

    bool solve(vector<double> &arr){
        int n = arr.size();
        if(n == 1){
            return abs(24 - arr[0]) <= e;
        }

        for(int i=0; i<n; ++i){
            for(int j=0; j<n; ++j){
                if(i == j)
                    continue;
                
                vector<double> temp;
                for(int k=0; k<n; ++k){
                    if(i != k && j != k)
                        temp.push_back(arr[k]);
                }
                double a = arr[i], b = arr[j];

                vector<double> possibilities = {a+b, a-b, b-a, a*b};
                if(abs(a) > 0)      possibilities.push_back(b/a);
                if(abs(b) > 0)      possibilities.push_back(a/b);

                for(auto possibility: possibilities){
                    temp.push_back(possibility);
                    if(solve(temp) == true)
                        return true;
                    
                    temp.pop_back();
                }
            }
        }
        return false;
    }

public:
    bool judgePoint24(vector<int>& cards) {
        vector<double> arr;
        for(auto card: cards)
            arr.push_back(card*1.0);
        
        return solve(arr);
    }
};