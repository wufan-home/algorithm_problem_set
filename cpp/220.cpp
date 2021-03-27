/*
    Given an array of integers, find out whether there are two distinct indices i and j in the array 
    such that the absolute difference between nums[i] and nums[j] 
    is at most t and the absolute difference between i and j is at most k.
*/

class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        multimap<long long, int> m;
        int l = 0;
        for(int r = 0; r < nums.size(); ++r)
        {
            if(r - l > k)
                m.erase((long long) nums[l++]);
            
            auto lb = m.lower_bound((long long)nums[r] - t);
            if(lb != m.end() && abs(lb->first - nums[r]) <= t)
                return true;
            
            m.insert(make_pair((long long)nums[r], r));
        }
        
        return false;
    }
};
