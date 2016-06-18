/*
  Given two strings s and t, determine if they are isomorphic.
  Two strings are isomorphic if the characters in s can be replaced to get t.
  All occurrences of a character must be replaced with another character 
  while preserving the order of characters. No two characters may map to the same character but a character may map to itself.
  For example,
  Given "egg", "add", return true.
  Given "foo", "bar", return false.
  Given "paper", "title", return true.
  Note:
  You may assume both s and t have the same length.
*/


bool isIsomorphic(string s, string t) {            
        unordered_map<char, char> maps;
        vector<bool> used(256, false);
        for(int i = 0; i < s.size(); ++i)
        {
            if(maps.find(s[i]) == maps.end())
            {
                if(used[t[i]])
                    return false;

                maps[s[i]] = t[i];
                used[t[i]] = true;
            }
            else if(maps[s[i]] != t[i])
                return false;
        }
        return true;
}
