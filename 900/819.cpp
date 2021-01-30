/*
    Given a paragraph and a list of banned words, return the most frequent word that is not in the list of banned words.  It is guaranteed there is at least one word that isn't banned, and that the answer is unique.

    Words in the list of banned words are given in lowercase, and free of punctuation.  Words in the paragraph are not case sensitive.  The answer is in lowercase.



    Example:

    Input: 
    paragraph = "Bob hit a ball, the hit BALL flew far after it was hit."
    banned = ["hit"]
    Output: "ball"
    Explanation: 
    "hit" occurs 3 times, but it is a banned word.
    "ball" occurs twice (and no other word does), so it is the most frequent non-banned word in the paragraph. 
    Note that words in the paragraph are not case sensitive,
    that punctuation is ignored (even if adjacent to words, such as "ball,"), 
    and that "hit" isn't the answer even though it occurs more because it is banned.



    Note:

        1 <= paragraph.length <= 1000.
        0 <= banned.length <= 100.
        1 <= banned[i].length <= 10.
        The answer is unique, and written in lowercase (even if its occurrences in paragraph may have uppercase symbols, and even if it is a proper noun.)
        paragraph only consists of letters, spaces, or the punctuation symbols !?',;.
        There are no hyphens or hyphenated words.
        Words only consist of letters, never apostrophes or other punctuation symbols.


*/

class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        unordered_set<string> banned_words;
        int size = banned.size();
        for (int i = 0; i < size; ++i) {
            toLowerCase(banned[i]);
            banned_words.insert(banned[i]);
        }
        
        unordered_map<string, int> freqMap;
        char* cstr = new char[paragraph.size() + 1];
        strcpy(cstr, paragraph.c_str());
        int maxCount = 0;
        string maxFreqWord = "";
        char* psplit = strtok(cstr, " !?',;.");
        for (; psplit != NULL; psplit = strtok(NULL, " !?',;.")) {
            string cur = string(psplit);
            toLowerCase(cur);
            if (banned_words.count(cur) != 0)
                continue;
            
            if (freqMap.count(cur) == 0) {
                freqMap[cur] = 0;
            }
            
            if (maxCount < ++freqMap[cur]) {
                maxCount = freqMap[cur];
                maxFreqWord = cur;
            }
        }
        
        return maxFreqWord;
    }
    
private:
    void toLowerCase(string& str) {
        for (int i = 0; i < str.size(); ++i) {
            if (str[i] >= 'A' && str[i] <= 'Z') {
                str[i] = str[i] - 'A' + 'a';
            }
        }
    }
};
