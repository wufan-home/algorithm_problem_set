/*
    Given a string, we can "shift" each of its letter to its successive letter, for example: "abc" -> "bcd". We can keep "shifting" which forms the sequence:

    "abc" -> "bcd" -> ... -> "xyz"
    Given a list of strings which contains only lowercase alphabets, group all strings that belong to the same shifting sequence.

    For example, given: ["abc", "bcd", "acef", "xyz", "az", "ba", "a", "z"], 
    A solution is:

    [
      ["abc","bcd","xyz"],
      ["az","ba"],
      ["acef"],
      ["a","z"]
    ]
*/

class Solution {
public:
    vector<vector<string>> groupStrings(vector<string>& strings) {
        for(int i = 0; i < strings.size(); ++i)
        {
            string key = getKey(strings[i]);
            if(groups.find(key) == groups.end())
                groups[key] = vector<string>();
            
            groups[key].push_back(strings[i]);
        }
        
        vector<vector<string>> result;
        for(unordered_map<string, vector<string>>::iterator it = groups.begin();
            it != groups.end(); ++it)
            result.push_back(it->second);
        
        return result;
    }
    
private:
    string getKey(const string input)
    {
        string key(input.size(), '\0');
        int difference = input[0] - 'a';
        for(int i = 0; i < input.size(); ++i)
        {
            key[i] = input[i] - difference;
            if(key[i] < 'a')
                key[i] += 26;
        }
        
        return key;
    }
    
    unordered_map<string, vector<string>> groups;
};
