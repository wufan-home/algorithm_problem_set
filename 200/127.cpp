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

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dict;
        for(int i = 0; i < wordList.size(); ++i)
        {
            if(wordList[i] == beginWord || wordList[i] == endWord)
                continue;
                
            dict.insert(wordList[i]);
        }
        
        beginToWord[beginWord] = 1;
        queueFromBegin.push(beginWord);
        
        wordToEnd[endWord] = 1;
        queueFromEnd.push(endWord);

        while(!queueFromBegin.empty() && !queueFromEnd.empty())
        {
            string word = queueFromBegin.front();
            queueFromBegin.pop();
            int length = searchAdjacentWords(word, dict, true);
            if(length > 0)
                return length;
                
            word = queueFromEnd.front();
            queueFromEnd.pop();
            length = searchAdjacentWords(word, dict, false);
            if(length > 0)
                return length;
        }
        
        return 0;
    }
private:
    int searchAdjacentWords(const string& word, const unordered_set<string>& dict, bool forward)
    {
        //cout << "Now " << word << " ========== " << (forward ? "From start" : "From End") << endl;
        string cur = word;
        int len = cur.size();
        for(int i = 0; i < len; ++i)
        {
            for(char c = 'a'; c <= 'z'; ++c)
            {
                cur[i] = c;
                if(dict.find(cur) == dict.end())
                    continue;

                if(forward)
                {
                    if(wordToEnd.find(cur) != wordToEnd.end())
                    {
                        /*cout << "forward " << word << " -> " << cur << endl;
                        cout << beginToWord[word] << endl;
                        cout << wordToEnd[cur] << endl;*/
                        return beginToWord[word] + wordToEnd[cur];
                    }
                    
                    if(beginToWord.find(cur) != beginToWord.end())
                        continue;

                    beginToWord[cur] = beginToWord[word] + 1;
                    queueFromBegin.push(cur);
                    //cout << cur << ": " << beginToWord[cur] << endl;
                }
                else
                {
                    if(beginToWord.find(cur) != beginToWord.end())
                    {
                        /*cout << "backword " << cur << " -> " << word << endl;
                        cout << wordToEnd[word] << endl;
                        cout << beginToWord[cur] << endl;*/
                        return beginToWord[cur] + wordToEnd[word];
                    }
                    
                    if(wordToEnd.find(cur) != wordToEnd.end())
                        continue;

                    wordToEnd[cur] = wordToEnd[word] + 1;
                    queueFromEnd.push(cur);
                    //cout << cur << ": " << wordToEnd[cur] << ", " << "backward" << endl;
                }
            }
            
            cur = word;
        }
        
        return 0;
    }

    unordered_map<string, int> beginToWord;
    queue<string> queueFromBegin;
    
    unordered_map<string, int> wordToEnd;
    queue<string> queueFromEnd;
};
