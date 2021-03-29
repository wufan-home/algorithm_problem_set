/*
    A strobogrammatic number is a number that looks the same when rotated 180 degrees (looked at upside down).

    Write a function to determine if a number is strobogrammatic. The number is represented as a string.

    For example, the numbers "69", "88", and "818" are all strobogrammatic.
*/

class Solution {
public:
    Solution()
    {
        stroboGrammaticDigitMap['1'] = '1';
        stroboGrammaticDigitMap['6'] = '9';
        stroboGrammaticDigitMap['8'] = '8';
        stroboGrammaticDigitMap['9'] = '6';
        stroboGrammaticDigitMap['0'] = '0';
    }

    bool isStrobogrammatic(string num) {
        string reverse(num.size(), '\0');
        for(int i = num.size() - 1, j = 0; i >= j ; --i, ++j)
        {
            if(stroboGrammaticDigitMap.find(num[i]) == stroboGrammaticDigitMap.end() || 
                num[j] != stroboGrammaticDigitMap[num[i]])
                return false;
        }
        
        return true;
    }
private:
    unordered_map<char, char> stroboGrammaticDigitMap;
};
