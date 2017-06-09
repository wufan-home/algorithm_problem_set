/*
  Given an array of meeting time intervals consisting of start and end times [[s1,e1],[s2,e2],...] (si < ei), 
  determine if a person could attend all meetings.
  For example,
  Given [[0, 30],[5, 10],[15, 20]],
  return false.
*/

static bool Compare(const Interval& l, const Interval& r)
{
	return l.start < r.start || (l.start == r.start && l.end <= r.end);
}

bool canAttendMeetings(vector<Interval>& intervals) 
{
	sort(intervals.begin(), intervals.end(), Compare);
	for(int i = 0; i < (int)intervals.size() - 1; ++i)
        {
		if(intervals[i].end > intervals[i + 1].start)
			return false;
        }
        
        return true;
}

// Using the quick sort.
/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    bool canAttendMeetings(vector<Interval>& intervals) {
        if(intervals.size() <= 1)
            return true;
            
        return sortedIntervalsWithCheckingIntersection(intervals, 0, intervals.size() - 1);
    }
    
private:
    bool sortedIntervalsWithCheckingIntersection(vector<Interval>& intervals, int start, int end)
    {
        if(start >= end)
            return true;

        int write = start - 1;
        for(int i = start; i < end; ++i)
        {
            if(checkTwoIntervalsIntersection(intervals[i], intervals[end]))
                return false;
                
            if(intervals[i].end <= intervals[end].start)
                swapIntervals(intervals[++write], intervals[i]);
        }
        swapIntervals(intervals[++write], intervals[end]);

        return sortedIntervalsWithCheckingIntersection(intervals, start, write - 1) && 
                sortedIntervalsWithCheckingIntersection(intervals, write + 1, end);
    }
    
    bool checkTwoIntervalsIntersection(const Interval &l, const Interval& r)
    {
        return (l.start == r.start && l.end == r.end) || 
               (l.start > r.start && l.start < r.end) || (l.end > r.start && l.end < r.end) || 
               (r.start > l.start && r.start < l.end) || (r.end > l.start && r.end < l.end);
    }
    
    void swapIntervals(Interval &l, Interval &r)
    {
        swap(l.start, r.start);
        swap(l.end, r.end);
    }
};
