/*
    Given a string representing an expression of fraction addition and subtraction, you need to return the calculation result in string format. The final result should be irreducible fraction. If your final result is an integer, say 2, you need to change it to the format of fraction that has denominator 1. So in this case, 2 should be converted to 2/1.

    Example 1:
    Input:"-1/2+1/2"
    Output: "0/1"
    Example 2:
    Input:"-1/2+1/2+1/3"
    Output: "1/3"
    Example 3:
    Input:"1/3-1/2"
    Output: "-1/6"
    Example 4:
    Input:"5/3+1/3"
    Output: "2/1"
    Note:
    The input string only contains '0' to '9', '/', '+' and '-'. So does the output.
    Each fraction (input and output) has format ±numerator/denominator. If the first input fraction or the output is positive, then '+' will be omitted.
    The input only contains valid irreducible fractions, where the numerator and denominator of each fraction will always be in the range [1,10]. If the denominator is 1, it means this fraction is actually an integer in a fraction format defined above.
    The number of given fractions will be in the range [1,10].
    The numerator and denominator of the final result are guaranteed to be valid and in the range of 32-bit int.
*/

class Solution {
public:
    string fractionAddition(string expression) {
        pair<int, int> frac = make_pair(0, 1);
        for(int l = 0, r = 0; r < expression.size();)
        {
            if(expression[r] == '/')
            {
                for(++r; r < expression.size() && expression[r] >= '0' && expression[r] <= '9'; ++r) {}
                addFrac(frac, expression, l, r - 1);
                l = r++;
            }
            else
                ++r;
        }
        
        string res = to_string(frac.first);
        res.push_back('/');
        res.append(to_string(frac.second));
        return res;
    }
    
private:
    void addFrac(pair<int, int> &frac, const string &s, int l, int r)
    {
        int sign = s[l] == '-' ? -1 : 1;
        if(s[l] == '+' || s[l] == '-')
            ++l;
        
        int index = l;
        for(; index < r && s[index] >= '0' && s[index] <= '9'; ++index) {}
        int upper = atoi(s.substr(l, index).c_str());
        int lower = atoi(s.substr(index + 1, r - index).c_str());
        
        frac.first = frac.first * lower + sign * frac.second * upper;
        frac.second *= lower;
        
        int gcd = getGCD(frac.first, frac.second);
        frac.first /= gcd;
        frac.second /= gcd;
    }
    
    int getGCD(int l, int r)
    {
        l = abs(l);
        r = abs(r);
        
        if(l < r)
            swap(l, r);
        
        return r == 0 ? l : getGCD(r, l % r);
    }
};
