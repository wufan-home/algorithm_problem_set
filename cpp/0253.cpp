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

// Use sort.
// Put all endpoints into one vector and use 1 and -1 to distinguish them as start/end time points.
// Use the time endpoints to sort all of them and put end timestamp before the next start timestamp.
// Accumulate 1 and -1 from the left to the right, and get the maximum value each round.
// This is the best code I did.
class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        int size = intervals.size();
        vector<pair<int, int>> timestamps(2 * size, {-1, -1});
        for (int i = 0; i < size; ++i) {
            timestamps[2 * i] = make_pair(intervals[i][0], 1);
            timestamps[2 * i + 1] = make_pair(intervals[i][1], -1);
        }
        
        auto compare = [](const pair<int, int>& l, const pair<int, int>& r) {
            return l.first < r.first || (l.first == r.first && l.second < r.second);
        };
        
        sort(timestamps.begin(), timestamps.end(), compare);
        
        int ans = 0;
        int local = 0;
        for (int i = 0; i < 2 * size; ++i) {
            local += timestamps[i].second;
            ans = max(ans, local);
        }
        
        return ans;
    }
};

// Use a priority queue.

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
