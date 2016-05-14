/*
  Median is the middle value in an ordered integer list. 
  If the size of the list is even, 
  there is no middle value. So the median is the mean of the two middle value.
  Examples:

  [2,3,4] , the median is 3

  [2,3], the median is (2 + 3) / 2 = 2.5

  Design a data structure that supports the following two operations:

  void addNum(int num) - Add a integer number from the data stream to the data structure.
  double findMedian() - Return the median of all elements so far.

  For example:

  add(1)
  add(2)
  findMedian() -> 1.5
  add(3) 
  findMedian() -> 2

*/

#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class MedianFinder {
public:
	void Heapfy(vector<int>& nums, bool bMax)
	{
		int size = nums.size();
		for(int i = 0; i < size;)
		{
			int l = (i + 1) * 2 - 1;
			int r = (i + 1) * 2;
			int ni = i;
			if(l < size && ((bMax && nums[ni] < nums[l]) || (!bMax && nums[ni] > nums[l])))
				ni = l;
			if(r < size && ((bMax && nums[ni] < nums[r]) || (!bMax && nums[ni] > nums[r])))
				ni = r;
			if(ni == i)
				break;
			else
			{
				swap(nums[i], nums[ni]);
				i = ni;
			}
		}
	}

	void AddToHeap(vector<int>& nums, int val, bool bMax)
	{
		nums.push_back(val);
		for(int index = nums.size() - 1,
			    parent = (index + 1) / 2 - 1; parent >= 0; index = parent, parent = (index + 1) / 2 - 1)
		{
			cout << bMax << ": " << index << " " << parent << " "<< (nums[parent] < nums[index]) << endl;
			if(!bMax)
			{
				for(int i = 0; i < right.size(); ++i)
					cout << right[i] << ", ";
				cout << endl;
			}
			if((bMax && nums[parent] < nums[index]) || (!bMax && nums[parent] > nums[index]))
				swap(nums[parent], nums[index]);
			else
				break;
		}
	}

	// Adds a number into the data structure.
	void addNum(int num) {
		cout << endl;
		cout << "input is " << num << endl;
		if(right.empty() || num < right[0])
			AddToHeap(left, num, true);
		else
			AddToHeap(right, num, false);

		if(left.size() > right.size() + 1)
		{
			AddToHeap(right, left[0], false);
			swap(left[0], left[left.size() - 1]);
			left.pop_back();
			Heapfy(left, true);
		}
		else if(right.size() > left.size())
		{
			AddToHeap(left, right[0], true);
			swap(right[0], right[right.size() - 1]);
			right.pop_back();
			Heapfy(right, false);
		}
		cout << left.size() << ": ";
		for(int i = left.size() - 1; i >= 0; --i)
			cout << left[i] << ", ";
		cout << " | ";
		for(int i = 0; i < right.size(); ++i)
			cout << right[i] << ", ";
		cout << " :" << right.size();
		cout << endl;
	}

	// Returns the median of current data stream
	double findMedian()
	{
		if(left.size() > right.size())
			return double(left[0]);
		else if(left.size() < right.size())
			return double(right[0]);
		else
			return (double(left[0]) + double(right[0])) / 2.0;
	}					
private:
	vector<int> left;
	vector<int> right;
};

int main()
{
	MedianFinder con;
	con.addNum(78);cout << "med = " << con.findMedian() << endl;con.addNum(14);cout << "med = " << con.findMedian() << endl;con.addNum(50);cout << "med = " << con.findMedian() << endl;con.addNum(20);cout << "med = " << con.findMedian() << endl;con.addNum(13);cout << "med = " << con.findMedian() << endl;con.addNum(9);cout << "med = " << con.findMedian() << endl;con.addNum(25);cout << "med = " << con.findMedian() << endl;con.addNum(8);cout << "med = " << con.findMedian() << endl;con.addNum(13);cout << "med = " << con.findMedian() << endl;con.addNum(37);cout << "med = " << con.findMedian() << endl;con.addNum(29);cout << "med = " << con.findMedian() << endl;con.addNum(33);cout << "med = " << con.findMedian() << endl;con.addNum(55);cout << "med = " << con.findMedian() << endl;con.addNum(52);cout << "med = " << con.findMedian() << endl;con.addNum(6);cout << "med = " << con.findMedian() << endl;con.addNum(17);cout << "med = " << con.findMedian() << endl;con.addNum(65);cout << "med = " << con.findMedian() << endl;con.addNum(23);cout << "med = " << con.findMedian() << endl;con.addNum(74);cout << "med = " << con.findMedian() << endl;con.addNum(43);cout << "med = " << con.findMedian() << endl;con.addNum(5);cout << "med = " << con.findMedian() << endl;con.addNum(29);cout << "med = " << con.findMedian() << endl;con.addNum(29);cout << "med = " << con.findMedian() << endl;con.addNum(72);cout << "med = " << con.findMedian() << endl;con.addNum(7);cout << "med = " << con.findMedian() << endl;con.addNum(13);cout << "med = " << con.findMedian() << endl;con.addNum(56);cout << "med = " << con.findMedian() << endl;con.addNum(21);cout << "med = " << con.findMedian() << endl;con.addNum(31);cout << "med = " << con.findMedian() << endl;con.addNum(66);cout << "med = " << con.findMedian() << endl;con.addNum(69);cout << "med = " << con.findMedian() << endl;con.addNum(69);cout << "med = " << con.findMedian() << endl;con.addNum(74);cout << "med = " << con.findMedian() << endl;con.addNum(12);cout << "med = " << con.findMedian() << endl;con.addNum(77);cout << "med = " << con.findMedian() << endl;con.addNum(23);cout << "med = " << con.findMedian() << endl;con.addNum(10);cout << "med = " << con.findMedian() << endl;con.addNum(6);cout << "med = " << con.findMedian() << endl;con.addNum(27);cout << "med = " << con.findMedian() << endl;con.addNum(63);cout << "med = " << con.findMedian() << endl;con.addNum(77);cout << "med = " << con.findMedian() << endl;con.addNum(21);cout << "med = " << con.findMedian() << endl;con.addNum(40);cout << "med = " << con.findMedian() << endl;con.addNum(10);cout << "med = " << con.findMedian() << endl;con.addNum(19);cout << "med = " << con.findMedian() << endl;con.addNum(59);cout << "med = " << con.findMedian() << endl;con.addNum(35);cout << "med = " << con.findMedian() << endl;con.addNum(40);cout << "med = " << con.findMedian() << endl;con.addNum(44);cout << "med = " << con.findMedian() << endl;con.addNum(4);cout << "med = " << con.findMedian() << endl;con.addNum(15);cout << "med = " << con.findMedian() << endl;con.addNum(29);cout << "med = " << con.findMedian() << endl;con.addNum(63);cout << "med = " << con.findMedian() << endl;con.addNum(27);cout << "med = " << con.findMedian() << endl;con.addNum(46);cout << "med = " << con.findMedian() << endl;con.addNum(56);cout << "med = " << con.findMedian() << endl;con.addNum(0);cout << "med = " << con.findMedian() << endl;con.addNum(60);cout << "med = " << con.findMedian() << endl;con.addNum(72);cout << "med = " << con.findMedian() << endl;con.addNum(35);cout << "med = " << con.findMedian() << endl;con.addNum(54);cout << "med = " << con.findMedian() << endl;con.addNum(50);cout << "med = " << con.findMedian() << endl;con.addNum(14);cout << "med = " << con.findMedian() << endl;con.addNum(29);cout << "med = " << con.findMedian() << endl;con.addNum(62);cout << "med = " << con.findMedian() << endl;con.addNum(24);cout << "med = " << con.findMedian() << endl;con.addNum(18);cout << "med = " << con.findMedian() << endl;con.addNum(79);cout << "med = " << con.findMedian() << endl;con.addNum(16);cout << "med = " << con.findMedian() << endl;con.addNum(19);cout << "med = " << con.findMedian() << endl;con.addNum(8);cout << "med = " << con.findMedian() << endl;con.addNum(77);cout << "med = " << con.findMedian() << endl;con.addNum(10);cout << "med = " << con.findMedian() << endl;con.addNum(21);cout << "med = " << con.findMedian() << endl;con.addNum(66);cout << "med = " << con.findMedian() << endl;con.addNum(42);cout << "med = " << con.findMedian() << endl;con.addNum(76);cout << "med = " << con.findMedian() << endl;con.addNum(14);cout << "med = " << con.findMedian() << endl;con.addNum(58);cout << "med = " << con.findMedian() << endl;con.addNum(20);cout << "med = " << con.findMedian() << endl;con.addNum(0);cout << "med = " << con.findMedian() << endl;
	return 1;
}
