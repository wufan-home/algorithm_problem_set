#include <iostream>
#include <vector>
#include <climits>

using namespace std;

class NumMatrix {
public:
	NumMatrix(const vector<vector<int> > &matrix)
	{
		m_empty = (matrix.empty() || matrix[0].empty());
		if(!m_empty)
		{
			int row = matrix.size();
			int col = matrix[0].size();
			m_sums.resize(row);
			for(int i = 0; i < row; ++i)
			{
				m_sums[i].resize(col);
				for(int j = 0; j < col; ++j)
				{
					m_sums[i][j] = matrix[i][j] + 
						(i ? m_sums[i - 1][j] : 0) +
						(j ? m_sums[i][j - 1] : 0) -
						(i && j ? m_sums[i - 1][j - 1] : 0);
				}
			}
		}
	}
	
	int sumRegion(int row1, int col1, int row2, int col2) {
		return m_empty ?
			INT_MIN : m_sums[row2][col2] - (row1 ? m_sums[row1 - 1][col2] : 0)
			- (col1 ? m_sums[row2][col1 - 1] : 0)
			+ (row1 && col1 ? m_sums[row1 - 1][col1 - 1] : 0);
	}
private:
	bool m_empty;
	vector<vector<int> > m_sums;
};

int main()
{
	vector<vector<int> > m;
	m.push_back(vector<int>({3,0,1,4,2}));
	m.push_back(vector<int>({5,6,3,2,1}));
	m.push_back(vector<int>({1,2,0,1,5}));
	m.push_back(vector<int>({4,1,0,1,7}));
	m.push_back(vector<int>({1,0,3,0,5}));
	NumMatrix a(m);
	cout << a.sumRegion(2, 1, 4, 3) << endl;
	return 1;
}
