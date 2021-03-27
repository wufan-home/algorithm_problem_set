/*
    This is a follow up of Shortest Word Distance. The only difference is now word1 could be the same as word2.

    Given a list of words and two words word1 and word2, return the shortest distance between these two words in the list.

    word1 and word2 may be the same and they represent two individual words in the list.

    For example,
    Assume that words = ["practice", "makes", "perfect", "coding", "makes"].

    Given word1 = “makes”, word2 = “coding”, return 1.
    Given word1 = "makes", word2 = "makes", return 3.

    Note:
    You may assume word1 and word2 are both in the list.
*/

class Solution {
public:
    int shortestWordDistance(vector<string>& words, string word1, string word2) {
        int minDistance = INT_MAX;
        for(int index = 0, first = -1, second = -1; index < words.size(); ++index)
        {
            if(words[index] == word1 || words[index] == word2)
            {
                if(word1 == word2)
                {
                    if(first < second)
                        first = index;
                    else
                        second = index;
                }
                else
                {
                    if(words[index] == word1)
                        first = index;
                    else
                        second = index;
                }
                
                if(first != -1 && second != -1)
                    minDistance = min(minDistance, (int)abs(first - second));
            }
        }
        
        return minDistance;
    }
};
