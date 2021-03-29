/*
	Given an array of strings, group anagrams together.

	For example, given: ["eat", "tea", "tan", "ate", "nat", "bat"], 
	Return:

	[
	  ["ate", "eat","tea"],
	  ["nat","tan"],
	  ["bat"]
	]
*/

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mapAnagrams;
        
        for(int i = 0; i < strs.size(); ++i)
        {
            string word = strs[i];
            sort(word.begin(), word.end());
            
            if(mapAnagrams.find(word) == mapAnagrams.end())
                mapAnagrams[word] = vector<string>(1, strs[i]);
            else
                mapAnagrams[word].push_back(strs[i]); 
        }
        
        vector<vector<string>> anagrams;
        for(unordered_map<string, vector<string>>::iterator it = mapAnagrams.begin(); it != mapAnagrams.end(); ++it)
            anagrams.push_back(it->second);
        
        return anagrams;
    }
};
