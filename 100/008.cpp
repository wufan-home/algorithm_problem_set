/*
  Implement atoi to convert a string to an integer.
  Hint: Carefully consider all possible input cases. 
  If you want a challenge, please do not see below and ask yourself what are the possible input cases.
  Notes: It is intended for this problem to be specified vaguely (ie, no given input specs). 
  You are responsible to gather all the input requirements up front.
  Update (2015-02-10):
  The signature of the C++ function had been updated. 
  If you still see your function signature accepts a const char * argument, 
  please click the reload button  to reset your code definition.
  spoilers alert... click to show requirements for atoi.
  Requirements for atoi:
  The function first discards as many whitespace characters as necessary until the first non-whitespace character is found. 
  Then, starting from this character, takes an optional initial plus or minus sign followed by as many numerical digits as possible, 
  and interprets them as a numerical value.
  The string can contain additional characters after those that form the integral number, 
  which are ignored and have no effect on the behavior of this function.
  If the first sequence of non-whitespace characters in str is not a valid integral number, 
  or if no such sequence exists because either str is empty or it contains only whitespace characters, no conversion is performed.
  If no valid conversion could be performed, a zero value is returned. If the correct value is out of the range of representable values, 
  INT_MAX (2147483647) or INT_MIN (-2147483648) is returned.

  Solution: Similar as the problem 7.
*/


	bool isSign(const char ch)
    {
        return ch == '+' || ch == '-';
    }
    
    bool isNumber(const char ch)
    {
        return ch >= '0' && ch <= '9';
    }
    
    int myAtoi(string str) {
        if(str.empty()) 
            return 0;
            
        int cur = 0;
        int sign = 1;
        for(; cur < str.size(); ++cur)
        {
            if(str[cur] == ' ')
                continue;

            if(isSign(str[cur]))
            {
                sign = str[cur] == '+' ? 1 : -1;
                ++cur;
                break;
            }
            else if(isNumber(str[cur]))
                break;
            else
                return 0;
        }

        int number = 0;
        const int bound = INT_MAX / 10;
        for(; cur < str.size() && isNumber(str[cur]); ++cur)
        {
            const int candidate = number * 10;
            const int addin = str[cur] - '0';
            if(number > bound || 
              (sign == 1 && (-1) * candidate < addin - INT_MAX) || 
              (sign == -1 && (-1) * candidate < addin + INT_MIN))
                return sign == 1 ? INT_MAX : INT_MIN;
                
            number = candidate + addin;
        }
        
        return sign * number;
    }
