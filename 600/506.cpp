/*
    Given scores of N athletes, find their relative ranks and the people with the top three highest scores, 
    who will be awarded medals: "Gold Medal", "Silver Medal" and "Bronze Medal".
    Example 1:
    Input: [5, 4, 3, 2, 1]
    Output: ["Gold Medal", "Silver Medal", "Bronze Medal", "4", "5"]
    Explanation: The first three athletes got the top three highest scores, so they got "Gold Medal", "Silver Medal" and "Bronze Medal". 
    For the left two athletes, you just need to output their relative ranks according to their scores.
    Note:
    N is a positive integer and won't exceed 10,000.
    All the scores of athletes are guaranteed to be unique.
*/

class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& nums) {
        vector<string> rankByElements;
        
        for(int i = 0; i < nums.size(); ++i)
        {
            if(mDistinctElements.find(nums[i]) == mDistinctElements.end())
            {
                mDistinctElements.insert(nums[i]);
                ranks.push(nums[i]);
            }
        }
            
        getElementToRank();
        
        for(int i = 0; i < nums.size(); ++i)
            rankByElements.push_back(mElementToRank[nums[i]]);
        
        return rankByElements;
    }
    
private:
    unordered_set<int> mDistinctElements;
    priority_queue<int> ranks;
    unordered_map<int, string> mElementToRank;
    
    void getElementToRank()
    {
        while(!ranks.empty())
        {
            switch(mElementToRank.size())
            {
                case 0:
                    mElementToRank[ranks.top()] = "Gold Medal";
                    break;
                case 1:
                    mElementToRank[ranks.top()] = "Silver Medal";
                    break;
                case 2:
                    mElementToRank[ranks.top()] = "Bronze Medal";
                    break;
                default:
                    mElementToRank[ranks.top()] = to_string(mElementToRank.size() + 1);
            }
            
            ranks.pop();
        }
    }
};
