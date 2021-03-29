/*
    Given a list of 24-hour clock time points in "Hour:Minutes" format, 
    find the minimum minutes difference between any two time points in the list.

    Example 1:
    Input: ["23:59","00:00"]
    Output: 1
    Note:
    The number of time points in the given list is at least 2 and won't exceed 20000.
    The input time is legal and ranges from 00:00 to 23:59.
*/

class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        sort(timePoints.begin(), timePoints.end());
        
        int minDiff = INT_MAX;
        int size = timePoints.size();
        for(int i = 0; i < size - 1; ++i)
        {
            int hour1 = atoi(timePoints[i].substr(0, 2).c_str());
            int hour2 = atoi(timePoints[i + 1].substr(0, 2).c_str());
            
            int min1 = atoi(timePoints[i].substr(3, 2).c_str());
            int min2 = atoi(timePoints[i + 1].substr(3, 2).c_str());
            
            minDiff = min(minDiff, (hour2 - hour1) * 60 + (min2 - min1));
        }
        
        int hour1 = atoi(timePoints[size - 1].substr(0, 2).c_str());
        int hour2 = atoi(timePoints[0].substr(0, 2).c_str());

        int min1 = atoi(timePoints[size - 1].substr(3, 2).c_str());
        int min2 = atoi(timePoints[0].substr(3, 2).c_str());

        int diff = (24 - hour1) * 60 + 0 - min1;
        diff += (hour2 - 0) * 60 + min2;
        
        return min(minDiff, diff);
    }
};
