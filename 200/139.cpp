/*
  Given a string s and a dictionary of words dict, determine if s can be segmented into a space-separated sequence of one or more dictionary words.
  For example, given
  s = "leetcode",
  dict = ["leet", "code"].
  Return true because "leetcode" can be segmented as "leet code".
*/

bool wordBreak(string s, unordered_set<string>& wordDict)
{
        int entry_len = INT_MIN;
        for(unordered_set<string>::iterator it = wordDict.begin(); it != wordDict.end(); ++it)
            entry_len = max(entry_len, (int)it->size());

        int size = s.size();
        vector<bool> aux(size + 1, false);
        aux[0] = true;
        for(int i = 1; i <= size; ++i)
        {
            for(int j = i; j >= 1 && i - j + 1 <= entry_len; --j)
            {
                if(aux[j - 1] && wordDict.find(s.substr(j - 1, i - j + 1)) != wordDict.end())
                {
                    aux[i] = true;
                    break;
                }
            }
        }
        
        return aux[size];
}
