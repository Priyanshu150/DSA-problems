#include<bits/stdc++.h>
using namespace std;

//Time complexity :- O(10*N*5^(N-1))       
//Space complexity :- O(10*N*5^(N-1))    

//Approach :-
// create a data structure which represents from a particular number where we can traverse next 
// try generating all possible string and put it into the set which will eliminate the duplicate 
// the base case will be when the length of string becomes equal to n the store it into set and return

// Link :- https://www.geeksforgeeks.org/problems/mobile-numeric-keypad5456/1

class Solution {
  private:
    unordered_set<string> res;
    
    vector<vector<string>> keypad = {{"0", "8"}, {"1", "2", "4"}, {"1","2","3","5"},
        {"2","3","6"}, {"1","4","5","7"}, {"2","4","5","6","8"}, {"3","5","6","9"},
        {"4","7","8"}, {"0","5","7","8","9"}, {"6","8","9"}
    };
    
    void solve(int num, string str, int n){
        if(str.size() == n){
            res.insert(str);
            return;
        }
        
        for(auto ch: keypad[num]){
            str += ch;
            solve(stoi(ch), str, n);
            str.pop_back();
        }
    }
  
  public:
    int getCount(int n) {
        // code here
        for(int i=0; i<=9; ++i)
            solve(i, "", n);
        return res.size();
    }
};