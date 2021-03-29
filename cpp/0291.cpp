/*
    Given a pattern and a string str, find if str follows the same pattern.

    Here follow means a full match, such that there is a bijection between a letter in pattern 
    and a non-empty substring in str.

    Examples:
    pattern = "abab", str = "redblueredblue" should return true.
    pattern = "aaaa", str = "asdasdasdasd" should return true.
    pattern = "aabb", str = "xyzabcxzyabc" should return false.
    Notes:
    You may assume both pattern and str contains only lowercase letters.
*/

class Solution {
public:
    bool wordPatternMatch(string pattern, string str) {
        unordered_map<char, string> dict;
        unordered_set<string> visited;
        return helper(str, 0, pattern, 0, dict, visited);
    }
    
private:
    bool helper(const string& str, int start, const string& pattern, int cur, unordered_map<char, string> &dict, unordered_set<string> &visited)
    {
        if(cur == pattern.size())
            return start == str.size();
            
        char key = pattern[cur];
        if(dict.find(key) == dict.end())
        {
            string s = "";
            for(int i = start; i < str.size(); ++i)
            {
                s.push_back(str[i]);
                if(visited.find(s) != visited.end())
                    continue;
                
                dict[key] = s;
                visited.insert(s);
                if(helper(str, i + 1, pattern, cur + 1, dict, visited))
                    return true;
                
                dict.erase(key);
                visited.erase(s);
            }
        }
        else
        {
            int len = dict[key].size();
            
            if(len > str.size() - start || str.substr(start, len) != dict[key])
                return false;
            
            if(helper(str, start + len, pattern, cur + 1, dict, visited))
                return true;
        }
        
        return false;
    }
};
