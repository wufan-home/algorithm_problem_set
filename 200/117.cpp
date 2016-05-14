#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int minimumTotal(vector<vector<int> >& triangle)
{
        if(triangle.empty())
		return INT_MIN;

	if(triangle.size() == 1)
		return triangle[0][0];

	int row = triangle.size();
	int max_sum = INT_MAX;
	int sum = 0;
	stack<int> index_stack;
	int cur = 0;
	while(cur >= 0 || !index_stack.empty())
	{
		if(cur < row)
		{
			int next = (cur == 0 ? 0 : index_stack.top());
			sum += triangle[cur++][next];
			index_stack.push(next);
		}
		else
		{
			if(sum < max_sum)
				max_sum = sum;

			int next = -1;
			for(--cur; ; --cur)
			{
				int temp = index_stack.top();
				sum -= triangle[cur][temp];
				index_stack.pop();
				//cout << "sum = " << sum << ". Pop: " << cur << ", " << temp << ", " << triangle[cur][temp] << endl;
				//cout << index_stack.size() << ", " << index_stack.top() << endl;
				if(index_stack.empty())
				{
					--cur;
					break;
				}
				else if(temp == index_stack.top())
				{
					next = temp + 1;
					break;
				}
			}
			
			
			if(next > 0)
			{			
				sum += triangle[cur++][next];
				index_stack.push(next);
			}
		}
	}

	return max_sum;
}

int main()
{
	vector<vector<int> > m(1, vector<int>(1, 2));
	
	vector<int> r(1, 3);
	r.push_back(4);
	m.push_back(r);
	r.clear();

	/*r.push_back(6);
	r.push_back(5);
	r.push_back(7);
	m.push_back(r);
	r.clear();

	r.push_back(4);
	r.push_back(1);
	r.push_back(8);
	r.push_back(3);
	m.push_back(r);
	r.clear();*/

	cout << minimumTotal(m) << endl;
	
	return 1;
}
