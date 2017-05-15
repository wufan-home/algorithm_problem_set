/*
    Given a non-empty string s and an abbreviation abbr, return whether the string matches with the given abbreviation.

    A string such as "word" contains only the following valid abbreviations:

    ["word", "1ord", "w1rd", "wo1d", "wor1", "2rd", "w2d", "wo2", "1o1d", "1or1", "w1r1", "1o2", "2r1", "3d", "w3", "4"]
    Notice that only the above abbreviations are valid abbreviations of the string "word". Any other string is not a valid abbreviation of "word".

    Note:
    Assume s contains only lowercase letters and abbr contains only lowercase letters and digits.

    Example 1:
    Given s = "internationalization", abbr = "i12iz4n":

    Return true.
    Example 2:
    Given s = "apple", abbr = "a2e":

    Return false.
    Show Company Tags
    Show Tags
    Show Similar Problems
*/

class Solution {
public:
    bool validWordAbbreviation(string word, string abbr) {
        int abbrIndex = 0;
        int wordIndex = 0;
        while(wordIndex < word.size() && abbrIndex < abbr.size())
        {
            if(abbr[abbrIndex] >= '1' && abbr[abbrIndex] <= '9')
            {
                int count = 0;
                for(; abbrIndex < abbr.size() && abbr[abbrIndex] >= '0' && abbr[abbrIndex] <= '9'; ++abbrIndex)
                    count = 10 * count + (abbr[abbrIndex] - '0');
                wordIndex += count;
            }
            else
            {
                if(abbr[abbrIndex++] != word[wordIndex++])
                    return false;
            }
        }
        
        return wordIndex == word.size() && abbrIndex == abbr.size();
    }
};
