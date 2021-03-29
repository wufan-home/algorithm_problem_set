/*
    Given a data stream input of non-negative integers a1, a2, ..., an, ..., summarize the numbers seen 
    so far as a list of disjoint intervals.

    For example, suppose the integers from the data stream are 1, 3, 7, 2, 6, ..., then the summary will be:

    [1, 1]
    [1, 1], [3, 3]
    [1, 1], [3, 3], [7, 7]
    [1, 3], [7, 7]
    [1, 3], [6, 7]
    Follow up:
    What if there are lots of merges and the number of disjoint intervals are small compared to the data stream's size?
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
class SummaryRanges {
public:
    /** Initialize your data structure here. */
    SummaryRanges() {}
    
    void addNum(int val) {
        Interval insert = Interval(val, val);
        
        for(int i = 0; i < mIntervals.size(); ++i)
        {
            if(val < mIntervals[i].start - 1)
            {
                if(i == 0 || val > mIntervals[i - 1].end + 1)
                    mIntervals.insert(mIntervals.begin() + i, insert);
                else
                    mIntervals[i - 1].end = max(mIntervals[i - 1].end, val);
                    
                break;
            }
            else if(val == mIntervals[i].start - 1)
            {
                mIntervals[i].start = min(mIntervals[i].start, val);
                if(i > 0 && mIntervals[i].start == mIntervals[i - 1].end + 1)
                {
                    mIntervals[i].start = mIntervals[i - 1].start;
                    mIntervals.erase(mIntervals.begin() + i - 1);
                }
                
                break;
            }
        }
        
        if(mIntervals.empty() || val >= mIntervals.back().end + 1)
        {
            if(!mIntervals.empty() && val == mIntervals.back().end + 1)
                mIntervals.back().end = max(mIntervals.back().end, val);
            else
                mIntervals.push_back(insert);
        }
    }
    
    vector<Interval> getIntervals() {
        return mIntervals;
    }
    
private:
    vector<Interval> mIntervals;
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges obj = new SummaryRanges();
 * obj.addNum(val);
 * vector<Interval> param_2 = obj.getIntervals();
 */
