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

#include <string>
#include <queue>
#include <iostream>
#include <unordered_set>
#include <unordered_map>

using namespace std;

int ladderLength(string beginWord, string endWord, unordered_set<string>& wordList)
{
        wordList.erase(beginWord);
        wordList.erase(endWord);
        if(wordList.empty())
		return 0;
            
        int len = beginWord.size();

        queue<string> left_q;
        left_q.push(beginWord);
        unordered_map<string, int> left_dis;
        left_dis[beginWord] = 0;

	queue<string> right_q;
        left_q.push(endWord);
        unordered_map<string, int> right_dis;
        right_dis[endWord] = 0;

	while(!left_q.empty() && !right_q.empty())
        {
		string l = left_q.front();
		left_q.pop();
		for(int i = 0; i < len; ++i)
		{
			string s = l;
			for(char ch = 'a'; ch <= 'z'; ++ch)
			{
				l[i] = ch;
				if(wordList.find(l) != wordList.end() && left_dis.find(l) == left_dis.end())
				{
					if(right_dis.find(l) != right_dis.end())
						return left_dis[s] + right_dis[l];
					
					left_dis[l] = left_dis[s] + 1;
					left_q.push(l);
				}
			}
			l = s;
		}
		
		string r = right_q.front();
		right_q.pop();
		for(int i = 0; i < len; ++i)
		{
			string s = r;
			for(char ch = 'a'; ch <= 'z'; ++ch)
			{
				r[i] = ch;
				if(wordList.find(r) != wordList.end() && right_dis.find(r) == right_dis.end())
					right_dis[r] = right_dis[s] + 1;
			}
			r = s;
		}
        }
	
        return 0;
}

int main()
{
	string start = "a";
	string end = "c";
	unordered_set<string> dict({"a", "b", "c"});
	cout << ladderLength(start, end, dict) << endl;
	return 1;
}

/*
int GetMinimalPath(const string& start, const string& end, 
                       unordered_map<string, vector<string> >& adj,
                       unordered_map<string, int>& dis)
{
	vector<string>& nbs = adj[start];
	for(int i = 0; i < nbs.size(); ++i)
	{
		if(nbs[i] == end)
		{
			dis[start] = 2;
			break;
		}
		else
		{
			int len = dis[nbs[i]] != INT_MAX ? dis[nbs[i]] : GetMinimalPath(nbs[i], end, adj, dis);
			dis[start] = min(dis[start], len == INT_MAX ? len : 1 + len);
		}
	}
	return dis[start];
}
        
int ladderLength(string beginWord, string endWord, unordered_set<string>& wordList)
{
	wordList.insert(endWord);
	wordList.erase(beginWord);
	if(wordList.empty())
    		return 0;
	
	int len = beginWord.size();
	unordered_map<string, vector<string> > adj;
	unordered_map<string, int> dis;
        
	queue<string> word_queue;
	word_queue.push(beginWord);
	while(!word_queue.empty())
	{
		string cur = word_queue.front();
		word_queue.pop();
		adj[cur] = vector<string>();
		dis[cur] = INT_MAX;
            	
		for(int i = 0; i < len; ++i)
		{
			string s = cur;
			for(char ch = 'a'; ch <= 'z'; ++ch)
			{
				cur[i] = ch;
				if(wordList.find(cur) != wordList.end())
				{
					adj[s].push_back(cur);
					word_queue.push(cur);
					wordList.erase(cur);
				}
			}
			cur = s;
		}
	}
        
	int min_len = GetMinimalPath(beginWord, endWord, adj, dis);
	return min_len == INT_MAX ? 0 : min_len;
}
*/
