/*
    A strobogrammatic number is a number that looks the same when rotated 180 degrees (looked at upside down).

    Find all strobogrammatic numbers that are of length = n.

    For example,
    Given n = 2, return ["11","69","88","96"].
*/

class Solution {
public:
    Solution()
    {
        digitToDigit['0'] = '0';
        digitToDigit['1'] = '1';
        digitToDigit['6'] = '9';
        digitToDigit['8'] = '8';
        digitToDigit['9'] = '6';
        
        digits = vector<char>({'0', '1', '8', '6', '9'});
    }
    
    vector<string> findStrobogrammatic(int n) {
        if(n == 0)
            return vector<string> ();
            
        if(n == 1)
            return vector<string>({"0", "1", "8"});
            
        int halfSize = n / 2 + (n % 2);
        vector<string> partResults = getPartNumbersBySize(halfSize);
        
        vector<string> results;
        for(int i = 0; i < partResults.size(); ++i)
        {
            if((partResults[i][partResults[i].size() - 1] == '6' || 
                partResults[i][partResults[i].size() - 1] == '9') &&
                n % 2 == 1)
                continue;

            partResults[i].resize(n);
            for(int l = 0, r = n - 1; l < r; ++l, --r)
                partResults[i][r] = digitToDigit[partResults[i][l]];
                
            results.push_back(partResults[i]);
        }
        
        return results;
    }
    
private:
    vector<string> getPartNumbersBySize(int n)
    {
        vector<string> partNumbers;
        if(n == 1)
        {
            for(int i = 1; i < digits.size(); ++i)
                partNumbers.push_back(string(1, digits[i]));
        }
        else
        {
            for(int i = 0; i < digits.size(); ++i)
            {
                vector<string> partNumbersOfOneLessSize = getPartNumbersBySize(n - 1);
                for(int j = 0; j < partNumbersOfOneLessSize.size(); ++j)
                {
                    string partNumber(partNumbersOfOneLessSize[j]);
                    partNumber.push_back(digits[i]);
                    partNumbers.push_back(partNumber);
                }
            }
        }
        
        return partNumbers;
    }

    unordered_map<char, char> digitToDigit;
    vector<char> digits;
};
