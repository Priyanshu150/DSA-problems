//Time complextiy :- O(n*len)
// Space complexity :- O(1)

// Approach :- 
// traverse on the each string and check if the char is present in that string or not 


// Link :- https://leetcode.com/problems/find-words-containing-character/

/**
 * @param {string[]} words
 * @param {character} x
 * @return {number[]}
 */


var findWordsContaining = function(words, x) {
    let ans = []
    for(let i=0; i<words.length; ++i){
        if(words[i].includes(x)){
            ans.push(i);
        }
    }
    return ans;
};