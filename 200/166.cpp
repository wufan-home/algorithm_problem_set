/*
    Given two integers representing the numerator and denominator of a fraction, 
    return the fraction in string format.

    If the fractional part is repeating, enclose the repeating part in parentheses.

    For example,

    Given numerator = 1, denominator = 2, return "0.5".
    Given numerator = 2, denominator = 1, return "2".
    Given numerator = 2, denominator = 3, return "0.(6)".
*/

class Solution {
public:
    string NumericToString(unsigned int num)
    {
        string s_num;
        if(num == 0)
            return "0";
            
        while(num) {
            s_num.insert(s_num.begin(), num % 10 + '0');
            num /= 10;
        }
        
        return s_num;
    }
    
    string fractionToDecimal(int numerator, int denominator) {
        string decimal;

        if(numerator == 0)
            return "0";

        if((numerator < 0 && denominator > 0) || (numerator > 0 && denominator < 0))
            decimal = "-";

        unsigned long long num = (numerator < 0 ? -1 : 1) * static_cast<long long>(numerator);
        unsigned long long den = (denominator < 0 ? -1 : 1) * static_cast<long long>(denominator);
        unsigned long long quo = num / den;
        unsigned long long res = num % den;
        if(num == 0)
            return "0";
        decimal.append(NumericToString(quo));
        if(res == 0)
            return decimal;

        decimal.push_back('.');
        num = res * 10;
        map<pair<unsigned long long, unsigned long long>, int> ress;
        string fraction;
        while(1) {
            quo = num / den;
            res = num % den;
            num = res * 10;

            if(res != 0 && ress.find(make_pair(quo, res)) == ress.end()) {
                fraction.push_back(quo + '0');
                ress[make_pair(quo, res)] = fraction.size() - 1;
                num = res * 10;
            } else {
                if(res == 0)
                    fraction.push_back(quo + '0');
                break;
            }
        }

        if(res == 0)
            decimal.append(fraction);
        else {
            cout << fraction << endl;
            for(int i = 0; i < fraction.size(); ++i) {
                if(i == ress[make_pair(quo, res)]) {
                    decimal.push_back('(');
                }
                decimal.push_back(fraction[i]);
            }
            decimal.push_back(')');
        }

        return decimal;
    }
};
