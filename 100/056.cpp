// 56.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
#include <map>
#include <iostream>
#include <algorithm>
using namespace std;

struct Interval {
	int start;
	int end;
	Interval() : start(0), end(0) {}
	Interval(int s, int e) : start(s), end(e) {}
};

vector<Interval> merge(vector<Interval>& intervals) {
	vector<Interval> results;
	if (intervals.empty())
		return results;

	int size = intervals.size();
	map<int, int> valid_ints;
	for (int i = 0; i < size; ++i)
	{
		map<int, int>::iterator it = valid_ints.find(intervals[i].start);
		if (it != valid_ints.end())
		{
			if (intervals[i].end > it->second)
				it->second = intervals[i].end;
		}
		else
			valid_ints[intervals[i].start] = intervals[i].end;
	}

	vector<int> starts;
	for (map<int, int>::iterator it = valid_ints.begin();
		it != valid_ints.end(); ++it)
		starts.push_back(it->first);
	sort(starts.begin(), starts.end());

	int s = INT_MIN;
	int e = INT_MIN;
	for (int i = 0; i < starts.size(); ++i)
	{
		if (s == INT_MIN)
		{
			s = starts[i];
			e = valid_ints[starts[i]];
			continue;
		}

		if (starts[i] > e)
		{
			results.push_back(Interval(s, e));
			s = starts[i];
			e = valid_ints[starts[i]];
		}
		else
			e = (e < valid_ints[starts[i]] ? valid_ints[starts[i]] : e);
	}

	if (results.empty() || (results.end() - 1)->start != s)
		results.push_back(Interval(s, e));

	return results;
}

int main()
{
	//[[2,3],[5,5],[2,2],[3,4],[3,4]]
	vector<Interval> ints;
	ints.push_back(Interval(2, 3));
	ints.push_back(Interval(5, 5));
	ints.push_back(Interval(2, 2));
	ints.push_back(Interval(3, 4));
	ints.push_back(Interval(3, 4));
	vector<Interval> r = merge(ints);
	for (int i = 0; i < r.size(); ++i)
	{
		cout << r[i].start << ", " << r[i].end << endl;
	}
    return 0;
}

