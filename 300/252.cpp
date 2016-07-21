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
