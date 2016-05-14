#include <iostream>
#include <vector>
#include <climits>

using namespace std;

class NumArray {
public:
	NumArray(const vector<int> &nums) {
		m_empty = nums.empty();

		if(!m_empty)
		{
			m_sums.resize(nums.size());
			m_sums[0] = nums[0];
			for(int i = 1; i < m_sums.size(); ++i)
				m_sums[i] = m_sums[i - 1] + nums[i];
			for(int i = 1; i < m_sums.size(); ++i)
				cout << m_sums[i] << ", ";
			cout << endl;
		}
	}

	int sumRange(int i, int j) {
		return m_empty ? INT_MIN : m_sums[j] - (i ? m_sums[i - 1] : 0);
	}
private:
	bool m_empty;
	vector<int> m_sums;
};

int main()
{
	NumArray a(vector<int>({-2,0,3,-5,2,-1}));
	cout << a.sumRange(0, 2) << endl;
	return 1;
}
