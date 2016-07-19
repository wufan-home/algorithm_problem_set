/*
  Given two words (beginWord and endWord), and a dictionary's word list, 
  find all shortest transformation sequence(s) from beginWord to endWord, such that:
  Only one letter can be changed at a time
  Each intermediate word must exist in the word list
  For example,
  Given:
  beginWord = "hit"
  endWord = "cog"
  wordList = ["hot","dot","dog","lot","log"]
  Return
  [
    ["hit","hot","dot","dog","cog"],
    ["hit","hot","lot","log","cog"]
  ]
  Note:
  All words have the same length.
  All words contain only lowercase alphabetic characters.
*/

void GetPath(const string& start, const string& end,
	     unordered_map<string, vector<string> >& adj,
	     vector<string>& path, vector<vector<string> >& pathes)
{
    	if(start == end)
    		pathes.push_back(path);
    	else
    	{
    		vector<string>& nbs = adj[start];
    		for(int i = 0; i < nbs.size(); ++i)
    		{
    			path.push_back(nbs[i]);
    			GetPath(nbs[i], end, adj, path, pathes);
    			path.pop_back();
    		}
    	}
}
    
vector<vector<string>> findLadders(string beginWord, string endWord, unordered_set<string> &wordList)
{
    	vector<vector<string> > ladders;
    	if(wordList.empty())
    		return ladders;

	int len = beginWord.size();
    	wordList.insert(endWord);
    	wordList.erase(beginWord);
	unordered_map<string, vector<string> > adj;

    	queue<string> word_queue;
    	word_queue.push(beginWord);
    	int level_size = word_queue.size();

	unordered_set<string> visited;
	unordered_set<string> finished;
    	bool found_end = false;
    	while(level_size)
    	{
    		string cur = word_queue.front();
    		word_queue.pop();
    		--level_size;
    		adj[cur] = vector<string>();
    		for(int i = 0; i < len; ++i)
    		{
    			string str = cur;
    			for(char c = 'a'; c <= 'z'; ++c)
    			{
    				cur[i] = c;
    				if(cur == endWord)
    				{
					adj[str].push_back(cur);
					found_end = true;
    				}
    				else if(wordList.find(cur) != wordList.end())
    				{
    					adj[str].push_back(cur);
					if(visited.find(cur) == visited.end())
					{
						word_queue.push(cur);
						visited.insert(cur);
						finished.insert(cur);
					}
    				}
    			}
    			cur = str;
    		}

    		if(level_size == 0 && !found_end)
    		{
    			level_size = word_queue.size();
    			for(unordered_set<string>::iterator it = finished.begin(); it != finished.end(); ++it)
				wordList.erase(*it);
			finished.clear();
    		}
    	}

    	if(!found_end)
    		return ladders;

    	vector<string> path;
    	path.push_back(beginWord);
    	GetPath(beginWord, endWord, adj, path, ladders);
    	
    	return ladders;
}
