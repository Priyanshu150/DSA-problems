#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(2^n)
// Space complexity :- O(2^n)

// Approach :-  
// take a queue and push (a, b, c) initial char into the queue
// for every element in a queue, try creating the two string which can we obtained by adding other two character which are present at last current string
// create every possible sequence by following this approach, and the count the number of node having length n
// once the cnt is reached to k return that string as answer
// don't process the string grater than length of n and if we didn't found kth string return ""

// Link :- https://leetcode.com/problems/the-k-th-lexicographical-string-of-all-happy-strings-of-length-n/

class Solution {
    public:
    string getHappyString(int n, int k) {
        int cnt = 0;
        queue<string> q;

        q.push("a");
        q.push("b");
        q.push("c");

        while(!q.empty()){
            string curr = q.front();
            q.pop();

            if(curr.size() == n){
                cnt += 1;
                if(cnt == k)
                    return curr;
                
                continue;
            }
            string first = curr, second = curr;

            if(curr.back() == 'a'){
                first += 'b';
                second += 'c';
            }
            else if(curr.back() == 'b'){
                first += 'a';
                second += 'c';
            }
            else{
                first += 'a';
                second += 'b';
            }
            q.push(first);
            q.push(second);
        }
        return "";
    }
};