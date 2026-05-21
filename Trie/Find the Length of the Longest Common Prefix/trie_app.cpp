#include<bits10_1.h>
using namespace std; 

// Time complexity :- O(n*sz + m*sz)
// Space complexity :- O(n*sz)

// Approach :- 
// store the first array digits into the trie 
// using second array's digit search the longest prefix using trie 


// Links :-https://leetcode.com/problems/find-the-length-of-the-longest-common-prefix/

class Trie{
  private:
    Trie* children[10];
  
  public:
    // contructor 
    Trie(){
        // intialize all the child with null 
        for(int i=0; i<10; ++i){
            children[i] = nullptr;
        }
    }

    // check if next node is present or not 
    bool isPresent(char digit, Trie* dict){
        return (dict -> children[digit - '0'] != nullptr);
    }

    // create a new node 
    void createNode(char digit, Trie* dict){
        dict -> children[digit - '0'] = new Trie();
    }

    // find the address of next node 
    Trie* findNext(char digit, Trie* dict){
        return dict -> children[digit - '0'];
    }
};

class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        int n = arr1.size();
        Trie* dict = new Trie();

        // traverse on the first array : arr1
        for(int i=0; i<n; ++i){
            Trie* temp = dict;
            string digit = to_string(arr1[i]);
            int sz = digit.size();

            // add the current number into the trie 
            for(int ind=0; ind<sz; ++ind){
                if(!temp -> isPresent(digit[ind], temp)){
                    temp -> createNode(digit[ind], temp);
                }

                temp = temp -> findNext(digit[ind], temp);
            }
        }
        int maxLen = 0;
        int m = arr2.size();

        // traverse on the first array : arr2
        for(int i=0; i<m; ++i){
            Trie* temp = dict;
            string digit = to_string(arr2[i]);
            int sz = digit.size(), prefixCnt = 0;

            // match the prefix from arr2 
            for(int ind=0; ind<sz; ++ind){
                // check if the address is presnet or now 
                if(!temp -> isPresent(digit[ind], temp)){
                    break;
                }
                prefixCnt += 1;
                temp = temp -> findNext(digit[ind], temp);
            }
            // update the max prefix length
            maxLen = max(maxLen, prefixCnt);
        }
        return maxLen;
    }
};
