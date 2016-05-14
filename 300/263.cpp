#include <iostream>

#include <vector>

using namespace std;

void IncreaseKey(vector<int>&  heap_past_num, int head, int tail)
{
	
}

void MaintainPriority(vector<int>&  heap_past_num, int head, int tail)
{
	for(int parent = 1; head + 2 * parent - 1 <= tail; parent *= 2)
	{
		if(head + 2 * parent > tail)
		{
			if()
		}
	}
}

bool isUgly(int num)
{
        if(num <= 0)
		return false;

	if(num <= 6)
		return true;

	vector<bool> used_number(num, false);
	vector<int> heap_past_num(num, 0);
	heap_past_num.push_back(2);
	heap_past_num.push_back(3);
	heap_past_num.push_back(5);

	for(int head = 0, tail = 3; tail < heap_past_num.size(); ++current)
	{
		int new_adding_2 = heap_past_num[head] * 2;
		int new_adding_3 = heap_past_num[head] * 3;
		int new_adding_5 = heap_past_num[head] * 5;

		if(new_adding_2 == num || new_adding_3 == num || new_adding_5 == num)
			return true;
		else if(new_adding_2 > num || new_adding_3 > num || new_adding_5 > num)
			return false;

		if(!used[new_adding_2]) {
			heap_past_num[tail++] = new_adding_2;
			IncreaseKey(heap_past_num, head + 1, tail);
			used[new_adding_2] = true;
		}

		if(!used[new_adding_3]) {
			heap_past_num[tail++] = new_adding_3;
			IncreaseKey(heap_past_num, head + 1, tail);
			used[new_adding_3] = true;
		}

		if(!used[new_adding_5]) {
			heap_past_num[tail++] = new_adding_5;
			IncreaseKey(heap_past_num, head + 1, tail);
			used[new_adding_5] = true;
		}

		MaintainPriority(heap_past_num, head + 1, tail);
	}
}

int main()
{
	for(int i = 6; i < 10000; ++i)
		cout << "Number " << i << " is " << isUgly(i) << "." << endl;

	return 1;
}
