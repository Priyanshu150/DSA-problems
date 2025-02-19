#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(2^n)
// Space complexity :- O(n)

// Approach :-  
// try creating every sequence and take first a -> b -> c accordingly which will give us lexiographically smallest order
// at every sequence which ever is previous char take other two char from that 
// count each string of size n once we get cnt == k that will be our answer

// Link :- https://leetcode.com/problems/the-k-th-lexicographical-string-of-all-happy-strings-of-length-n/

class Solution {
    private:
    int size, num, cnt;
    char arr[3] = {'a', 'b', 'c'};

    string solve(string temp, char prev){
        if(temp.size() == size){
            cnt += 1;
            if(cnt == num)      return temp;
            return "";
        }
        
        for(auto ch: arr){
            if(ch != prev){
                string res = solve(temp + ch, ch);
                if(res != "")
                    return res;
            }
        }
        return "";
    }

public:
    string getHappyString(int n, int k) {
        size = n, num = k, cnt = 0;
        return solve("", '#');
    }
};
