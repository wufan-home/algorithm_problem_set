/*
    Given a string s and a list of strings dict, you need to add a closed pair of bold tag <b> and </b> to wrap the substrings in s that exist in dict. If two such substrings overlap, you need to wrap them together by only one pair of closed bold tag. Also, if two substrings wrapped by bold tags are consecutive, you need to combine them.

    Example 1:
    Input: 
    s = "abcxyz123"
    dict = ["abc","123"]
    Output:
    "<b>abc</b>xyz<b>123</b>"
    Example 2:
    Input: 
    s = "aaabbcc"
    dict = ["aaa","aab","bc"]
    Output:
    "<b>aaabbc</b>c"
    Note:
    The given dict won't contain duplicates, and its length won't exceed 100.
    All the strings in input have length in range [1, 1000].
*/

class Solution {
public:
    string addBoldTag(string s, vector<string>& dict) {
        if(dict.empty())
            return s;

        vector<int> candidateLengths;
        unordered_map<int, unordered_set<string>> lengthToWordList;
        for(int i = 0; i < dict.size(); ++i)
        {
            int len = dict[i].size();
            if(lengthToWordList.find(len) == lengthToWordList.end())
            {
               lengthToWordList[len] = unordered_set<string>();
                candidateLengths.push_back(len);
            }
            
            lengthToWordList[len].insert(dict[i]);
        }
        
        sort(candidateLengths.begin(), candidateLengths.end())
        
        vector<pair<int, int>> boldStrings;
        int boldStringNumber = 0;
        for(int i = 0; i < s.size();++i)
        {
            for(int j = candidateLengths.size() - 1; j >= 0; --j)
            {
                int len = candidateLengths[j];
                if(i + len > s.size())
                    continue;
                    
                if(boldStringNumber > 0 && i + len - 1 <= boldStrings[boldStringNumber - 1].second)
                    break;
                    
                if(lengthToWordList[len].find(s.substr(i, len)) != lengthToWordList[len].end())
                {
                    if(boldStringNumber == 0 || i > boldStrings[boldStringNumber - 1].second + 1)
                        boldStrings.push_back(make_pair(i, i + len - 1));
                    else
                        boldStrings[boldStringNumber - 1].second = i + len - 1;
                        
                    boldStringNumber = boldStrings.size();

                    break;
                }
            }
        }
        
        if(boldStringNumber == 0)
            return s;
        
        string stringWithBold;
        for(int i = 0, index = 0; i < s.size(); ++i)
        {
            if(i == boldStrings[index].first)
                stringWithBold.append("<b>");
            
            stringWithBold.push_back(s[i]);
            
            if(i == boldStrings[index].second)
            {
                stringWithBold.append("</b>");
                ++index;
            }
        }
        
        return stringWithBold;
    }
};
