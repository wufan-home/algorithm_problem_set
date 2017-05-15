/*
	  Given an index k, return the kth row of the Pascal's triangle.

	  For example, given k = 3,
	  Return [1,3,3,1].

	  Note:
	  Could you optimize your algorithm to use only O(k) extra space? 
*/

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> line(rowIndex + 1, 1);
        int half = rowIndex / 2;
        for(int i = 1; i <= half; ++i)
        {
            long long temp = line[i - 1];
            temp *= (rowIndex - i + 1);
            temp /= i;
            line[i] = (int)temp;
        }
        
        for(int i = half + 1; i <= rowIndex; ++i)
            line[i] = line[rowIndex - i];
            
        return line;
    }
};
