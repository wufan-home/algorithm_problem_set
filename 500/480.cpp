/*
    Median is the middle value in an ordered integer list. If the size of the list is even, there is no middle value. So the median is the mean of the two middle value.

    Examples: 
    [2,3,4] , the median is 3

    [2,3], the median is (2 + 3) / 2 = 2.5

    Given an array nums, there is a sliding window of size k which is moving from the very left of the array to the very right. You can only see the k numbers in the window. Each time the sliding window moves right by one position. Your job is to output the median array for each window in the original array.

    For example,
    Given nums = [1,3,-1,-3,5,3,6,7], and k = 3.

    Window position                Median
    ---------------               -----
    [1  3  -1] -3  5  3  6  7       1
     1 [3  -1  -3] 5  3  6  7       -1
     1  3 [-1  -3  5] 3  6  7       -1
     1  3  -1 [-3  5  3] 6  7       3
     1  3  -1  -3 [5  3  6] 7       5
     1  3  -1  -3  5 [3  6  7]      6
    Therefore, return the median sliding window as [1,-1,-1,3,5,6].

    Note: 
    You may assume k is always valid, ie: 1 ≤ k ≤ input array's size for non-empty array.
*/

class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        if(nums.empty() || k == 0)
            return vector<double>();
            
        for(int i = 0; i < k; ++i)
            window.push_back(make_pair(nums[i], i));
            
        sort(window.begin(), window.end(), compare);
        
        for(int i = 0; i < window.size(); ++i)
            indexToSortedIndex[window[i].second] = i;
            
        vector<double> medians(1, getMedian());
        for(int i = k; i < nums.size(); ++i)
        {
            UpdateWindow(nums[i], i);
            medians.push_back(getMedian());
        }
        
        return medians;
    }
private:
    double getMedian()
    {
        int size = window.size();
        if(size % 2 == 0)
            return ((double)window[(size - 1) / 2].first + (double)window[size / 2].first) / 2;

        return (double)window[size / 2].first;
    }

    void UpdateWindow(int value, int index)
    {
        int k = window.size();
        int replace = indexToSortedIndex[index - k];
        indexToSortedIndex[index] = replace;
        window[replace] = make_pair(value, index);
        
        if(replace < k - 1 && window[replace].first >= window[replace + 1].first)
        {
            for(; replace < k - 1 && window[replace].first > window[replace + 1].first; ++replace)
            {
                swap(indexToSortedIndex[window[replace].second], indexToSortedIndex[window[replace + 1].second]);
                swap(window[replace].first, window[replace + 1].first);
                swap(window[replace].second, window[replace + 1].second);
            }
        }
        else if(replace > 0 && window[replace].first < window[replace - 1].first)
        {
            for(; replace > 0 && window[replace].first < window[replace - 1].first; --replace)
            {
                swap(indexToSortedIndex[window[replace].second], indexToSortedIndex[window[replace - 1].second]);
                swap(window[replace].first, window[replace - 1].first);
                swap(window[replace].second, window[replace - 1].second);
            }
        }
    }

    static bool compare(const pair<int, int>& l, const pair<int, int>& r)
    {
        return l.first < r.first;
    }
    
    vector<pair<int, int> > window;
    unordered_map<int, int> indexToSortedIndex;
};
