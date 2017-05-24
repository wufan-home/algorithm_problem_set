/*
    Given two non-negative integers num1 and num2 represented as string, return the sum of num1 and num2.

    Note:

    The length of both num1 and num2 is < 5100.
    Both num1 and num2 contains only digits 0-9.
    Both num1 and num2 does not contain any leading zero.
    You must not use any built-in BigInteger library or convert the inputs to integer directly.
*/

class Solution {
public:
    string addStrings(string num1, string num2) {
        int maxLen = max(num1.size(), num2.size());
        string sumString(maxLen, '0');
        int overflow = 0;
        for(int i1 = num1.size() - 1, i2 = num2.size() - 1, i = sumString.size() - 1; i1 >= 0 || i2 >= 0; --i1, --i2, --i)
        {
            int sum = (i1 >= 0 ? num1[i1] - '0' : 0) + (i2 >= 0 ? num2[i2] - '0' : 0) + overflow;
            overflow = sum / 10;
            sum %= 10;
            sumString[i] = sum + '0';
        }
        
        string result;
        if(overflow > 0)
            result.push_back(overflow + '0');
            
        result.append(sumString);
        return result;
    }
};
