/*
  Given an index k, return the kth row of the Pascal's triangle.

  For example, given k = 3,
  Return [1,3,3,1].

  Note:
  Could you optimize your algorithm to use only O(k) extra space? 
*/

#include <iostream>
#include <vector>

using namespace std;

vector<int> getRow(int rowIndex) {
	vector<int> rv;
	if(rowIndex < 0)
		return rv;

	if(rowIndex >= 0)
		rv.push_back(1);

	if(rowIndex >= 1)
		rv.push_back(1);

	if(rowIndex >= 2)
	{
		for(int i = 2; i <= rowIndex; ++ i)
		{
			vector<int> new_row(i + 1, 1);
			for(int j = 1; j < i; ++j)
				new_row[j] = rv[j - 1] + rv[j];
			rv = new_row;
		}
	}

	return rv;
}

vector<int> getRow1(int rowIndex) {
	vector<int> rv;
    	if(rowIndex < 0)
    		return rv;
    
    	if(rowIndex >= 0)
    		rv.push_back(1);
    
    	if(rowIndex >= 1)
    		rv.push_back(1);
    
    	if(rowIndex >= 2)
    	{
		rv.resize(rowIndex + 1, 1);
    		int size = rv.size();
    		for(int i = 1; i < size - 1; ++i)
    		{
    			long long temp = static_cast<long long>(rv[i - 1])
				* static_cast<long long>(size - i);
    			temp /= i;
    			rv[i] = temp;
    		}
    	}
    	
    	return rv;
}

int main()
{
	for(int i = 30; i < 31; ++i)
	{
		vector<int> rv = getRow1(i);
		for(int j = 0; j < rv.size(); ++j)
			cout << rv[j] << ", ";
		cout << endl;
	}
}
