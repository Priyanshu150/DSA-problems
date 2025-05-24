//Time complextiy :- O(n*len)
// Space complexity :- O(1)

// Approach :- 
// traverse on the each string and check if the char is present in that string or not 


function findWordsContaining(words: string[], x: string): number[] {
    let ans: number[] = [];

    for(let i=0; i<words.length; ++i){
        if(words[i].includes(x)){
            ans.push(i);
        }
    }
    return ans;
};