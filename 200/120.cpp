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

#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int minimumTotal(vector<vector<int> >& triangle) {
	if(triangle.size() < 1)
		return INT_MIN;
	else if(triangle.size() == 1)
		return triangle[0][0];
	else
	{
		int row = triangle.size() - 1;
		vector<int> psums(triangle[row]);
		for(--row; row >= 0; --row)
		{
			for(int i = 0; i < triangle[row].size(); ++i)
				psums[i] = triangle[row][i] + min(psums[i], psums[i + 1]);
		}
		return psums[0];
	}
}

int main()
{
	vector<vector<int> > ts(1, vector<int>({2}));
	ts.push_back(vector<int>({3, 4}));
	//ts.push_back(vector<int>({6, 5, 7}));
	//ts.push_back(vector<int>({4, 1, 8, 3}));
	cout << minimumTotal(ts) << endl;
	return 1;
}
