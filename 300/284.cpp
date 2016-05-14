#include <iostream>
#include <vector>
#include <climits>

using namespace std;

class Iterator {
    struct Data;
	Data* data;
public:
	Iterator(const vector<int>& nums);
	Iterator(const Iterator& iter);
	virtual ~Iterator();
	// Returns the next element in the iteration.
	int next();
	// Returns true if the iteration has more elements.
	bool hasNext() const;
};


class PeekingIterator : public Iterator {
public:
	PeekingIterator(const vector<int>& nums) : Iterator(nums), prev(INT_MIN) { }

	int peek() {
		if(prev == INT_MIN)
			prev = Iterator::hasNext() ?
				Iterator::next() : INT_MIN;

		return prev;
	}

	int next() {
		int rv = prev;
		prev = (Iterator::hasNext() ? Iterator::next() : INT_MIN);
		return rv;
	}

	bool hasNext() const
	{
		return (Iterator::hasNext() || prev != INT_MIN);
	}

private:
	int prev;
};

int main()
{
	vector<int> v({1, 2, 3, 4});
	PeekingIterator o(v);
	cout << o.hasNext() << endl;
	cout << o.peek() << endl;
	cout << o.peek() << endl;
}
