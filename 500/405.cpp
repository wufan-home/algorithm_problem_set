/*
    Given an integer, write an algorithm to convert it to hexadecimal. For negative integer, two’s complement method is used.

    Note:

    All letters in hexadecimal (a-f) must be in lowercase.
    The hexadecimal string must not contain extra leading 0s. 
    If the number is zero, it is represented by a single zero character '0'; 
    otherwise, the first character in the hexadecimal string will not be the zero character.
    The given number is guaranteed to fit within the range of a 32-bit signed integer.
    You must not use any method provided by the library which converts/formats the number to hex directly.
    Example 1:

    Input:
    26

    Output:
    "1a"
    Example 2:

    Input:
    -1

    Output:
    "ffffffff"
*/

class Solution {
public:
    Solution()
    {
        digitToChar[10] = 'a';
        digitToChar[11] = 'b';
        digitToChar[12] = 'c';
        digitToChar[13] = 'd';
        digitToChar[14] = 'e';
        digitToChar[15] = 'f';
    }
    
    string toHex(int num) {
        if(num == 0)
            return "0";
        
        string result(8, '0');    
        for(int i = 0; i < 8; ++i, num >>= 4)
        {
            int partNum = 0;
            for(int j = 3; j >= 0; --j)
            {
                int digit = (num >> j) & 1;
                partNum = 2 * partNum + digit;
            }
            
            result[7 - i] = (partNum < 10 ? partNum + '0' : digitToChar[partNum]);
        }
        
        while(result[0] == '0')
            result.erase(result.begin());
        
        return result;
    }
    
private:

    unordered_map<int, char> digitToChar;
};
