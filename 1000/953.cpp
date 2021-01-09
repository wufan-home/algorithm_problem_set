/*
    In an alien language, surprisingly they also use english lowercase letters, but possibly in a different order. The order of the alphabet is some permutation of lowercase letters.

    Given a sequence of words written in the alien language, and the order of the alphabet, return true if and only if the given words are sorted lexicographicaly in this alien language.



    Example 1:

    Input: words = ["hello","leetcode"], order = "hlabcdefgijkmnopqrstuvwxyz"
    Output: true
    Explanation: As 'h' comes before 'l' in this language, then the sequence is sorted.
    Example 2:

    Input: words = ["word","world","row"], order = "worldabcefghijkmnpqstuvxyz"
    Output: false
    Explanation: As 'd' comes after 'l' in this language, then words[0] > words[1], hence the sequence is unsorted.
    Example 3:

    Input: words = ["apple","app"], order = "abcdefghijklmnopqrstuvwxyz"
    Output: false
    Explanation: The first three characters "app" match, and the second string is shorter (in size.) According to lexicographical rules "apple" > "app", because 'l' > '∅', where '∅' is defined as the blank character which is less than any other character (More info).


    Constraints:

    1 <= words.length <= 100
    1 <= words[i].length <= 20
    order.length == 26
    All characters in words[i] and order are English lowercase letters.
*/

class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        vector<int> orderList(26, -1);
        for (int i = 0; i < 26; ++i) {
            orderList[order[i] - 'a'] = i;
        }
        
        bool res = true;
        int size = words.size();
        for (int i = 0; i < size - 1; ++i) {
            int firstSize = words[i].size();
            int secondSize = words[i + 1].size();
            for (int j = 0, k = 0; j < firstSize || k < secondSize; ++j, ++k) {
                if (j >= firstSize && k < secondSize) {
                    break;
                }
                else if (j < firstSize && k >= secondSize) {
                    res = false;
                    break;
                }
                else {
                    if (orderList[words[i][j] - 'a'] < orderList[words[i + 1][k] - 'a']) {
                        break;
                    }
                    else if (orderList[words[i][j] - 'a'] == orderList[words[i + 1][k] - 'a']) {
                        continue;
                    }
                    else {
                        res = false;
                        break;
                    }
                }
            }
        }
        
        return res;
    }
};
