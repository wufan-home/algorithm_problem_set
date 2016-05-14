/*
  Given numRows, generate the first numRows of Pascal's triangle.

  For example, given numRows = 5,
  Return

  [
     [1],
    [1,1],
   [1,2,1],
  [1,3,3,1],
 [1,4,6,4,1]
 ]

*/

#include <iostream>
#include <vector>

using namespace std;

vector<vector<int> > generate(int numRows) {
	vector<vector<int> > rv;
        if(numRows < 1)
		return rv;

	rv.push_back(vector<int>(1, 1));
	if(numRows > 1)
		rv.push_back(vector<int>(2, 1));

	for(int i = 2; i < numRows; ++i)
	{
		vector<int> new_row(i + 1, 1);
		for(int j = 1; j < i; ++j)
			new_row[j] = rv[i - 1][j - 1] + rv[i - 1][j];
		rv.push_back(new_row);
	}

	return rv;
}

int main()
{
	for(int i = 1; i <= 10; ++i)
	{
		vector<vector<int> > rv = generate(i);
		for(int j = 0; j < rv.size(); ++j)
		{
			for(int k = 0; k < rv[j].size(); ++k)
				cout << rv[j][k] << ", ";
			cout << endl;
		}
		cout << endl;
	}
	return 1;
}
