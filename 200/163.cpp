/*
    Given a sorted integer array where the range of elements are in the inclusive range [lower, upper], 
    return its missing ranges.
    For example, given [0, 1, 3, 50, 75], lower = 0 and upper = 99, return ["2", "4->49", "51->74", "76->99"].
*/

class Solution {
public:
    vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
        vector<string> missingRanges;
        
        if(nums.empty())
        {
            missingRanges.push_back(createMissingRange(lower, upper));
            return missingRanges;
        }
        
        int n = nums.size();
        if(lower < nums[0])
            missingRanges.push_back(createMissingRange(lower, nums[0] - 1));
        
        for(int i = 0; i < n - 1; ++i)
        {
            if(nums[i] == INT_MAX)
                continue;
        
            if(nums[i] + 1 < nums[i + 1])
                missingRanges.push_back(createMissingRange(nums[i] + 1, nums[i + 1] - 1));
        }
        
        if(nums[n - 1] < upper && nums[n - 1] < INT_MAX)
            missingRanges.push_back(createMissingRange(nums[n - 1] + 1, upper));
            
        return missingRanges;
    }
    
private:
    string createMissingRange(int start, int end)
    {
        string range(to_string(start));
        if(end > start)
        {
            range.append("->");
            range.append(to_string(end));
        }
        return range;
    }
};
