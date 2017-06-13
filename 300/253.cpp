/*
    Given an array of meeting time intervals consisting of start and end times [[s1,e1],[s2,e2],...] (si < ei), 
    find the minimum number of conference rooms required.

    For example,
    Given [[0, 30],[5, 10],[15, 20]],
    return 2.
*/

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
    int minMeetingRooms(vector<Interval>& intervals) {
        if(intervals.empty())
            return 0;

        vector<stack<Interval>> meetingRooms;
        sort(intervals.begin(), intervals.end(), compare);
        meetingRooms.push_back(stack<Interval>());
        meetingRooms[0].push(intervals[0]);
        for(int i = 1; i < intervals.size(); ++i)
        {
            bool available = false;
            for(int j = 0; j < meetingRooms.size(); ++j)
            {
                available = (intervals[i].start >= meetingRooms[j].top().end);
                if(available)
                {
                    meetingRooms[j].push(intervals[i]);
                    break;
                }
            }
            
            if(!available)
            {
                meetingRooms.push_back(stack<Interval>());
                meetingRooms[meetingRooms.size() - 1].push(intervals[i]);
            }
        }
        
        return meetingRooms.size();
    }
    
private:
    static bool compare(const Interval &l, const Interval &r)
    {
        return l.start < r.start || (l.start == r.start && l.end <= r.end);
    }
};
