/*
	Given a triangle, find the minimum path sum from top to bottom. Each step you may move to adjacent numbers on the row below.

	For example, given the following triangle

	[
		 [2],
		[3,4],
	   [6,5,7],
	  [4,1,8,3]
	]

	The minimum path sum from top to bottom is 11 (i.e., 2 + 3 + 5 + 1 = 11).

	Note:
	Bonus point if you are able to do this using only O(n) extra space, where n is the total number of rows in the triangle. 
*/

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        if(triangle.empty())
            return INT_MIN;

        vector<int> levelSums(triangle[triangle.size() - 1]);
        for(int i = triangle.size() - 2; i >= 0; --i)
        {
            const vector<int>& level = triangle[i];
            for(int j = 0; j < level.size(); ++j)
                levelSums[j] = level[j] + min(levelSums[j], levelSums[j + 1]);
        }
        
        return levelSums[0];
    }
};
