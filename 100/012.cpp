/*
  Given an integer, convert it to a roman numeral.
  Input is guaranteed to be within the range from 1 to 3999.
*/

class Solution {
public:
    string getExpressionByUnit(int digit, const char single, const char half, const char full)
    {
        string expression("");
        if(digit == 4)
        {
            expression.push_back(single);
            expression.push_back(half);
        }
        else if(digit == 9)
        {
            expression.push_back(single);
            expression.push_back(full);
        }
        else
        {
            if(digit >= 5)
            {
                expression.push_back(half);
                digit %= 5;
            }
            
            for(int i = 0; i < digit; ++i)
                expression.push_back(single);
        }
        
        return expression;
    }
    
    string intToRoman(int num) 
    {
        vector<int> digits(4, 0);
        for(int i = 0, bound = 1000; i < 4; ++i, bound /= 10)
        {
            digits[i] = num / bound;
            num %= bound;
        }
          
        string expression("");  
        expression.append(getExpressionByUnit(digits[0], thousand, '\0', '\0'));
        expression.append(getExpressionByUnit(digits[1], hundred, five_hundred, thousand));
        expression.append(getExpressionByUnit(digits[2], ten, fifty, hundred));
        expression.append(getExpressionByUnit(digits[3], one, five, ten));
        
        return expression;
    }
    
private:
    const static char one = 'I';
    const static char five = 'V';
    const static char ten = 'X';
    const static char fifty = 'L';
    const static char hundred = 'C';
    const static char five_hundred = 'D';
    const static char thousand = 'M';
};
