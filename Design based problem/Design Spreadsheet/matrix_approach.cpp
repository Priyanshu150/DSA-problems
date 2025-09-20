#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(len(formual))
// Space complexity :- O(N*26)

// Approach :-  
// we'll use matrix to store the information 
// In add and remove function, we can update and remove the value 
// In getValue, we can convert it into proper format and then calculate the result accordingly

// links :- https://leetcode.com/problems/design-spreadsheet/

class Spreadsheet {
    vector<vector<int>> excel;

public:
    Spreadsheet(int rows) {
        excel.resize(rows, vector<int> (26, 0));
    }

    pair<int,int> rowAndColValue(string cell){
        char row = cell[0];
        string col = cell.substr(1);
        int colVal = row - 'A';
        int rowVal = stoi(col) - 1;

        return {rowVal, colVal};
    }
    
    void setCell(string cell, int value) {
        auto [rowVal, colVal] = rowAndColValue(cell);
        excel[rowVal][colVal] = value;
    }
    
    void resetCell(string cell) {
        auto [rowVal, colVal] = rowAndColValue(cell);
        excel[rowVal][colVal] = 0;
    }
    
    int getValue(string formula) {
        bool changed = false;
        int n = formula.size();
        string str1 = "", str2 = "";

        for(int i=1; i<n; ++i){
            if(formula[i] == '+')
                changed = true;
            else if(changed)
                str2 += formula[i];
            else 
                str1 += formula[i];
        }

        if(isdigit(str1[0]) && isdigit(str2[0]))
            return stoi(str1) + stoi(str2);
        
        if(isdigit(str1[0])){
            auto [rowVal1, colVal1] = rowAndColValue(str2);
            return stoi(str1) + excel[rowVal1][colVal1];
        }
        
        if(isdigit(str2[0])){
            auto [rowVal, colVal] = rowAndColValue(str1);
            return stoi(str2) + excel[rowVal][colVal];
        }

        auto [rowVal, colVal] = rowAndColValue(str1);
        auto [rowVal1, colVal1] = rowAndColValue(str2);

        return excel[rowVal][colVal] + excel[rowVal1][colVal1];
    }
};

/**
 * Your Spreadsheet object will be instantiated and called as such:
 * Spreadsheet* obj = new Spreadsheet(rows);
 * obj->setCell(cell,value);
 * obj->resetCell(cell);
 * int param_3 = obj->getValue(formula);
 */
