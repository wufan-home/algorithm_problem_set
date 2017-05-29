/*
    This is a follow up of Shortest Word Distance. 
    The only difference is now you are given the list of words and your method will be called repeatedly many times 
    with different parameters. How would you optimize it?

    Design a class which receives a list of words in the constructor, 
    and implements a method that takes two words word1 and word2 and return the shortest distance between these two words in the list.

    For example,
    Assume that words = ["practice", "makes", "perfect", "coding", "makes"].

    Given word1 = “coding”, word2 = “practice”, return 3.
    Given word1 = "makes", word2 = "coding", return 1.

    Note:
    You may assume that word1 does not equal to word2, and word1 and word2 are both in the list.
*/

class WordDistance {
public:
    WordDistance(vector<string> words) {
        for(int i = 0; i < words.size(); ++i)
        {
            if(wordToIndices.find(words[i]) == wordToIndices.end())
                wordToIndices[words[i]] = vector<int>();
                
            wordToIndices[words[i]].push_back(i);
        }
    }
    
    int shortest(string word1, string word2) 
    {
        const vector<int>& wordIndices1 = wordToIndices[word1];
        const vector<int>& wordIndices2 = wordToIndices[word2];
        
        int minDistance = INT_MAX;
        for(int i = 0, j = 0; i < wordIndices1.size() && j < wordIndices2.size();)
        {
            minDistance = min(minDistance, abs(wordIndices1[i] - wordIndices2[j]));
            if(wordIndices1[i] <= wordIndices2[j])
                ++i;
            else
                ++j;
        }
        
        return minDistance;
    }
    
private:
    unordered_map<string, vector<int>> wordToIndices;
};

/**
 * Your WordDistance object will be instantiated and called as such:
 * WordDistance obj = new WordDistance(words);
 * int param_1 = obj.shortest(word1,word2);
 */
