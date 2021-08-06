/*
    A transformation sequence from word beginWord to word endWord using a dictionary wordList is a sequence of words beginWord -> s1 -> s2 -> ... -> sk such that:

    Every adjacent pair of words differs by a single letter.
    Every si for 1 <= i <= k is in wordList. Note that beginWord does not need to be in wordList.
    sk == endWord
    Given two words, beginWord and endWord, and a dictionary wordList, return the number of words in the shortest transformation sequence from beginWord to endWord, or 0 if no such sequence exists.



    Example 1:

    Input: beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log","cog"]
    Output: 5
    Explanation: One shortest transformation sequence is "hit" -> "hot" -> "dot" -> "dog" -> cog", which is 5 words long.
    Example 2:

    Input: beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log"]
    Output: 0
    Explanation: The endWord "cog" is not in wordList, therefore there is no valid transformation sequence.


    Constraints:

    1 <= beginWord.length <= 10
    endWord.length == beginWord.length
    1 <= wordList.length <= 5000
    wordList[i].length == beginWord.length
    beginWord, endWord, and wordList[i] consist of lowercase English letters.
    beginWord != endWord
    All the words in wordList are unique.
*/

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int len = beginWord.size();
        unordered_set<string> dict(wordList.begin(), wordList.end());
        queue<string> q;
        q.push(beginWord);
        unordered_set<string> visited;
        visited.insert(beginWord);
        int ans = 1;
        bool found = false;
        for (int level = q.size();!q.empty();) {
            if (q.front() == endWord) {
                found = true;
                break;
            }
            string cur = q.front();
            q.pop();
            for (int i = 0; i < len; ++i) {
                char origin = cur[i];
                for (int j = 0; j < 26; ++j) {
                    cur[i] = 'a' + j;
                    
                    if (visited.count(cur) == 0 && dict.count(cur) > 0) {
                        visited.insert(cur);
                        q.push(cur);
                    }
                }
                cur[i] = origin;
            }
            if (--level == 0) {
                ++ans;
                level = q.size();
            }
        }
        return !found ? 0 : ans;
    }
};
