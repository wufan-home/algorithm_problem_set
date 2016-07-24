/*
  You are given a string, s, and a list of words, words, 
  that are all of the same length. Find all starting indices of substring(s) in s 
  that is a concatenation of each word in words exactly once and without any intervening characters.
  For example, given:
  s: "barfoothefoobarman"
  words: ["foo", "bar"]
  You should return the indices: [0,9].
  (order does not matter).

  Solution: 
*/

vector<int> findSubstring(string s, vector<string>& words)
{
	vector<int> results;
	if(s.empty() || words.empty())
		return results;
    
	unordered_map<string, int> word_count;
	for(int i = 0; i < words.size(); ++i)
	{
		if(word_count.find(words[i]) == word_count.end())
			word_count[words[i]] = 0;
		++word_count[words[i]];
	}

	int len = words[0].size();
	unordered_map<string, queue<int> > substr_index;
	for(int i = 0; i < len; ++i)
	{
		int start = i;
		substr_index.clear();
		for(int j = i; j < s.size(); j += len)
		{
			string str = s.substr(j, len);
			if(word_count.find(str) == word_count.end())
			{
				start = j + len;
				substr_index.clear();
				continue;
			}
			
			if(substr_index.find(str) == substr_index.end())
				substr_index[str] = queue<int>();

			substr_index[str].push(j);
			if(substr_index[str].size() > word_count[str])
			{
				start = substr_index[str].front() + len;
				for(unordered_map<string, queue<int> >::iterator it = substr_index.begin();
				    it != substr_index.end(); ++it)
				{
					while(it->second.size() && it->second.front() < start)
						it->second.pop();
				}
			}
    			
			
			bool found = (substr_index.size() == word_count.size());
			for(unordered_map<string, queue<int> >::iterator it = substr_index.begin();
			    it != substr_index.end(); ++it)
			{
				if(it->second.size() != word_count[it->first])
				{
					found = false;
					break;
				}
			}

			if(found)
				results.push_back(start);    			
		}
	}
      
	return results;
}
