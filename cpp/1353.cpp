/*
    Given an array of events where events[i] = [startDayi, endDayi]. Every event i starts at startDayi and ends at endDayi.

    You can attend an event i at any day d where startTimei <= d <= endTimei. Notice that you can only attend one event at any time d.

    Return the maximum number of events you can attend.



    Example 1:

    Input: events = [[1,2],[2,3],[3,4]]
    Output: 3
    Explanation: You can attend all the three events.
    One way to attend them all is as shown.
    Attend the first event on day 1.
    Attend the second event on day 2.
    Attend the third event on day 3.

    Example 2:

    Input: events= [[1,2],[2,3],[3,4],[1,2]]
    Output: 4

    Example 3:

    Input: events = [[1,4],[4,4],[2,2],[3,4],[1,1]]
    Output: 4

    Example 4:

    Input: events = [[1,100000]]
    Output: 1

    Example 5:

    Input: events = [[1,1],[1,2],[1,3],[1,4],[1,5],[1,6],[1,7]]
    Output: 7



    Constraints:

        1 <= events.length <= 10^5
        events[i].length == 2
        1 <= startDayi <= endDayi <= 10^5
*/

class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        int size = events.size();
        
        sort(events.begin(), events.end());
        
        int res = 0;
        priority_queue<int, vector<int>, greater<int>> pq;
        for (int i = 0, cur = 1; cur <= 100000; ++cur) {
            if (i < size) {
                // Push the end dates of all events that have overlaps.
                int localLastDate = events[i][1];
                for (; i < size && cur >= events[i][0] && events[i][0] <= localLastDate; ++i) {
                    pq.push(events[i][1]);
                    localLastDate = max(localLastDate, events[i][1]);
                }
            }
            
            if (!pq.empty()) {
                if (cur <= pq.top()) {
                    ++res;
                }
                for (pq.pop(); !pq.empty() && pq.top() <= cur; pq.pop()) {}
            }
        }
        
        return res;
    }
};

/*
    This solution is from the link: https://leetcode.com/problems/maximum-number-of-events-that-can-be-attended/discuss/510263/JavaC%2B%2BPython-Priority-Queue
*/

class Solution {
public:
    int maxEvents(vector<vector<int>>& A) {
        priority_queue <int, vector<int>, greater<int>> pq;
        sort(A.begin(), A.end());
        int i = 0, res = 0, n = A.size();
        for (int d = 1; d <= 100000; ++d) {
            while (pq.size() && pq.top() < d)
                pq.pop();
            while (i < n && A[i][0] == d)
                pq.push(A[i++][1]);
            if (pq.size()) {
                pq.pop();
                ++res;
            }
        }
        return res;
    }
};

