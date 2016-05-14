/*
  Given a set of non-overlapping intervals, insert a new interval into the intervals (merge if necessary).

  You may assume that the intervals were initially sorted according to their start times.

  Example 1:
  Given intervals [1,3],[6,9], insert and merge [2,5] in as [1,5],[6,9].

  Example 2:
  Given [1,2],[3,5],[6,7],[8,10],[12,16], insert and merge [4,9] in as [1,2],[3,10],[12,16].

  This is because the new interval [4,9] overlaps with [3,5],[6,7],[8,10]. 
*/

struct Interval {
	int start;
	int end;
	Interval() : start(0), end(0) {}
	Interval(int s, int e) : start(s), end(e) {}
};

vector<Interval> insert(vector<Interval>& intervals,
			Interval newInterval)
{
	int size = intervals.size();
	int left = 0;
	for(; left < size; ++left)
	{
		if(intervals[left].start >= newInterval.start || intervals[left].end >= newInterval.start)
		{
			if(intervals[left].start > newInterval.end)
			{
				intervals.insert(intervals.begin() + (left ? left : 0), newInterval);
				return intervals;
			}
			else if(intervals[left].start == newInterval.end)
			{
				intervals[left].start = newInterval.start;
				return intervals;
			}
			newInterval.start = min(newInterval.start, intervals[left].start);
			break;
		}
	}

	int right = size - 1;
	for(; right >= 0; --right)
	{
		if(intervals[right].end <= newInterval.end || intervals[right].start <= newInterval.end)
		{
			newInterval.end = max(newInterval.end, intervals[right].end);
			break;
		}
	}

	vector<Interval> rv;
	for(int i = 0; i < left; ++i)
		rv.push_back(intervals[i]);
	rv.push_back(newInterval);
	for(int i = right + 1; i < size; ++i)
		rv.push_back(intervals[i]);
	
	return rv;
}

