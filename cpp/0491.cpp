/*
    Given an integer array, your task is to find all the different possible increasing subsequences of the given array, 
    and the length of an increasing subsequence should be at least 2 .

    Example:
    Input: [4, 6, 7, 7]
    Output: [[4, 6], [4, 7], [4, 6, 7], [4, 6, 7, 7], [6, 7], [6, 7, 7], [7,7], [4,7,7]]
    Note:
    The length of the given array will not exceed 15.
    The range of integer in the given array is [-100,100].
    The given array may contain duplicates, 
    and two equal integers should also be considered as a special case of increasing sequence.
*/

class Solution {
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        if(nums.empty())
            return vector<vector<int>>();
        
        set<vector<int>> res;
        doFinding(nums, 0, res);
        
        vector<vector<int>> r;
        for(auto a : res)
            r.push_back(a);
        
        return r;
    }
    
private:
    void doFinding(vector<int>& nums, int start, set<vector<int>>& res)
    {
        vector<vector<int>> result(1, vector<int>({nums[start]}));
        for(int i = start + 1; i < nums.size(); ++i)
        {
            if(cached_list.find(i) == cached_list.end())
                doFinding(nums, i, res);
            
            if(nums[i] < nums[start])
                continue;
            
            for(auto a : cached_list[i])
            {
                vector<int> cur = vector<int>(1, nums[start]);
                for(auto b : a)
                    cur.push_back(b);
                
                if(cur.size() > 1)
                    res.insert(cur);
                
                result.push_back(cur);
            }
        }
        
        cached_list[start] = result;
    }
    
    unordered_map<int, vector<vector<int>>> cached_list;
};
