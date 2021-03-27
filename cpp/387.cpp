/*
    Given a string, find the first non-repeating character in it and return it's index. If it doesn't exist, return -1.

    Examples:

    s = "leetcode"
    return 0.

    s = "loveleetcode",
    return 2.
    Note: You may assume the string contain only lowercase letters.
*/

class Solution {
public:
    Solution() : testCharacterRepeated(vector<int>(256, -1)) {}
    
    int firstUniqChar(string s) {
        for(int i = 0; i < s.size(); ++i)
        {
            if(testCharacterRepeated[s[i]] == -1)
            {
                testCharacterRepeated[s[i]] = i;
                uniqueCharacterSet.insert(i);
                minimalIndexQueue.push(i);
            }
            else if(testCharacterRepeated[s[i]] > -1 && 
                    uniqueCharacterSet.find(testCharacterRepeated[s[i]]) != uniqueCharacterSet.end())
            {
                uniqueCharacterSet.erase(testCharacterRepeated[s[i]]);
                if(!minimalIndexQueue.empty() && minimalIndexQueue.top() == testCharacterRepeated[s[i]])
                {
                    while(!minimalIndexQueue.empty() && uniqueCharacterSet.find(minimalIndexQueue.top()) == uniqueCharacterSet.end())
                        minimalIndexQueue.pop();
                }
            }
        }
        
        return minimalIndexQueue.empty() ? -1 : minimalIndexQueue.top();
    }
    
private:
    class Compare
    {
    public:
        bool operator() (const int& l, const int& r)
        {
            return l > r;
        }
    };

    priority_queue<int, vector<int>, Compare> minimalIndexQueue;
    unordered_set<int> uniqueCharacterSet;
    vector<int> testCharacterRepeated;
};
