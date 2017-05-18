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

class Solution {
public:
	Solution() : minPathLength(INT_MAX) {}

	vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
		if (find(wordList.begin(), wordList.end(), endWord) == wordList.end())
			return vector<vector<string>>(1, vector<string>());

		unordered_set<string> dict;
		dict.insert(beginWord);
		dict.insert(endWord);
		for (int i = 0; i < wordList.size(); ++i)
			dict.insert(wordList[i]);

		queueForPrevWords.push(beginWord);
		wordToLengthAndPrevWords[beginWord] = make_pair(1, vector<string>());
		queueForNextWords.push(endWord);
		wordToLengthAndNextWords[endWord] = make_pair(1, vector<string>());
		while (!queueForPrevWords.empty() && !queueForNextWords.empty())
		{
			string word = queueForPrevWords.front();
			queueForPrevWords.pop();
			findAdjacentWords(word, dict, true);

			word = queueForNextWords.front();
			queueForNextWords.pop();
			findAdjacentWords(word, dict, false);
		}

		return paths;
	}

private:
	void findAdjacentWords(const string& curWord, const unordered_set<string>& dict, bool forward)
	{
		string adjacentWord = curWord;
		int wordLength = adjacentWord.size();
		for (int i = 0; i < wordLength; ++i)
		{
			for (char c = 'a'; c <= 'z'; ++c)
			{
				adjacentWord[i] = c;
				if (dict.find(adjacentWord) == dict.end() || adjacentWord == curWord)
					continue;

				if (forward)
				{
					if (wordToLengthAndNextWords.find(adjacentWord) != wordToLengthAndNextWords.end())
					{
						int length = wordToLengthAndPrevWords[curWord].first + wordToLengthAndNextWords[adjacentWord].first;
						if (minPathLength == INT_MAX || length == minPathLength)
						{
							minPathLength = length;
							addPathsToCollection(curWord, adjacentWord);
						}
					}
					else if (wordToLengthAndPrevWords.find(adjacentWord) != wordToLengthAndPrevWords.end() &&
						wordToLengthAndPrevWords[curWord].first + 1 == wordToLengthAndPrevWords[adjacentWord].first)
					{
						wordToLengthAndPrevWords[adjacentWord].second.push_back(curWord);
					}
					else if (wordToLengthAndPrevWords.find(adjacentWord) == wordToLengthAndPrevWords.end())
					{
						wordToLengthAndPrevWords[adjacentWord] = make_pair(wordToLengthAndPrevWords[curWord].first + 1, vector<string>(1, curWord));
						queueForPrevWords.push(adjacentWord);
					}
				}
				else
				{
					if (wordToLengthAndNextWords.find(adjacentWord) != wordToLengthAndNextWords.end() &&
						wordToLengthAndNextWords[curWord].first + 1 == wordToLengthAndNextWords[adjacentWord].first)
					{
						wordToLengthAndNextWords[adjacentWord].second.push_back(curWord);
					}
					else if (wordToLengthAndNextWords.find(adjacentWord) == wordToLengthAndNextWords.end())
					{
						wordToLengthAndNextWords[adjacentWord] = make_pair(wordToLengthAndNextWords[curWord].first + 1, vector<string>(1, curWord));
						queueForNextWords.push(adjacentWord);
					}
				}
			}

			adjacentWord[i] = curWord[i];
		}
	}

	void addPathsToCollection(const string& endFromBeginWord, const string& startToEndWord)
	{
		vector<vector<string>> pathsFromBeginWord = getPaths(endFromBeginWord, false);
		vector<vector<string>> pathsToEndWord = getPaths(startToEndWord, true);

		for (int i = 0; i < pathsFromBeginWord.size(); ++i)
		{
			for (int j = 0; j < pathsToEndWord.size(); ++j)
			{
				paths.push_back(pathsFromBeginWord[i]);
				for (int k = 0; k < pathsToEndWord[j].size(); ++k)
					paths[paths.size() - 1].push_back(pathsToEndWord[j][k]);
			}
		}
	}

	vector<vector<string>> getPaths(const string& word, bool forward)
	{
		vector<vector<string>> collection;
		unordered_map<string, pair<int, vector<string>>>& cachedPaths = forward ? wordToLengthAndNextWords : wordToLengthAndPrevWords;
		if (cachedPaths[word].first == 1)
			return vector<vector<string>>(1, vector<string>(1, word));

		for (int i = 0; i < cachedPaths[word].second.size(); ++i)
		{
			vector<vector<string>> paths = getPaths(cachedPaths[word].second[i], forward);
			for (int j = 0; j < paths.size(); ++j)
			{
				if (!forward)
				{
					collection.push_back(vector<string>(paths[i]));
					collection[collection.size() - 1].push_back(word);
				}
				else
				{
					collection.push_back(vector<string>(1, word));
					for (int k = 0; k < paths[j].size(); ++k)
						collection[collection.size() - 1].push_back(paths[j][k]);
				}
			}
		}

		return collection;
	}

	vector<vector<string>> paths;

	int minPathLength;

	unordered_map<string, pair<int, vector<string>>> wordToLengthAndPrevWords;
	queue<string> queueForNextWords;

	unordered_map<string, pair<int, vector<string>>> wordToLengthAndNextWords;
	queue<string> queueForPrevWords;
};
