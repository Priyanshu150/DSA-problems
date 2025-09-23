//Time complextiy :- O(n)
// Space complexity :- O(n)

// Approach :-  
// split the string for every '.' and check the required conditions 

// Link :- https://leetcode.com/problems/compare-version-numbers/

function compareVersion(version1: string, version2: string): number {
    const ver1 : string[] = version1.split(".");
    const ver2 : string[] = version2.split(".");

    const n : number = ver1.length, m : number = ver2.length;
    let i: number = 0, j : number = 0;

    while(i < n || j < m){
        let val1 : number = (i < n) ? Number(ver1[i++]) : 0;
        let val2 : number = (j < m) ? Number(ver2[j++]) : 0;

        if(val1 < val2)
            return -1;
        else if(val1 > val2)
            return 1;
    }
    return 0;
};