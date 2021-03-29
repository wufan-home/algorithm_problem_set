/*
	Follow up for N-Queens problem.

	Now, instead outputting board configurations, return the total number of distinct solutions.
*/

class Solution {
public:
    int totalNQueens(int n) {
        size = n;
        unavailableLines.resize(n, -1);
        countNQueens(0);
        return totalNumber;
    }
    
private:
    void countNQueens(int l)
    {
        if(l == size)
            ++totalNumber;
        else
        {
            for(int c = 0; c < size; ++c)
            {
                if(find(unavailableLines.begin(), unavailableLines.end(), c) != unavailableLines.end() || 
                    checkLeanLines(l, c))
                    continue;
                    
                unavailableLines[l] = c;
                countNQueens(l + 1);
                unavailableLines[l] = -1;
            }
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

    int size;
    int totalNumber;
};
