/*
    Given two strings representing two complex numbers.

    You need to return a string representing their multiplication. Note i2 = -1 according to the definition.

    Example 1:
    Input: "1+1i", "1+1i"
    Output: "0+2i"
    Explanation: (1 + i) * (1 + i) = 1 + i2 + 2 * i = 2i, and you need convert it to the form of 0+2i.
    Example 2:
    Input: "1+-1i", "1+-1i"
    Output: "0+-2i"
    Explanation: (1 - i) * (1 - i) = 1 + i2 - 2 * i = -2i, and you need convert it to the form of 0+-2i.
    Note:

    The input strings will not have extra blank.
    The input strings will be given in the form of a+bi, where the integer a and b will both belong to the range of [-100, 100]. 
    And the output should be also in this form.
*/

class Solution {
public:
    string complexNumberMultiply(string a, string b) {
        if(a.empty() || b.empty())
            return "";
            
        pair<int, int> aVector = getTwoNumbers(a);
        pair<int, int> bVector = getTwoNumbers(b);
        pair<int, int> multiplicationVector = calculateMultiplication(aVector, bVector);
        
        string multiplication(to_string(multiplicationVector.first));
        multiplication.push_back('+');
        multiplication.append(to_string(multiplicationVector.second));
        multiplication.push_back('i');
        
        return multiplication;
    }
    
private:
    pair<int, int> getTwoNumbers(const string& numberString)
    {
        int realIndex = 1;
        for(; numberString[realIndex] != '+'; ++realIndex) {}
        int realPart = atoi(numberString.substr(0, realIndex).c_str());
        
        ++realIndex;
        int complexPart = atoi(numberString.substr(realIndex).c_str());
        
        return make_pair(realPart, complexPart);
    }
    
    pair<int, int> calculateMultiplication(const pair<int, int>& l, const pair<int, int>& r)
    {
        return make_pair(l.first * r.first - l.second * r.second, l.first * r.second + l.second * r.first);
    }
};  
