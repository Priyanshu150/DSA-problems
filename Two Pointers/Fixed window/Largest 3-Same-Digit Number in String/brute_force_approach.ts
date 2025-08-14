
//Time complexity :- O(n*3)
//Space complexity :- O(n)

// Approach :-
// Try every subarray of 3 length if the are all equal then consider it as one of answer 


//link :- https://leetcode.com/problems/largest-3-same-digit-number-in-string/

function largestGoodInteger(num: string): string {
    let res = "";

    for(let i=0; i<num.length-2; ++i){
        let temp = num.substring(i, i+3);
        if(temp[0] === temp[1] && temp[1] === temp[2]){
            if(res === "" || (temp[0] > res[0]))
                res = temp;
        }
    }
    return res;
};