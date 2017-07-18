/*
    Write a function to generate the generalized abbreviations of a word.

    Example:
    Given word = "word", return the following list (order does not matter):
    ["4","3d","2r1","2rd","1o2","1o1d","1or1","1ord","w3","w2d","w1r1","w1rd","wo2","wo1d","wor1","word"]
*/

class Solution {
public:
    vector<string> generateAbbreviations(string word) {
        int len = word.size();
        abbs.push_back(word);
        vector<int> indexList(len, 0);
        for(int i = 1; i <= len; ++i)
            findAbbrevWithIndexList(word, indexList, 0, 0, i);
        return abbs;
    }
    
private:
    void findAbbrevWithIndexList(string& word, vector<int>& indexList, int start, int used, int bound)
    {
        if(used == bound)
        {
            string abb;
            int size = indexList.size();
            for(int i = 0; i < size;)
            {
                if(indexList[i] == 0)
                    abb.push_back(word[i++]);
                else
                {
                    int change = 0;
                    for(; i < size && indexList[i] == 1; ++i)
                        change += indexList[i];
                    abb.append(to_string(change));
                }
            }
            abbs.push_back(abb);
            return;
        }
        
        if(start >= indexList.size())
            return;
        
        for(int j = start; j < indexList.size(); ++j)
        {
            indexList[j] = 1;
            findAbbrevWithIndexList(word, indexList, j + 1, used + 1, bound);
            indexList[j] = 0;
        }
    }
    
    vector<string> abbs;
};
