/*
  Given two numbers represented as strings, 
  return multiplication of the numbers as a string.

  Note:
  The numbers can be arbitrarily large and are non-negative.
  Converting the input string to integer is NOT allowed.
  You should NOT use internal library such as BigInteger.
*/

class Solution {
public:
    string multiply(string num1, string num2) {
        string product(num1.size() + num2.size(), '0');
        
        int start = product.size() - 1;
        for(int i = num2.size() - 1; i >= 0; --i, --start)
        {
            int digit2 = num2[i] - '0';
            int overflow = 0;
            for(int j = num1.size() - 1; j >= 0; --j)
            {
                int write = start - (num1.size() - 1 - j);
                int digitProduct = digit2 * (num1[j] - '0') + (product[write] - '0') + overflow;
                product[write] = digitProduct % 10 + '0';
                overflow = digitProduct / 10;
            }
            product[start - num1.size()] = overflow + '0';
        }
        
        for(int i = 0; i < product.size() - 1 && product[i] == '0'; product.erase(i, 1)) {}
        
        return product;
    }
};
