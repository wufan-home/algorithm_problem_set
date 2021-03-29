/*
  Given a digit string, return all possible letter combinations that the number could represent.

  A mapping of digit to letters (just like on the telephone buttons) is given below.

  Input:Digit string "23"
  Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].

  Note:
  Although the above answer is in lexicographical order, your answer could be in any order you want.

  Solution:
  Recursive method.
*/

class Solution {
public:
    Solution()
    {
        m_number_to_chars[0] = vector<char>({' '});
        m_number_to_chars[2] = vector<char>({'a', 'b', 'c'});
        m_number_to_chars[3] = vector<char>({'d', 'e', 'f'});
        m_number_to_chars[4] = vector<char>({'g', 'h', 'i'});
        m_number_to_chars[5] = vector<char>({'j', 'k', 'l'});
        m_number_to_chars[6] = vector<char>({'m', 'n', 'o'});
        m_number_to_chars[7] = vector<char>({'p', 'r', 'q', 's'});
        m_number_to_chars[8] = vector<char>({'t', 'u', 'v'});
        m_number_to_chars[9] = vector<char>({'w', 'x', 'y', 'z'});
    }
    
    vector<string>* poplulateCombinationsByIndex(const string& digits, int index)
    {
        vector<string>* newResults = new vector<string>();
        
        vector<string>* prevResults = NULL;
        if(index < digits.size() - 1)
            prevResults = poplulateCombinationsByIndex(digits, index + 1);
            
        const int key = digits[index] - '0';
        const vector<char>& charVector = m_number_to_chars[key];
        
        for(int i = 0; i < charVector.size(); ++i)
        {
            string prefix(1, charVector[i]);
            if(index == digits.size() - 1)
                (*newResults).push_back(prefix);
            else
            {
                for(int j = 0; j < (*prevResults).size(); ++j)
                {
                    string combination(prefix);
                    combination.append((*prevResults)[j]);
                    (*newResults).push_back(combination);
                }
            }
        }
        
        return newResults;
    }
    
    vector<string> letterCombinations(string digits) {
        if(digits.empty())
            return vector<string>();
        
        return *(poplulateCombinationsByIndex(digits, 0));
    }
private:
    unordered_map<int, vector<char>> m_number_to_chars;
};
