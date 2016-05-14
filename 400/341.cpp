#include <iostream>
#include <vector>
#include <stack>
#include <climits>

using namespace std;

class NestedInteger
{
public:
	NestedInteger() : m_i(INT_MIN) {}
	NestedInteger(int i) : m_i(i) {}

	~NestedInteger() {}

	bool isInteger() { return m_v.empty(); }

	int getInteger() { return m_i; }
	vector<NestedInteger> &getList() { return m_v; }

	void push_back(const NestedInteger& ni) { m_v.push_back(ni); }
	void push_back(const int i) { m_v.push_back(NestedInteger(i)); }
private:
	vector<NestedInteger> m_v;
	int m_i;
};

class NestedIterator {
public:
	NestedIterator(vector<NestedInteger> &nestedList) {
		mp_cur_node = &nestedList;
		mp_start = mp_cur_node;
		m_index = 0;
		m_w = 1;
		MoveToNextAvailable();
	}

	int next() {
		if(!hasNext())
			return INT_MIN;

		int rv = (*mp_cur_node)[m_index++].getInteger();
		MoveToNextAvailable();
		return rv;
	}

	bool hasNext()
	{
		return m_index < mp_cur_node->size();
	}

	int GetSumByWeight();
	{
		int sum = 0;
		while(hasNext())
		{
			sum += (*mp_cur_node)[m_index++].getInteger() * m_w;
			MoveToNextAvailable();
		}
		return sum;
	}
private:
	void MoveToNextAvailable()
	{
		while(hasNext() || !m_node_stack.empty())
		{
			if(hasNext())
			{
				if((*mp_cur_node)[m_index].isInteger())
					return;

				m_node_stack.push(make_pair(mp_cur_node, m_index));
				mp_cur_node = &(*mp_cur_node)[m_index].getList();
				m_index = 0;
				++m_w;
			}
			else
			{
				mp_cur_node = m_node_stack.top().first;
				m_index =  m_node_stack.top().second + 1;
				m_node_stack.pop();
				--m_w;
			}
		}
	}
	
	typedef vector<NestedInteger> node;
	stack<pair<node *, int> > m_node_stack;
	node *mp_cur_node;  // The entry.
	int m_index;  //The index of the current entry.

	node *mp_start;
	int m_w;
};

int main()
{
	/*
	  [[2,[3, [4, 4], 3], 2],1,[2,2]]
[1,[4,[6]]]
[]
[1]
[[], [], []]
[[], [3]]
*/
	return 1;
}
