/*
	Given an unsorted array of integers, find the length of the longest consecutive elements sequence.

	For example,
	Given [100, 4, 200, 1, 3, 2],
	The longest consecutive elements sequence is [1, 2, 3, 4]. Return its length: 4.

	Your algorithm should run in O(n) complexity.
*/

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.empty())
            return 0;
            
        unordered_set<int> numberSet;
        for(int i = 0; i < nums.size(); ++i)
            numberSet.insert(nums[i]);
            
        int maxLength = 1;
        for(unordered_set<int>::iterator it = numberSet.begin(); it != numberSet.end(); ++it)
        {
            int point = *it;
            if(startToEnd.find(point + 1) != startToEnd.end())
            {
                updateIntervalEndPoints(point + 1, startToEnd[point + 1], point, startToEnd[point + 1]);
                maxLength = max(maxLength, startToEnd[point] - point + 1);
                while(endToStart.find(point - 1) != endToStart.end())
                {
                    int oldStart = point;
                    int oldEnd = startToEnd[point];
                    int newStart = endToStart[point - 1];
                    maxLength = max(maxLength, oldEnd - newStart + 1);
                    updateIntervalEndPoints(oldStart, oldEnd, newStart, oldEnd);
                    point = newStart;
                }
            }
            else if(endToStart.find(point - 1) != endToStart.end())
            {
                updateIntervalEndPoints(endToStart[point - 1], point - 1, endToStart[point - 1], point);
                maxLength = max(maxLength, point - endToStart[point] + 1);
                while(startToEnd.find(point + 1) != startToEnd.end())
                {
                    int oldStart = endToStart[point];
                    int oldEnd = point;
                    int newEnd = startToEnd[point + 1];
                    maxLength = max(maxLength, newEnd - oldStart + 1);
                    updateIntervalEndPoints(oldStart, oldEnd, oldStart, newEnd);
                    point = newEnd;
                }
            }
            else
            {
                startToEnd[point] = point;
                endToStart[point] = point;
            }
        }
        
        return maxLength;
    }
    
private:
    void updateIntervalEndPoints(int start, int end, int newStart, int newEnd)
    {
        startToEnd.erase(start);
        endToStart.erase(end);
        startToEnd.erase(newStart);
        endToStart.erase(newEnd);
        startToEnd[newStart] = newEnd;
        endToStart[newEnd] = newStart;
    }
    
    unordered_map<int, int> startToEnd;
    unordered_map<int, int> endToStart;
};
