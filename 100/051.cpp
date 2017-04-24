/*
	The n-queens puzzle is the problem of placing n queens on an n×n chessboard such that no two queens attack each other.
	
	Given an integer n, return all distinct solutions to the n-queens puzzle.

	Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space respectively.

	For example,
	There exist two distinct solutions to the 4-queens puzzle:

	[
	 [".Q..",  // Solution 1
	  "...Q",
	  "Q...",
	  "..Q."],

	 ["..Q.",  // Solution 2
	  "Q...",
	  "...Q",
	  ".Q.."]
	]
	Show Tags
	Show Similar Problems
*/

class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        size = n;
        unavailableLines.resize(n, -1);
        getTableByLine(0);
        
        return tables;
    }
    
private:
    void getTableByLine(int l)
    {
        if(l == size)
        {
            vector<string> table;
            for(int i = 0; i < l; ++i)
            {
                string line(l, '.');
                line[unavailableLines[i]] = 'Q';
                table.push_back(line);
            }
            tables.push_back(table);
            return;
        }
        
        for(int i = 0; i < size; ++i)
        {
            if(find(unavailableLines.begin(), unavailableLines.end(), i) != unavailableLines.end() || 
                checkLeanLines(l, i))
                continue;
                
            unavailableLines[l] = i;
            getTableByLine(l + 1);
            unavailableLines[l] = -1;
        }
    }

    bool checkLeanLines(int l, int c)
    {
        for(int i = 0; l - i >= 0; ++i)
        {
            if((c - i >= 0 && c - i == unavailableLines[l - i]) ||
                (c + i < size && c + i == unavailableLines[l - i]))
                return true;	
        }
       
        return false;
    }

   vector<int> unavailableLines;
   vector<vector<string>> tables;
   int size;
};
