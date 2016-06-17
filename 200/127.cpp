/*
  Given two words (beginWord and endWord), and a dictionary's word list, 
  find the length of shortest transformation sequence from beginWord to endWord, such that:
  Only one letter can be changed at a time
  Each intermediate word must exist in the word list
  For example,
  Given:
  beginWord = "hit"
  endWord = "cog"
  wordList = ["hot","dot","dog","lot","log"]
  As one shortest transformation is "hit" -> "hot" -> "dot" -> "dog" -> "cog",
  return its length 5.
*/


int ladderLength(string beginWord, string endWord, unordered_set<string>& wordList)
{
	if (beginWord.empty() || endWord.empty() || wordList.empty())
		return 0;

	if (beginWord == endWord)
		return 1;

	int len = 1;
	queue<string> word_queue;
	word_queue.push(beginWord);
	int count = 1;
	int size = wordList.begin()->size();
	wordList.insert(endWord);
	while (word_queue.size())
	{
		string cur = word_queue.front();
		word_queue.pop();
		--count;

		if (cur == endWord)
    		return len;

		for(int i = 0; i < size; ++i)
		{
		    string temp = cur;
		    for(char l = 'a'; l <= 'z'; ++l)
		    {
		        temp[i] = l;
		        if(wordList.find(temp) != wordList.end())
		        {
		            word_queue.push(temp);
		            wordList.erase(temp);
		        }
		    }
		}
		
		if(!count)
		{
		    ++len;
		    count = word_queue.size();
		}
	}

	return 0;
}
