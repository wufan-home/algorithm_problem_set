#include <iostream>
#include <string>
#include <set>
#include <queue>

using namespace std;

vector<vector<string> > findLadders(string beginWord, string endWord,
				    set<string> &wordList)
{
	vector<vector<string> > ladders;
        if(beginWord.size() != endWord.size() ||
	   beginWord.size() != wordList.begin()->size())
		return ladders;

	wordList.erase(beginWord);
	wordList.erase(endWord);
	int word_length = beginWord.size();
	queue<vector<string> > words_queue;
	words_queue.push(vector<string>(1, beginWord));
	while(!words_queue.empty())
	{
		if(!ladders.empty() && words_queue.front().size() >= ladders[0].size())
			break;

		vector<string> cur_list = words_queue.front();
		for(int i = 0; i < cur_list.size(); ++i)
			cout << cur_list[i] << "->";
		cout << endl;
		words_queue.pop();
		wordList.erase(*(cur_list.end() - 1));
		for(int i = 0; i < word_length; ++i)
		{
			string last_word = *(cur_list.end() - 1);
			cout << last_word << endl;
			for(char c = 'a'; c <= 'z'; ++c)
			{
				last_word[i] = c;
				cout << last_word << ", ";
				if(last_word == endWord ||
				   wordList.find(last_word) != wordList.end())
				{
					cur_list.push_back(last_word);
					if(last_word == endWord)
					{
						cout << "Found!!!" << " ";
						ladders.push_back(cur_list);
					}
					else
					{
						cout << "push!!!" << " ";
						words_queue.push(cur_list);
					}
					cur_list.pop_back();
				}
			}
		}
		cout << endl;
		cout << "size = " << words_queue.size() << endl;
	}

	return ladders;
}

int main()
{
	string s1 = "red";
	string s2 = "tax";
	set<string> dict;
	dict.insert("ted");
	dict.insert("tex");
	dict.insert("tad");
	dict.insert("den");
	dict.insert("rex");
	dict.insert("pee");
	findLadders(s1, s2, dict);
	return 1;
}
