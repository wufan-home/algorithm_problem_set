/*

*/

class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        vector<pair<int, int>> valueWithRow;
        for(int i = 0; i < nums.size(); ++i)
        {
            for(int j = 0; j < nums[i].size(); ++j)
                valueWithRow.push_back(make_pair(nums[i][j], i));
        }
        
        sort(valueWithRow.begin(), valueWithRow.end(), compare);
        int size = valueWithRow.size();
        vector<int> selected(nums.size(), 0);
        int start = INT_MIN;
        int end = INT_MIN;
        for(int l = 0, r = 0; r < size; ++r)
        {
            ++selected[valueWithRow[r].second];
            for(; l <= r && allRowContained(selected); ++l)
            {
                if(start == INT_MIN || valueWithRow[r].first - valueWithRow[l].first < end - start)
                {
                    start = valueWithRow[l].first;
                    end = valueWithRow[r].first;
                }
                --selected[valueWithRow[l].second];
            }
        }
        
        return vector<int>({start, end});
    }

private:
    bool allRowContained(const vector<int> &selected)
    {
        bool all = true;
        int size = selected.size();
        for(int i = 0; i < size; ++i)
        {
            if(selected[i] == 0)
            {
                all = false;
                break;
            }
        }
        
        return all;
    }
    
    static bool compare(const pair<int, int> &l, const pair<int, int> &r)
    {
        return l.first < r.first || (l.first == r.first && l.second < r.second);
    }
};
